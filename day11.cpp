#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef vector<int> vi;

vector<vi> octs;
vector<vector<bool>> flashed;

void adjacent(int x, int y){
	for(int dy=-1;dy<2;++dy) for(int dx=-1;dx<2;++dx){
		if(y+dy >= 0 && y+dy < sz(octs) && x+dx >=0 && x+dx < sz(octs[y])){
			if(flashed[y+dy][x+dx]) continue;
			++octs[y+dy][x+dx];
			if(octs[y+dy][x+dx]>9){
				flashed[y+dy][x+dx] = true;
				octs[y+dy][x+dx] = 0;
				adjacent(x+dx,y+dy);
			}
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("input/day11", "r", stdin);

	string s;
	vector<string> strs;

	while(cin >> s) strs.pb(s);
	octs = vector<vi>(sz(strs),vi(sz(strs[0])));
	rep(y,0,sz(strs)) rep(x,0,sz(strs[y])) octs[y][x] = strs[y][x]-'0';

	int i = 1;
	int c = 0;
	while(true){
		flashed = vector<vector<bool>>(sz(octs),vector<bool>(sz(octs[0])));

		rep(y,0,sz(octs)) rep(x,0,sz(octs[y])){
			if(flashed[y][x]) continue;
			++octs[y][x];
			if(octs[y][x]>9){
				flashed[y][x] = true;
				octs[y][x] = 0;
				adjacent(x,y);
			}
		}
		
		int f=0;
		rep(y,0,sz(octs)){
			rep(x,0,sz(octs[y])){
				f+=flashed[y][x];
			}
		}
		c+=f;
		if(f==sz(flashed)*sz(flashed)) break;
		if(i==100) cout << c << "\n";
		++i;
	}
	cout << i;
}
