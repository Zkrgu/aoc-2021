#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("input/day08", "r", stdin);

	map<int,int> num;
	num[42] = 0;
	num[17] = 1;
	num[34] = 2;
	num[39] = 3;
	num[30] = 4;
	num[37] = 5;
	num[41] = 6;
	num[25] = 7;
	num[49] = 8;
	num[45] = 9;

	ll count = 0;
	string s;
	while(cin >> s){
		vector<string> l,r;
		l.pb(s);
		rep(_,0,9){
			cin >> s;
			l.pb(s);
		}
		cin >> s;
		rep(_,0,4){
			cin >> s;
			r.pb(s);
		}
		map<char, int> chars;
		for(string s : l){
			for(char c : s) ++chars[c];
		}
		int o=0;
		rep(i,0,sz(r)){
			int j=0;
			for(char c : r[i]) j += chars[c];
			o += ((int)pow(10,sz(r)-1-i)+0.1)*num[j];
		}
		count+=o;
	}
	cout << count;
}