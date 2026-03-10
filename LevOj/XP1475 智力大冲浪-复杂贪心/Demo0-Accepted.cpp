#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Game{
	int deadline;
	int penalty;
};

bool pntyCompare(const Game& a, const Game& b){
	return a.penalty > b.penalty;
}

int main(){
	int m,n;
	while(cin>>m>>n){//m is the money initially give to the participants
		vector<Game> gameList(n);
		for(int i = 0; i < n; i++){//input deadline
			cin >> gameList[i].deadline;
		}
		
		for(int i = 0; i < n; i++){//input penalty
			cin >> gameList[i].penalty;
		}
		
		sort(gameList.begin(),gameList.end(),pntyCompare);//sort by the amount of penalty from highest to the lowest
		
		int latestTime = 0;
		for(int i = 0; i < n;i++){
			if(gameList[i].deadline > latestTime){
				latestTime = gameList[i].deadline;
			}
		}
		//cout<<latestTime<<endl;
		vector<bool> timeOccupied(latestTime + 1,false);
		int penaltySum = 0;
		for(int i = 0;i < n;i++){
			int curDeadline = gameList[i].deadline;
			int j;
			for(j = curDeadline; j > 0; j--){
				if(timeOccupied[j]==false){//successfully find its time to finish 
					timeOccupied[j]=true;
					break;
				}
			}
			if(j==0){
				cout<<gameList[i].penalty<<endl;
				penaltySum += gameList[i].penalty;
			}
		}
		cout<<m-penaltySum<<endl;
	}
}


