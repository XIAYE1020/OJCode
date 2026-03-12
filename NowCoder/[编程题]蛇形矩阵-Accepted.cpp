#include<iostream>
#include<vector>
using namespace std;

vector<int> D_X={0,1,0,-1};//right-down-left-up
vector<int> D_Y={1,0,-1,0};

int main(){
	int N;
	cin>>N;
	vector<vector<int>> SnakeMatrix(N,vector<int>(N,0));//N*N 
	int dic = 0;//go right at the beginning
	int X=0,Y=0;
	SnakeMatrix[0][0]=1;
	for(int i = 2;i<=N*N;i++){
		int tempX,tempY;
		tempX = X + D_X[dic];
		tempY = Y + D_Y[dic];
		if(tempX<0||tempX>N-1||tempY<0||tempY>N-1||SnakeMatrix[tempX][tempY]!=0){//not a ideal position
			dic++;
			if(dic>=4){
				dic=dic-4;
			}
			tempX = X + D_X[dic];
			tempY = Y + D_Y[dic];
		}
		SnakeMatrix[tempX][tempY] = i;
		X=tempX;
		Y=tempY;
	}
	
	int count = 0;
	for(int i = 0;i<N;i++){
		for(int j=0;j<N;j++){
			if(count==N*N){
				cout<<SnakeMatrix[i][j]<<endl;
			}else{
				cout<<SnakeMatrix[i][j]<<' ';
			}
		}
	}
	return 0;
}