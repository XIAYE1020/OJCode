#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> cptBiTree(n+1);
	for(int i = 1; i<=n;i++){
		cin>>cptBiTree[i];
	}
	int k;
	cin>>k;
	int layerNum = 1;
	int NodeCount = 0;//the begin node of the No.k layer
	for(int i =1;i<k;i++){
		NodeCount+=layerNum;
		layerNum *=2;
	}
	
	if(NodeCount>=n){
		cout<<"EMPTY";
	}else {
		if(n-NodeCount < layerNum){
			for(int i = 0; i < n-NodeCount; i++){
				cout<<cptBiTree[i+NodeCount+1]<<' ';
			}
		}else{
			for(int i = 0; i < layerNum; i++){
				cout<<cptBiTree[i+NodeCount+1]<<' ';
			}
		}

	}
	cout<<endl;
	return 0;
}