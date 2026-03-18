#include<iostream>
using namespace std;

string inOrder, preOrder;

void postOrder(string& pre,string& in){
	if(pre.empty()){
		return ;
	}
	
	char root = pre[0];
	int rootPos = in.find(root);//position of root
	
	
	string in_left = in.substr(0,rootPos);
	string in_right = in.substr(rootPos+1);

	
	string pre_left = pre.substr(1, in_left.size());
	string pre_right = pre.substr(in_left.size() + 1);

	
	postOrder(pre_left,in_left);
	postOrder(pre_right,in_right);
	
	cout<<root;
}

int main(){
	while(cin>>inOrder>>preOrder){
		postOrder(preOrder,inOrder);
		cout<<endl;
	}
}