#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;

unordered_map<char,char> mp = {
{'<', '>'},
{'(', ')'},
{'[', ']'},
{'{', '}'}
};

int main(){
	stack<char> khStack;
		
	string tempKH;
	getline(cin,tempKH);
		
	int len = tempKH.size();
		
	if(len == 0){//empty
		cout<<"empty"<<endl;
	}
	int j;
	for(j = 0; j < len;j++){
		if(tempKH[j]=='<'||tempKH[j]=='('||tempKH[j]=='['||tempKH[j]=='{'){
			if(khStack.empty()){
				khStack.push(tempKH[j]);
				continue;
			}
			khStack.push(tempKH[j]);

		}
		if(tempKH[j]=='>'||tempKH[j]==')'||tempKH[j]==']'||tempKH[j]=='}'){
			if(khStack.empty()){
//				cout<<"NO"<<endl;
				break;
			}
			if(mp[khStack.top()]==tempKH[j]){
				khStack.pop();
			}else{
//				cout<<"NO"<<endl;
				break;
			}
		}
	}
	if(j==len&&khStack.empty()){
		cout<<"yes"<<endl;
	}else{
		cout<<"no"<<endl;
	}
return 0;
}