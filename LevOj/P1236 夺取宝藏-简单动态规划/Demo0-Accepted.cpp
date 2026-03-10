#include<iostream>
#include<vector>
using namespace std;

int main(){
	int m,n;
	while(cin>>m>>n){
		vector<vector<int>> map(m,vector<int>(n,0));//initiate the map
		vector<vector<int>> dp(m,vector<int>(n,0));//initiate the dp map
		
		for(int i = 0;i<m;i++){//input the price of treasures
			for(int j = 0;j<n;j++){
				cin>>map[i][j];
			}
		}
		
		for(int i = 0;i<m;i++){//form the dp map
			for(int j = 0;j<n;j++){
				if(i == 0&&j==0){//the [0][0]
					continue;
				}else if(i==0){
					dp[i][j] = dp[i][j-1]+map[i][j];
				}else if(j==0){
					dp[i][j] = dp[i-1][j]+map[i][j];
				}else{
					dp[i][j] = max(dp[i-1][j]+map[i][j],dp[i][j-1]+map[i][j]);
				}
			}
		}
		
		cout<<dp[m-1][n-1];
	}
	return 0;
}