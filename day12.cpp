#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef vector<int> vi;

map<string, set<string>> adj;

int findPaths(string node, map<string,bool> &used, string d, int* part1){
	if(islower(node[0])){
		if(used[node]){
			if(node=="start"||d!="") return 0;
			d=node;
		}else if(node=="end"){
			if(d=="") {
				++*part1;
			}
			return 1;
		}
		else used[node] = true;
	}
	int paths = 0;
	for(string n : adj[node]){
		paths += findPaths(n,used,d,part1);
	}
	if(islower(node[0])){
		if(d==node) d="";
		else used[node] = false;
	}
	return paths;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("input/day12", "r", stdin);

	string f,t;
	while(cin>>f>>t){
		adj[f].insert(t);
		adj[t].insert(f);
	}

	map<string,bool> used;
	int part1 = 0;
	int part2 = findPaths("start", used, "", &part1);
	cout << part1 << "\n" << part2;
}
