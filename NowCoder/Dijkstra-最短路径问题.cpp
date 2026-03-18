#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

typedef struct Edge{
	int b;//to
	int d;//length
	int p;//cost
}Edge;

struct Node{
	int u,d,p;
	bool operator>(const Node& other) const {
		if(d!=other.d)return d > other.d;
		return p>other.p;
	}
};

int main(){
	int n,m,s,t;
	while(cin>>n>>m){
		if(n==0||m==0){
			return 0;
		}
		vector<vector<Edge>> Edges(n+1);
		
		for(int i = 0; i < m; i++){
			int a,b,d,p;
			cin>>a>>b>>d>>p;
			Edges[a].push_back({b,d,p});
			Edges[b].push_back({a,d,p});
		}
		
		cin>>s>>t;
		
		if(s==t){//initially finished
			cout<<0<<' '<<0<<endl;
			return 0;
		}
		
		priority_queue<Node,vector<Node>,greater<Node>> pq;//pair<length,to>
		vector<int> min_dist(n+1,INT_MAX);
		vector<int> min_cost(n+1,INT_MAX);
		
		min_dist[s] = 0;
		min_cost[s] = 0;
		pq.push({s,0,0});
		
		while(!pq.empty()){
			Node current = pq.top();
			pq.pop();
			
			int u = current.u;
			if(current.d>min_dist[u]) continue;
			
			for(auto it : Edges[u]){
				int v = it.b;
				if(min_dist[u]+it.d<min_dist[v]){
					min_dist[v] = min_dist[u]+it.d;
					min_cost[v] = min_cost[u]+it.p;
					pq.push({v,min_dist[v],min_cost[v]});
				}else if(min_dist[u]+it.d==min_dist[v]){
					if(min_cost[u]+it.p<min_cost[v]){
						min_cost[v]=min_cost[u]+it.p;
						pq.push({v,min_dist[v],min_cost[v]});
					}
				}
			}
		}
		cout<<min_dist[t]<<' '<<min_cost[t]<<endl;
	}
	return 0;
}