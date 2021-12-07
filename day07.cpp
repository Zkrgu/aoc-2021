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
	freopen("input/day07", "r", stdin);

	vi subs;

	int x;
	while(cin >> x) subs.pb(x);
	auto maxe = max_element(all(subs));
	int maxv = *maxe;

	int best[2];
	best[0] = maxv*sz(subs);
	best[1] = maxv*sz(subs)*sz(subs);

	rep(i,0,maxv){
		int totalDistance = 0;
		int fuel = 0;
		rep(j,0,sz(subs)){
			int distance = abs(i-subs[j]);
			totalDistance += distance;
			fuel+= (distance*(distance+1))/2;
		}
		if(totalDistance<best[0]) best[0]=totalDistance;
		if(fuel<best[1]) best[1]=fuel;
	}
	cout << best[0] << "\n" << best[1];
}
