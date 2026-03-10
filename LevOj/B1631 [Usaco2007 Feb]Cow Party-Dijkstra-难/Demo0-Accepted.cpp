#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;//Infinity

struct Edge{
	int to;
	int weight;
};

vector<int> Dijkstra(int start, int n, const vector<vector<Edge>>& adj) {
    // dist 数组初始化：所有距离设为无穷大
    vector<int> dist(n + 1, INF);
    
    // 优先队列，存储 pair<当前距离, 节点编号>
    // greater<pair<int, int>> 确保这是个小顶堆（距离小的排在前面）
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 起点到自己的距离为 0
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        // 取出当前距离最小的节点
        int d = pq.top().first;   // 当前记录的距离
        int u = pq.top().second;  // 节点编号
        pq.pop();

        // 【重要优化】如果取出的距离比已经记录的最短距离还大，说明这个状态过时了，直接跳过
        if (d > dist[u]) continue;

        // 遍历当前节点 u 的所有邻居
        for (const auto& edge : adj[u]) {
            int v = edge.to;       // 邻居节点
            int w = edge.weight;   // 边权

            // 松弛操作：如果通过 u 到达 v 的距离更短，则更新
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                // 将新的最短距离和节点加入优先队列
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main(){
	int N, M, X;
	while(cin>>N>>M>>X){//N:number of cows; M:number of roads; X:farm to hold the party
		vector<vector<Edge>> graph(N + 1);
		vector<vector<Edge>> rev_graph(N + 1);
		
		for(int i = 0;i < M; i++){
			int s, e, w;
			cin >> s >> e >> w;
			graph[s].push_back({e,w});
			rev_graph[e].push_back({s,w});
		}
		
		vector<int> dist_return = Dijkstra(X,N,graph);
		vector<int> dist_go = Dijkstra(X,N,rev_graph);
		
		int max_len = 0;
		for(int i = 1; i <= N;i++){
			if(dist_return[i] != INF && dist_go[i] != INF){
				if(dist_return[i] + dist_go[i] > max_len){
					max_len = dist_return[i] + dist_go[i];
				}
			}
		}
		cout << max_len << endl;
	}
	return 0;
}