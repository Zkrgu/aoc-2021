#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("input/day01", "r", stdin);

	int x, part1 = 0, part2 = 0;
	vector<int> input;
	while(cin >> x) input.push_back(x);

	for(vector<int>::iterator it = input.begin(); it != input.end(); ++it){
		if(*it>*(it-1)) ++part1;
		if(it<input.end()-1&&*it>*(it-3)) ++part2;
	}

	cout << part1 << "\n" << part2;
}
