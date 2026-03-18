#include<iostream>
#include<vector>
using namespace std;
vector<int> father;

int FindFather(int son){
	if(father[son]!=son){
		return FindFather(father[son]);
	}else{
		return son;
	}
}

void UnionSE(int A,int B){
	int ftrA = FindFather(A);
	int ftrB = FindFather(B);
	if(ftrA!=ftrB){
		father[ftrA] = ftrB;
	}
}

int main(){
	int n,m;
	while(cin>>n>>m){
	father.resize(n+1);
		for(int i=1;i<=n;i++){
			father[i]=i;
		}
		
		for(int i = 0; i < m; i++){
			int start,end;
			cin>>start>>end;
			UnionSE(start,end);
		}
		
		int pubF = FindFather(1);
		int i;
		for(i = 2; i<=n;i++){
			if(FindFather(i)!=pubF){
				cout<<"NO"<<endl;
				break;
			}
		}
		if(i==n+1){
			cout<<"YES"<<endl;
		}

	}
	return 0;
}