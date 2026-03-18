#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

int n;

int bfs(string start){
	unordered_map<string, int> dist;
	queue<string> que;
	
	if(start.find("2012")!=string::npos) return 0;
	
	que.push(start);
	dist[start] = 0;
	
	while(!que.empty()){
		string temp = que.front();
		que.pop();
		
		int tempdist = dist[temp];
		
		for(int i = 0;i<n-1;i++){
			string next = temp;
			swap(next[i],next[i+1]);
			
			if(dist.find(next)==dist.end()){
				dist[next]=tempdist+1;
				que.push(next);
				if(next.find("2012")!=string::npos){
					return dist[next];
				}
			}
			
		}
	}
	return -1;
}

int main(){
	string Code;
	cin>>n>>Code;
	
	cout<<bfs(Code)<<endl;
	
	return 0;
}