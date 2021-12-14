#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<b;++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef vector<int> vi;


map<pair<char,char>,char> pr;
map<tuple<char,char,int>,vector<ll>> rs;

vector<ll> put(char f, char s, int i){
	auto p = mp(f,s);
	auto t = make_tuple(f,s,i);
	if(rs.count(t)) return rs[t];

	vector<ll> r(26);
	if(pr.count(p)) {
		char m = pr[p];
		++r[m-'A'];
		if(i>0){
			auto a = put(f,m,i-1);
			auto b = put(m,s,i-1);
			rep(j,0,sz(a)) r[j] += a[j] + b[j];
		}
	}
	rs[t] = r;
	return r;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("input/day14", "r", stdin);

	string t;
	cin >> t;

	string s, r;
	while(cin >> s >> r){
		pr[mp(s[0],s[1])] = r[0];
	}
	
	vector<ll> part1(26);
	for(char c : t) ++part1[c-'A'];
	vector<ll> part2 = part1;
	rep(i,0,sz(t)-1){
		auto p1 = put(t[i],t[i+1],9);
		auto p2 = put(t[i],t[i+1],39);
		rep(j,0,sz(p1)) part1[j] += p1[j];
		rep(j,0,sz(p2)) part2[j] += p2[j];
	}
	ll h1=0, h2=0, l1=LLONG_MAX, l2=LLONG_MAX;
	rep(i,0,sz(part1)){
		if(part1[i]==0) continue;
		h1 = max(h1,part1[i]);
		l1 = min(l1,part1[i]);
		h2 = max(h2,part2[i]);
		l2 = min(l2,part2[i]);
	} cout << h1-l1 << "\n" << h2-l2;
}
