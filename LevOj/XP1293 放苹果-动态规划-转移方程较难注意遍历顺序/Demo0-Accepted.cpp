#include<iostream>
#include<vector>
using namespace std;

int main(){
	int m,n;
	while(cin>>m>>n){
		vector<vector<int>> dp(m+1,vector<int>(n+1,0));//initiate the dp array m*n
		for(int i = 0;i<=m;i++){//i apples -> 0 plate 
			dp[i][0]=0;//0 way
		}
		for(int j = 0;j<=n;j++){//0 apple-> j plates
			dp[0][j]=1;//1 way
		}
		
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(j>i){//numbers of plate > numbers of apples
					dp[i][j] = dp[i][i];//ways equal to the [i][i] 
				}else{
					dp[i][j] = dp[i][j-1] + dp[i-j][j];//left an empty plate / place an apple in each plate 
				}
			}
		}
		cout<<dp[m][n]<<endl;
	}
}