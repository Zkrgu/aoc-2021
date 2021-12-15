#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<b;++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef vector<int> vi;

int n;

vector<vector<ll>> dijkstra(vector<vector<int>> risks){
	pair<int,int> src = mp(0,0);

	priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;
	vector<vector<ll>> dist(sz(risks), vector<ll>(sz(risks[0]),LONG_MAX));
	dist[0][0] = 0;
	pq.push(mp(0,src));

	while(!pq.empty()){
		pair<ll,pair<int,int>> u = pq.top();
		int x = u.second.first;
		int y = u.second.second;
		ll d = u.first;
		pq.pop();
		if(d<dist[y][x]) continue;

		rep(dy,-1,2) rep(dx,-1,2){
			if((dy==0) == (dx==0)) continue;
			int yy = y+dy;
			int xx = x+dx;
			if(yy >= 0 && yy < sz(risks) && xx >= 0 && xx < sz(risks[0])){
				ll nd = d+risks[yy][xx];
				if(nd < dist[yy][xx]){
					dist[yy][xx] = nd;
					pq.push(mp(nd,mp(xx,yy)));
				}	
			}
		}
	}
	return dist;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("input/day15", "r", stdin);

	string line;
	vector<string> lines;
	while(cin >> line) lines.pb(line);

	int m = sz(lines);
	n = 5*m;

	vector<vi> risks(m,vi(m));
	vector<vi> risks2(n,vi(n));

	rep(i,0,m)rep(j,0,m) risks[i][j] = lines[i][j]-'0';

	rep(i,0,n) rep(j,0,n) {
		int q = risks[i%m][j%m] + i / m + j / m;
		while (q > 9) q -= 9;
		risks2[i][j] = q;
	}

	cout << dijkstra(risks)[m-1][m-1] << " " << dijkstra(risks2)[n-1][n-1];
}
