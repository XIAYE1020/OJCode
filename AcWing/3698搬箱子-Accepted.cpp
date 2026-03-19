#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> BoxList(n);
	for(int i = 0; i < n; i++){
		cin>>BoxList[i];
	}
	
	vector<int> dp(n,1);
	int MaxLen = 1;
	
	for(int i = 1;i < n;i++){
		int heighti = BoxList[i];
		for(int j = i-1;j>=0;j--){
			int heightj = BoxList[j];
			
			if(heighti>heightj&&dp[i]<dp[j]+1){
				dp[i] = dp[j]+1;
				if(dp[i]>MaxLen){
					MaxLen = dp[i];
				}
			}else continue;
		}
	}
	cout<<MaxLen<<endl;
	return 0;
}