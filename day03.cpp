#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input/day03", "r", stdin);

	vector<string> input;
	string s;
	while (cin >> s) input.push_back(s);

	vector<vector<string>> arr = { input, input };

	int n = input[0].size();
	int gamma = 0;
	for(int i=0;i<n;i++){
		int ones=0, zeroes=0;
		for(auto s : input){
			s[i] == '0' ? ++zeroes : ++ones;
		}
		gamma=gamma<<1;
		gamma |= zeroes>ones ? 0 : 1;
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<2;j++) {

			int zeroes = 0, ones = 0;
			for(auto s : arr[j]) s[i] == '0'? ++zeroes : ++ones;

			vector<string> narr;
			char keep;
			if(j == 1){
				keep = ones >= zeroes ? '1' : '0';
			}else{
				keep = zeroes <= ones ? '0' : '1';
			}
			for(auto s : arr[j]) {
				if (s[i] == keep) narr.push_back(s);
			}
			arr[j] = narr;
		}
	}
	cout << gamma*(gamma^4095) << "\n" << stoi(arr[0][0],0,2)*stoi(arr[1][0],0,2);
}