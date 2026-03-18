#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> father;
vector<int> Depth;

typedef struct Edge{
	int begin,end,cost;
}Edge;

bool CmpEdge(const Edge& a,const Edge& b){
	return a.cost<b.cost;
}

int findFather(int i){
	if(father[i]!=i){
		father[i] = findFather(father[i]);
	}
	return father[i];
}

bool UnionEdge(int a,int b){
	int ftrA = findFather(a);
	int ftrB = findFather(b);
	if(ftrA != ftrB){//not in a same tree
		if(Depth[ftrA]>Depth[ftrB]){//insert B to A
			father[ftrB] = ftrA;
		}else if(Depth[ftrA]<Depth[ftrB]){//insert A to B
			father[ftrA] = ftrB;
		}else{
			father[ftrA] = ftrB;
			Depth[ftrB]++;
		}
		return true;//not same tree, and combined successfully
	}
	return false;//same tree
}

int main(){
	int n,m;
	while(cin>>n>>m){
		vector<Edge> Edges;
		Edges.reserve(m);
		for(int i = 0;i < m;i++){
			int b,e,c;
			cin>>b>>e>>c;
			Edges.push_back({b,e,c});
		}
		
		sort(Edges.begin(),Edges.end(),CmpEdge);//sort edges by cost from small to bigger
		
		father.resize(n+1);
		Depth.assign(n+1,0);
		
		for(int i=1;i<=n;i++){//initiate father
			father[i] = i;
		}
		
		int total_cost = 0;
		int edgeCount = 0;
		
		for(const auto& edge: Edges){
			if(UnionEdge(edge.begin,edge.end)){//not in a same tree
				total_cost +=edge.cost;
				edgeCount++;
			}
			
			if(edgeCount==n-1){
				break;
			}
		}
		
		if(edgeCount==n-1){//all nodes are succesfully conneced
			cout<<total_cost<<endl;
		}else{
			cout<<'?'<<endl;
		}
	}
	return 0;
}