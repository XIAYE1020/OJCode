#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<int> father(1000,-1);
unordered_set<int> nodes;

int FindFather(int num){
	if(father[num]!=num){
		father[num] = FindFather(father[num]);
	}
	return father[num];
}

void Union(int num1,int num2){
	int ftrnum1 = FindFather(num1);
	int ftrnum2 = FindFather(num2);
	if(ftrnum1!=ftrnum2){
		father[ftrnum2] = ftrnum1;
	}
}

int main(){
	int i,j;

	while(cin>>i>>j){
		if(father[i]==-1){
			father[i]=i;
		}
		if(father[j]==-1){
			father[j]=j;
		}
		Union(i,j);
		
		nodes.insert(i);
		nodes.insert(j);
	}
	
	int count=0;
	for(auto it : nodes){
		if(father[it]==it){
			count++;
		}
	}	
	cout<<count<<endl;
	return 0;
}