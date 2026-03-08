#include<iostream>
#include<vector>
using namespace std;
int x[4] = {0,0,-1,1};
int y[4] = {-1,1,0,0};

int maxLength(int i, int j, const int R,const int C,vector<vector<int>> mountain){
	for(int k=0;k<4;k++){
		int tempX = i+x[k];
		int tempY = i+y[k];
		if(tempX>=0&&tempX<=R-1&&tempY>=0&&tempY<=C-1&&mountain[tempX][tempY]<mountain[i][j]){
			return maxLength(tempX,tempY,R,C,mountain)+1;
		}else{
			return 0;
		}
	}
	return 0;
}

int main(){
	int R,C;
	while(cin>>R>>C){
		vector<vector<int>> mountain(R,vector<int>(C));
		for(int i = 0;i < R;i++){
			for(int j = 0;j < C; j++){
				cin>>mountain[i][j];
			}
		}
		int ans = 0;
		for(int i = 0;i < R; i++){
			for(int j = 0;j < C;j++){
				ans = max(ans,maxLength(i,j,R,C,mountain));
			}
		}
		cout<<ans+1<<endl;
	}
	return 0;
}