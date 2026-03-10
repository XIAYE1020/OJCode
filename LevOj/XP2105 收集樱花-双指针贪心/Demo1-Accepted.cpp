#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;//record the numbers of the sakura trees
	int v;//record the volumn of the bag
	while(cin>>n>>v){
		vector<int> saku(n);
		int max = 0;//record the answer;
		for(int i = 0; i < n;i++){//input sakura numbers
			cin>>saku[i];
		}
		int left = 0,tempSum = 0;
		for(int right = 0;right < n;right++){
			tempSum+=saku[right];
			
			while(tempSum>v){
				tempSum-=saku[left];
				left++;
			}
			
			if(tempSum>max){
				max = tempSum;
			}
		}
		cout<<max<<endl;
	}
}