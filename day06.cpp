#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("input/day06", "r", stdin);

	int x;
	vector<long long> s(9);
	while(cin >> x) ++s[x];

	for(int i=0;i<256;++i){
		vector<long long> s2(9);
		for(int i=1;i<=8;++i) s2[i-1] = s[i];
		s2[6] += s[0];
		s2[8] = s[0];
		s = s2;
		if(i==79){
			int sum=0;
			for(long long x : s) sum += x;
			cout << sum << "\n";
		}
	}
	long long sum = 0;
	for(long long x : s) sum += x;
	cout << sum;
}
