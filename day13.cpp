#include <bits/stdc++.h>
using namespace std;

#define pb push_back;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("input/day13", "r", stdin);

	int n;
	cin >> n;
	set<pair<int,int>> points;
	pair<int,int> xy;
	rep(_,0,n){
		cin >> xy.first >> xy.second;
		points.insert(xy);
	}

	char dir;
	bool first = true;
	while(cin >> dir >> n){
		set<pair<int,int>> points2;
		for (auto p : points){
			int x = p.first;
			int y = p.second;
			if(dir=='x' && p.first > n){
				x = 2*n-x;
			}else if(dir=='y' && p.second > n){
				y = 2*n-y;
			}
			points2.emplace(x,y);
		}
		points = points2;
		if(first){
			cout << sz(points) << "\n";
			first = false;
		}
	}
	vector<vector<char>> part2(6,vector<char>(40, ' '));
	for(auto p : points){
		part2[p.second][p.first] = '#';
	}
	rep(y,0,sz(part2)){
		rep(x,0,sz(part2[y])){
			cout << part2[y][x];
		}
		cout << "\n";
	}
}
