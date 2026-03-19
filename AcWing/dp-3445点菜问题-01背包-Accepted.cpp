#include<iostream>
#include<vector>
using namespace std;

int main(){
	int C,N;
	cin>>C>>N;
	vector<pair<int,int>> menu;
	for(int i = 0; i<N; i++){
		int p,v;
		cin>>p>>v;
		menu.push_back({p,v});
	}
	
	vector<vector<int>> dp(N+1,vector<int>(C+1,0));
	int maxprice = 0;
	for(int i = 1; i <= N;i++){
		int price = menu[i-1].first;
		int satis = menu[i-1].second;
		for(int j = C; j>=0; j--){
			if(j<menu[i-1].first){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-price]+satis);
				if(dp[i][j]>maxprice){
					maxprice = dp[i][j];
				}
			}

		}
	}
	cout<<dp[N][C]<<endl;
	return 0;
}