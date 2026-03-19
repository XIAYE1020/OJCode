#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> floor(n+1,0);
	floor[1] = 1;
	floor[2] = 2;
	for(int i=3;i<=n;i++){
		floor[i] = (floor[i-1]+floor[i-2])%999983;
	}
	cout<<floor[n]<<endl;
	return 0;
}