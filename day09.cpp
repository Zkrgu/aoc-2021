#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef vector<int> vi;


vector<vi> f;
vector<vi> b;

void dfs(int x, int y, int n){
	if(f[y][x]==9 || b[y][x] != -1) return;
	b[y][x] = n;
	if(x+1<sz(f[y])) dfs(x+1,y,n);
	if(x>0) dfs(x-1,y,n);
	if(y>0) dfs(x,y-1,n);
	if(y+1<sz(f[y])) dfs(x,y+1,n);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("input/day09", "r", stdin);

	vector<string> in;
	string s;
	while(cin >> s) in.pb(s);
	
	f=vector<vi>(sz(in), vi(sz(in[0])));
	b=vector<vi>(sz(in), vi(sz(in[0]),-1));
	rep(y,0,sz(in)) rep(x,0,sz(in[y])) f[y][x] = in[y][x] - '0';
	
	int ac = 0, c=0;
	rep(y,0,sz(f)) rep(x,0,sz(f[y])){
		int ic = 0, lt=0;
		if(y>0){
			++ic;
			if(f[y][x]<f[y-1][x]) ++lt;
		}
		if(y<sz(f)-1){
			++ic;
			if(f[y][x]<f[y+1][x]) ++lt;
		}
		if(x>0){
			++ic;
			if(f[y][x]<f[y][x-1]) ++lt;
		}
		if(x<sz(f[y])-1){
			++ic;
			if(f[y][x]<f[y][x+1]) ++lt;
		}
		if(lt==ic) {
			dfs(x,y,c);
			ac+=f[y][x]+1;
			++c;
		}
	}
	cout << ac << "\n";
	vi bs(c,0);
	rep(y,0,sz(b)) rep(x,0,sz(b[y])) if(b[y][x]!=-1) ++bs[b[y][x]];
	sort(all(bs));
	cout << bs[c-1] * bs[c-2] * bs[c-3];
}
