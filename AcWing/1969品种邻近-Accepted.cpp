#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
	int N,K;
	cin>>N>>K;
	vector<int> cowList;
	unordered_map<int, int> lastPos;
	int maxCrowdID = -1;
	for(int i = 0; i < N;i++){
		int tempCowID;
		cin>>tempCowID;
		cowList.push_back(tempCowID);
		if(lastPos.count(tempCowID)){
			int dis = i-lastPos[tempCowID];
			if(dis<=K){
				maxCrowdID = max(maxCrowdID, tempCowID);
			}
		}
		lastPos[tempCowID] = i; 
	}
	
	cout<<maxCrowdID<<endl;
	return 0;
}