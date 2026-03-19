#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	string a,b;
	cin>>a>>b;
	int lena = a.size();
	int lenb = b.size();
	
	vector<vector<int>> dp(lena+1,vector<int>(lenb+1,0));
	int max = 0;
	
	for(int i = 0; i < lena; i++){
		for(int j = 0; j < lenb; j++){
			if(a[i]==b[j]){
				dp[i+1][j+1] = dp[i][j]+1;
				if(dp[i+1][j+1]>max){
					max = dp[i+1][j+1];
				}
			}else{
				dp[i+1][j+1] = 0;
			}
		}
	}
	
	for(int i = 0; i <= lena; i++){
		for(int j = 0; j <= lenb; j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<endl;
	}
	
	cout<<max<<endl;
	return 0;
}