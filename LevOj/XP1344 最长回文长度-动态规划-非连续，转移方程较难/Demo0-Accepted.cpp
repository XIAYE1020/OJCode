#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	string str;
	while(cin>>str){
		int n = str.size();//n records the lenth of str
		
		if(n == 0){//the str is empty
			cout << '0' << endl;
			continue;
		}
		
		vector<vector<int>> dp(n+1,vector<int>(n+1,0));
		for(int i = 0; i < n; i++){//initiate dp[i][i] = 1, only the No.i charactor itself
			dp[i][i] = 1;
		}

		for(int i = n-1; i >= 0; i--){//start from rear,for the "dp[i][j] = dp[i+1][j-1] + 2" needs the information from rear
			for(int j = i + 1; j < n; j++){
				if(str[i]==str[j]){
					dp[i][j] = dp[i+1][j-1] + 2;
				}else{
					dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
				}
			}
		}
		
		cout << dp[0][n-1] << endl;
	}
	return 0;
}