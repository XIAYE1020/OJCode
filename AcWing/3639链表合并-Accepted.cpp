#include<iostream>
#include<iterator>
#include<list>
#include<vector>
using namespace std;

int main(){
	list<int> list1;
	list<int> list2;
	list<int> ansList;
	int S1,S2;
	cin>>S1;
	for(int i = 0; i < S1; i++){
		int tempNum;
		cin>>tempNum;
		list1.push_back(tempNum);
	}
	cin>>S2;
	for(int i = 0; i < S2; i++){
		int tempNum;
		cin>>tempNum;
		list2.push_back(tempNum);
	}
	
	auto it1 = list1.begin();
	auto it2 = list2.begin();
	
	while(it1!=list1.end()&&it2!=list2.end()){
		if(*it1>*it2){
			ansList.push_back(*it2);
			it2++;
		}else{
			ansList.push_back(*it1);
			it1++;
		}
	}
	
	if(it1==list1.end()){
		while(it2!=list2.end()){
			ansList.push_back(*it2);
			it2++;
		}
	}
	
	if(it2==list2.end()){
		while(it1!=list1.end()){
			ansList.push_back(*it1);
			it1++;
		}
	}
	
	for(auto it = ansList.begin();it!=ansList.end();it++){
		cout<<*it<<' ';
	}
	
	return 0;
}