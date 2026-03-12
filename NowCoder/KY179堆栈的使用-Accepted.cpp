#include<iostream>
#include<stack>
#include<string>
using namespace std;

void funcP(stack<int>& stkNum){
	string numP;
	cin>>numP;
	int len = numP.size();
	int num = 0;
	for(int i = 0;i<len;i++){
		num=num*10+(numP[i]-'0');
	}
	stkNum.push(num);
}

void funcO(stack<int>& stkNum){
	if(!stkNum.empty()){
		stkNum.pop();
	}

}

void funcA(stack<int>& stkNum){
	if(stkNum.empty()){
		cout<<'E'<<endl;
	}else{
		cout<<stkNum.top()<<endl;
	}
}

int main(){
	int n;
	while(cin>>n){
		stack<int> stkNum;
		for(int i = 0; i < n;i++){
			char curCh;
			cin>>curCh;
			if(curCh=='P'){
				funcP(stkNum);
			}else if(curCh=='O'){
				funcO(stkNum);
			}else if(curCh=='A'){
				funcA(stkNum);
			}else{
				cout<<"Unvalid character!"<<endl;
			}
			
		}
		
	}
	return 0;
}