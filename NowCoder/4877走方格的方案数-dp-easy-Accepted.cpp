#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> map(n+1,vector<int>(m+1));
	for(int i = 0;i<=n;i++){
		for(int j = 0;j<=m;j++){
			if(i==0||j==0){
				map[i][j]=1;
				continue;
			}
			map[i][j] = map[i-1][j]+map[i][j-1];
		}
	}
	cout<<map[n][m]<<endl;
	return 0;
}