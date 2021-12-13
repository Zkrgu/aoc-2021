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
	freopen("input/test10", "r", stdin);

	string s;
	vector<string> strs;
	while(cin >> s) strs.pb(s);

	map<char,int> mp;
	mp[')'] = 3;
	mp[']'] = 57;
	mp['}'] = 1197;
	mp['>'] = 25137;
	
	map<char,int> sm;
	sm['('] = 1;
	sm['['] = 2;
	sm['{'] = 3;
	sm['<'] = 4;

	int cost = 0;
	vi scores;
	for(auto s : strs){
		string st;
		bool con = false;
		for(auto c : s){
			if(c == '(' || c == '[' || c== '{' || c=='<') st.pb(c);
			else if( (c==')' && st.back()=='(') ||
				st.back()==c-2) st.pop_back();
			else {
				cost+=mp[c];
				con = true;
				break;
			}
		}
		if(con) continue;
		int score = 0;
		for(int i=sz(st);i>=0;--i){
			score *= 5;
			score += sm[st[i]];
		}
		scores.pb(score);
	}
	sort(all(scores));
	cout << cost << "\n" << scores[sz(scores)/2];
}
