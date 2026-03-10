#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;//record the numbers of the sakura trees
	int v;//record the volumn of the bag
	while(cin>>n>>v){
		int saku[200000]={0};
		int max = 0;//record the answer;
		for(int i = 0; i < n;i++){//input sakura numbers
			cin>>saku[i];
		}
		for(int i = 0;i < n;i++){
			int tempSum = 0;//using to sum the Nums of sakura,starting from No.i tree
			for(int j = i;j<n;j++){
				tempSum += saku[j];
				if(tempSum > v){//overflow,stop summing the trees in the rear of the line 
					break;
				}else if(tempSum > max){
					max=tempSum;
				}
			}
		}
		cout<<max<<endl;
	}
}