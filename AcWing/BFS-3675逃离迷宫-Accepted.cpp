#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int m,n,k,x1,y1,x2,y2;
vector<vector<char>> map;
vector<vector<int>> times;
int dX[4] = {1,0,-1,0};
int dY[4] = {0,-1,0,1};

bool isValid(int y, int x){
	if(x>0&&x<=n&&y>0&&y<=m&&map[y][x]!='*'){
		return true;
	}else{
		return false;
	}
}

void bfs(){
	if(x1==x2&&y1==y2&&times[y1][x1]<=k){
		cout<<"yes"<<endl;
		return;
	}
	
	queue<pair<int,int>> que;
	que.push({x1,y1});
	
	while(!que.empty()){
		int curx = que.front().first;
		int cury = que.front().second;
		que.pop();
		
//		if (times[cury][curx] >= k) continue;
		
		for(int i = 0; i<4;i++){
			int tempX = curx + dX[i];
			int tempY = cury + dY[i];
			while(isValid(tempY, tempX)){
				if(times[tempY][tempX]>times[cury][curx]+1){
					times[tempY][tempX]=times[cury][curx]+1;
					que.push({tempX,tempY});
				}
				if(tempX==x2&&tempY==y2&&times[tempY][tempX]<=k){
					cout<<"yes"<<endl;
					return;
				}
				tempX+=dX[i];
				tempY+=dY[i];
			}
		}
		
	}
	cout<<"no"<<endl;
}

int main(){
	int T;
	cin>>T;
	for(int i =0;i<T;i++){
		cin>>m>>n;
		map.assign(m + 1, vector<char>(n + 1));
    	times.assign(m + 1, vector<int>(n + 1, INT_MAX));
		for(int i = 1;i<=m;i++){//input map
			for(int j = 1;j<=n;j++){
				cin>>map[i][j];
			}
		}
		cin>>k>>x1>>y1>>x2>>y2;//input nums
		times[y1][x1]=-1;
		bfs();
	}
	
	return 0;
}