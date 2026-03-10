#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		for(int i = 0; i < n; i++){
			string Str;
			cin>>Str;
			int len = Str.size();
			int maxLen = 0;
			vector<int> dp(len,1);
			
			
			for(int j = 1; j < len;j++){//find the longgest dp[j]
				for(int k = j-1; k >= 0; k--){
					if(Str[k] < Str[j]){
						dp[j] = max(dp[j],dp[k]+1);
					}
				}
			}
			
			for(int j=0;j<len;j++){
				maxLen = max(maxLen, dp[j]);
			}
			cout << maxLen << endl;
		}
	}
	return 0;
}