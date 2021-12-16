#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<b;++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef vector<int> vi;

ll parseInt(string &b, int from, int length){
	ll c=0;
	rep(i,from,from+length){
		c <<= 1;
		c += b[i]-'0';
	}
	return c;
}

pair<pair<ll,int>,int> parsePacket(string &b, int bitp){
	int v = parseInt(b,bitp,3);
	if(v<0) cout << bitp;
	bitp+=3;
	int t = parseInt(b,bitp,3);
	bitp+=3;
	
	ll value = 0;
	vector<ll> values;

	if(t==4){
		while(true){
			value <<= 4;
			value += parseInt(b,bitp+1,4);
			if(b[bitp]=='0') break;
			bitp += 5;
		}
		bitp += 5;
	}else{
		int len;
		if(b[bitp]=='0'){
			++bitp;
			len = parseInt(b,bitp,15);
			bitp += 15;
			int bl = bitp+len;
			while(bitp<bl){
				auto packet = parsePacket(b,bitp);
				v += packet.first.second;
				values.pb(packet.first.first);
				bitp = packet.second;
			}
		}else if(b[bitp]=='1'){
			++bitp;
			len = parseInt(b,bitp,11);
			bitp += 11;
			rep(i,0,len){
				auto packet = parsePacket(b,bitp);
				v += packet.first.second;
				values.pb(packet.first.first);
				bitp = packet.second;
			}
		}
		switch(t){
			case 0:
				for(ll v : values) value+=v;
				break;
			case 1:
				value = 1;
				for(ll v : values) value*=v;
				break;
			case 2:
				value = values[0];
				for(ll v : values) value = min(value,v);
				break;
			case 3:
				value = values[0];
				for(ll v : values) value = max(value,v);
				break;
			case 5:
				value = values[0] > values[1];
				break;
			case 6:
				value = values[0] < values[1];
				break;
			case 7:
				value = values[0] == values[1];
				break;
		}
	}
	return mp(mp(value,v),bitp);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("input/day16", "r", stdin);

	map<char,string> rp;

	rp['0'] = "0000";
	rp['1'] = "0001";
	rp['2'] = "0010";
	rp['3'] = "0011";
	rp['4'] = "0100";
	rp['5'] = "0101";
	rp['6'] = "0110";
	rp['7'] = "0111";
	rp['8'] = "1000";
	rp['9'] = "1001";
	rp['A'] = "1010";
	rp['B'] = "1011";
	rp['C'] = "1100";
	rp['D'] = "1101";
	rp['E'] = "1110";
	rp['F'] = "1111";

	string s;
	string b;
	cin >> s;
	for(char c : s) b += rp[c];

	auto vt = parsePacket(b,0);
	cout << vt.first.second << "\n" << vt.first.first;
}
