#include<iostream>
using namespace std;
int count;
void testChild(int curNum, int n){
	if(curNum*2<=n){
		count++;
		testChild(curNum*2,n);
	}
	
	if(curNum*2+1<=n){
		count++;
		testChild(curNum*2+1,n);
	}
}

int main(){
	int m,n;
	while(cin>>m>>n){
		if(m==0||n==0){
			return 0;
		}
		count = 1;
		testChild(m,n);
		cout<<count<<endl;
	}
	return 0;
}