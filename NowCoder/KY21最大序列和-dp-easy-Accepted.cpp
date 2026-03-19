#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N;
	while(cin>>N){
		vector<int> S(N);
		vector<long long> dp(N);
		
		for(int i = 0; i < N; i++){
			cin>>S[i];
		}
		
		dp[0] = S[0];
		long long MaxSum = dp[0];
		
		for(int i = 1; i<N;i++){
			if(dp[i-1]<0){
				dp[i]=S[i];
			}else{
				dp[i] = dp[i-1]+S[i];
			}
			
			if(dp[i]>MaxSum){
				MaxSum = dp[i];
			}
		}
		
		cout<<MaxSum<<endl;
	}
	return 0;
}