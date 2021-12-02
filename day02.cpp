#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input/day02", "r", stdin);

	int x;
	string ins;
	int parts[3] = {0, 0, 0};

	while(cin >> ins >> x){
		if(ins[0] == 'd'){
			parts[1] += x;
		}
		else if(ins[0] == 'u'){
			parts[1] -= x;
		}
		else{
			parts[0] += x;
			parts[2] += x*parts[1];
		}
	}
	cout << parts[0]*parts[1] << "\n" << parts[0]*parts[2];
}
