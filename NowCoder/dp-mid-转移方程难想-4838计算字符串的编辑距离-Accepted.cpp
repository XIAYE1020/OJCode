#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	string s,t;
	cin>>s>>t;
	int lens = s.size();
	int lent = t.size();
	
	vector<vector<int>> dp(lens+1,vector<int>(lent+1,0));
	
	
	for(int i = 0;i<=lens;i++){
		dp[i][0]=i;//s->t del i times
	}
	for(int j = 0;j<=lent;j++){
		dp[0][j]=j;//s->t add j times
	}
	
	for(int i = 1;i<=lens;i++){
		for(int j = 1;j<=lent;j++){
			if(s[i-1]==t[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}else{
				//s->t dp[x][y] means x->y needs dp[x][y] times
				//add s dp[i][j-1]
				//del s dp[i-1][j]
				//rep s dp[i-1][j-1]
				dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]})+1;
			}
		}
	}
	cout<<dp[lens][lent];
	return 0;
}