#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	string s1,s2;
	int n,m;

	cin>>n>>m;
	
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	
	cin>>s1;
	cin>>s2;
	
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m;j++){
			if(s1[i]==s2[j]){
				dp[i+1][j+1] = dp[i][j] + 1;
			}else{
				dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
			}
		}
	}
	
//	for(int i = 0; i <= n; i++){
//		for(int j = 0; j <= m;j++){
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	
	cout<<dp[n][m]<<endl;
	return 0;
}