#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		vector<int> aList(n);
		for(int i = 0; i < n; i++){
			cin >> aList[i];
		}
		
		int tempSum = aList[0];
		int maxSum = aList[0];
		
		for(int i = 1; i < n; i++){
			if(tempSum>0){
				tempSum += aList[i];
			}else{
				tempSum = aList[i];
			}
			
			maxSum = max(maxSum, tempSum); 
		}
		
		cout << maxSum << endl;
	}
	return 0;
}