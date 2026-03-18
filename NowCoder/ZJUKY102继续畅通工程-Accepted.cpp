#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> father;

typedef struct road{
	int u;
	int v;
	int cost;
	int state;//1 means is built,0 means hasn't built
}road;

int FindFather(int i){
	if(father[i]!=i){
		return FindFather(father[i]);
	}
	return father[i];
}

void Union(int a,int b){
	int ftrA = FindFather(a);
	int ftrB = FindFather(b);
	if(ftrA!=ftrB){
		father[ftrA] = ftrB;
	}
}

bool myCompare(const road& a, const road& b){
	return a.cost<b.cost;
}

int main(){
	int N;//the number of the villeges
	while(cin>>N){
		if(N==0){
			break;
		}
		vector<road> roads(N*(N-1)/2);
		father.assign(N+1,0);
		
		for(int i = 1;i <= N; i++){//initiate father disjoint-set
			father[i] = i;
		}
		
		for(int i = 0;i<N*(N-1)/2;i++){//input data
			cin>>roads[i].u>>roads[i].v>>roads[i].cost>>roads[i].state;
			if(roads[i].state==1){//Union the village connected
				Union(roads[i].u,roads[i].v);
			}
		}
		
		sort(roads.begin(),roads.end(),myCompare);//sort the roads by cost from cheap to expensive
		
		int totalcost = 0;
		
		for(int i = 0;i<N*(N-1)/2;i++){
			if(roads[i].state==1||FindFather(roads[i].u)==FindFather(roads[i].v)){
				continue;
			}else{
				totalcost+=roads[i].cost;
				roads[i].state = 1;
				Union(roads[i].u,roads[i].v);
			}
		}
		
		cout<<totalcost<<endl;
	}
	return 0;
}