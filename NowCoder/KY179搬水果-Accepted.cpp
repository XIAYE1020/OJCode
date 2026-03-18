#include<iostream>
#include<queue>
using namespace std;

int main(){
	int n;
	while(cin>>n){
		int ans = 0;
		priority_queue<int,vector<int>,greater<int>> PriQue;
		if(n==0){
			return 0;
		}
		
		for(int i= 0;i<n;i++){
			int tempNum;
			cin>>tempNum;
			PriQue.push(tempNum);
		}
		
		while(PriQue.size()>1){
			int num1 = PriQue.top();
			PriQue.pop();
			int num2 = PriQue.top();
			PriQue.pop();
			int sum = num1+num2;
			ans+=sum;
			PriQue.push(sum);
		}
		cout<<ans<<endl;
	}
	return 0;
}