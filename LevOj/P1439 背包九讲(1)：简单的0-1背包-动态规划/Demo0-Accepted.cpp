#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Good{
	int volumn;
	int price;
};

bool myCompare(const Good& a, const Good& b){
	return a.volumn < b.volumn;
}

int main(){
	int V,n;
	while(cin>>V>>n){
		vector<Good> Goods(n);
		vector<int> dp(V);
		int ans = 0;
		for(int i = 0; i < n;i++){
			cin>>Goods[i].volumn>>Goods[i].price;
			
			for(int j = V; j >= Goods[i].volumn; j--){
				dp[j] = max(dp[j], dp[j-Goods[i].volumn]+Goods[i].price);
			}
		}
		
		for(int i = 1; i <= V;i++){
			ans = max(ans,dp[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}