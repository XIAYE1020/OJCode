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

bool khCmp(char a, char b){//a>=b ? 
	int aNum;
	int bNum;
	if(a=='<'){
		aNum = 1;
	}
	if(a=='('){
		aNum = 2;
	}
	if(a=='['){
		aNum = 3;
	}
	if(a=='{'){
		aNum = 4;
	}
	
	if(b=='<'){
		bNum = 1;
	}
	if(b=='('){
		bNum = 2;
	}
	if(b=='['){
		bNum = 3;
	}
	if(b=='{'){
		bNum = 4;
	}
	
	return aNum>=bNum;
}

int main(){
	int n;
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++){
		stack<char> khStack;
		
		string tempKH;
		getline(cin,tempKH);
		
		int len = tempKH.size();
		
		if(len == 0){//empty
			cout<<"empty"<<endl;
			continue;
		}
		int j;
		for(j = 0; j < len;j++){
			if(tempKH[j]=='<'||tempKH[j]=='('||tempKH[j]=='['||tempKH[j]=='{'){
				if(khStack.empty()){
					khStack.push(tempKH[j]);
					continue;
				}
				
				if(khCmp(khStack.top(), tempKH[j])){
					khStack.push(tempKH[j]);
				}else{
//					cout<<"NO"<<endl;
					break;
				}
			}
			if(tempKH[j]=='>'||tempKH[j]==')'||tempKH[j]==']'||tempKH[j]=='}'){
				if(khStack.empty()){
//					cout<<"NO"<<endl;
					break;
				}
				if(mp[khStack.top()]==tempKH[j]){
					khStack.pop();
				}else{
//					cout<<"NO"<<endl;
					break;
				}
			}
		}
		if(j==len&&khStack.empty()){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}