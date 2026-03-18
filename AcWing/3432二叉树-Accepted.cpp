#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
	int x,y;
	cin>>x>>y;
	unordered_set<int> hashset;
	int parent = x;
	
	if(x==1){
		cout<<1<<endl;
		return 0;
	}
	
	do{
		hashset.insert(parent);
		parent = parent/2;
	}while(parent!=0);
	
//	for(auto it : hashset){
//		cout<<it<<endl;
//	}
	
	parent = y;
	if(y==1){
		cout<<1<<endl;
		return 0;
	}
	
	do{
		if(hashset.find(parent)!=hashset.end()){//have same ancient
			cout<<parent<<endl;
			return 0;
		}
		parent = parent/2;
	}while(parent!=0);
	return 0;
}