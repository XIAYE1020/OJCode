#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> stairs(n+1);
	stairs[0]=1;
	stairs[1]=1;
	for(int i= 2; i <= n; i++){
		stairs[i] = stairs[i-1]+stairs[i-2];
	}
	cout<<stairs[n]<<endl;
	return 0;
}