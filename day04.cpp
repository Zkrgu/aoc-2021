#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("input/day04", "r", stdin);

	int n,x;
	vector<int> nums;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> x;
		nums.push_back(x);
	}

	int besti[2] = {n,0};
	int bestn[2] = {0,0};

	int board[5][5];
	while(cin >> board[0][0]){
		for(int i=0;i<5;i++) for(int j=0;j<5;j++)
			if(i+j!=0) cin >> board[i][j];

		for(int i=0;i<n;i++){
			int cur = nums[i];
			for(int i=0;i<5;i++) for(int j=0;j<5;j++)
				if(board[i][j]==cur) board[i][j] = 0;
			bool done = false;
			for(int i=0;i<5;i++){
				int sum = 0;
				for(int j=0;j<5;j++) if(board[i][j]==0) ++sum;
				if(sum==5) done=true;
				sum = 0;
				for(int j=0;j<5;j++) if(board[j][i]==0) ++sum;
				if(sum==5) done=true;
			}
			if(done){
				if(i<besti[0]){
					besti[0] = i;
					int sum = 0;
					for(int i=0;i<5;i++) for(int j=0;j<5;j++) sum+=board[i][j];
					bestn[0] = sum*cur;
				}
				if(i>besti[1]){
					besti[1] = i;
					int sum = 0;
					for(int i=0;i<5;i++) for(int j=0;j<5;j++) sum+=board[i][j];
					bestn[1] = sum*cur;
				}
				break;
			}
		}
	}
	cout << bestn[0] << "\n" << bestn[1];
}
