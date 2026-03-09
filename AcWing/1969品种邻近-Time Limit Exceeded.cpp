#include<iostream>
#include<list>
using namespace std;

int main(){
	int N,K;
	cin>>N>>K;
	list<int> cowList;
	int maxCrowdID = -1;
	for(int i = 0; i<N;i++){
		int tempCowID;
		cin >> tempCowID;
		cowList.push_back(tempCowID);
	}
	
	for(auto it = cowList.begin();it!=cowList.end();it++){
		if(*it<maxCrowdID){
			continue;
		}else{
			auto tempIt = it;
			for(int n = 0;n<K;n++){
				tempIt++;
				if(tempIt==cowList.end()){
					break;
				}
				if(*tempIt==*it){
					maxCrowdID = *it;
				}
			}
		}
	}
	
	cout<<maxCrowdID<<endl;
	return 0;
}