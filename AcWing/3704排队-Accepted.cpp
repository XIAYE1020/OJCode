#include<iostream>
#include<vector>
using namespace std;

int main(){
	int N,M;
	cin>>N>>M;
	
	vector<vector<int>> Request(N+1);
	vector<int> InDegree(N+1,0);//record the in-degree of each kid
	
	for(int i = 0;i<M;i++){
		int a, b;
		cin>>a>>b;
		Request[a].push_back(b);
		InDegree[b]++;
	}
	
	int count=0;
	
	while(count!=N){
		for(int i = 1;i<=N;i++){
			if(InDegree[i]!=0){
				continue;
			}else if(InDegree[i]==0){
				cout<<i<<' ';
				InDegree[i] = -1;//-1 record the No.i kid has been arranged
				for(auto it : Request[i]){
					InDegree[it]--;
				}
				count++;
				break;				
			}
		}
	}
	return 0;
}