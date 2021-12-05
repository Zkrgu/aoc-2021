#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("input/day05", "r", stdin);

	vector<vector<int>> field1(1000,vector<int>(1000));
	vector<vector<int>> field2(1000,vector<int>(1000));

	int x1,x2,y1,y2;
	while(cin >> x1){
		cin >> y1 >> x2 >> y2;
		if(x1==x2){
			if(y1>y2) swap(y1,y2);
			for(int y=y1;y<=y2;++y) ++field1[y][x1];
		}else if(y1==y2){
			if(x1>x2) swap(x1,x2);
			for(int x=x1;x<=x2;++x) ++field1[y1][x];
		}else {
			if(x1>x2){
				swap(x1,x2);
				swap(y1,y2);
			}
			int dy = y1>y2?-1:1;
			int y = y1;
			for(int x=x1;x<=x2;++x){
				++field2[y][x];
				y+=dy;
			}
		}
	}
	int sum[2] = {0, 0};
	for(int y=0;y<1000;y++) for(int x=0;x<1000;x++){
		if(field1[y][x]>=2)	++sum[0];
		else if(field1[y][x]+field2[y][x]>=2) ++sum[1];
	}
	cout << sum[0] << "\n" << sum[0]+sum[1];
}
