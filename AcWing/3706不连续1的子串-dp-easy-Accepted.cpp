#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<vector<int>> dp(N+1,vector<int>(2));
	dp[1][0] = 1;
	dp[1][1] = 1;
	for(int j =2;j<=N;j++){
		dp[j][0] = dp[j-1][0]+dp[j-1][1];
		dp[j][1] = dp[j-1][0];
	}
	cout<<dp[N][1]+dp[N][0]<<endl;
	return 0;
}