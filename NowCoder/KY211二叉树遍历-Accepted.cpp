#include<iostream>
#include<string>
using namespace std;

void postOrder(string& FrontStr,string& InStr){
	if(FrontStr.empty()){
		return;
	}
	char root = FrontStr[0];
	int rootInPos = InStr.find(root);
	
	string leftIn = InStr.substr(0,rootInPos);
	string rightIn = InStr.substr(rootInPos+1);
	
	string leftFront = FrontStr.substr(1,leftIn.size());
	string rightFront = FrontStr.substr(leftIn.size()+1);
	
	postOrder(leftFront,leftIn);
	postOrder(rightFront,rightIn);
	
	cout<<root;
}

int main(){
	string FrontStr;
	string InStr;
	while(cin>>FrontStr>>InStr){
		postOrder(FrontStr,InStr);
		cout<<endl;
	}
	return 0;
}