#include<iostream>
#include<queue>
using namespace std;

int main(){
	int n,WPL=0;
	cin>>n;
	priority_queue<int,vector<int>,greater<int>> PriQue;
	for(int i = 0;i<n;i++){
		int curNum;
		cin>>curNum;
		PriQue.push(curNum);
	}
	
	while(PriQue.size()!=1){
		int num1,num2;
		num1 = PriQue.top();
		PriQue.pop();
		num2 = PriQue.top();
		PriQue.pop();
		WPL+=num1+num2;
		PriQue.push(num1+num2);
	}
	cout<<WPL<<endl;
	return 0;
}