#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		vector<int> aList(n);
		vector<vector<int>> dp(n,vector<int>(n,0));
		int maxSum = -6e8;
		for(int i = 0; i < n; i++){
			cin >> aList[i];
		}
		for(int i = 0; i < n; i++){
			for(int j = i; j < n; j++){
				if(i == j){
					dp[i][j] = aList[i];
					maxSum = max(dp[i][j],maxSum);
				}else{
					dp[i][j] = dp[i][j-1] + aList[j];
					maxSum = max(dp[i][j],maxSum);
				}
			}
		}
		cout << maxSum << endl;
	}
	return 0;
}