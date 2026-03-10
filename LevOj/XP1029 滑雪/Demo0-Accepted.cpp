#include<iostream>
#include<vector>
using namespace std;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int R,C;

bool isLegal(int x,int y){
	if(x>=0&&x<R&&y>=0&&y<C){
		return true;
	}else{
		return false;
	}
}

int dfs(int x, int y, const vector<vector<int>>& mountain, vector<vector<int>>& path){
	if(path[x][y] != 0){
		//cout<<path[x][y]<<endl;
		return path[x][y];
	}
	int tempX,tempY,maxLen = 1;
	for(int i = 0;i < 4;i++){
		tempX = x + dx[i];
		tempY = y + dy[i];
		if(isLegal(tempX,tempY)&&mountain[x][y]>mountain[tempX][tempY]){//legal direction and is lower than temp position 
			int len = dfs(tempX, tempY, mountain, path) + 1;
			maxLen = max(len,maxLen);
		}
	}
	path[x][y] = maxLen;
	return maxLen;
}

int main(){
	while(cin>>R>>C){
		vector<vector<int>> mountain(R,vector<int>(C));
		vector<vector<int>> path(R, vector<int>(C,0));//default length 0
		for(int i = 0;i < R;i++){
			for(int j = 0;j < C; j++){
				cin>>mountain[i][j];
			}
		}
		int ans = 0;
		for(int i = 0;i < R;i++){
			for(int j = 0;j < C; j++){
				dfs(i,j,mountain,path);
			}
		}
		
		for(int i = 0;i < R;i++){
			for(int j = 0;j < C; j++){
				if(path[i][j]>ans){
					ans = path[i][j];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}