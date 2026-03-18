#include<iostream>
using namespace std;

typedef struct BiNode{
	int data;
	struct BiNode* left;
	struct BiNode* right;
	
	BiNode(int val):data(val),left(nullptr),right(nullptr){
	}
	
}Node;

void InsertBiTree(int num, Node* root){
	if(num>=root->data){//num>=root
		if(root->right==nullptr){
			cout<<root->data<<endl;
			root->right = new Node(num);
		}else{
			InsertBiTree(num,root->right);
		}
	}else{//num<root
		if(root->left==nullptr){
			cout<<root->data<<endl;
			root->left =new Node(num);
		}else{
			InsertBiTree(num,root->left);
		}
	}
}

int main(){
	int N;
	cin>>N;
	Node* root = new Node(-1);
	for(int i = 0;i<N;i++){
		int curNum;
		cin>>curNum;
		InsertBiTree(curNum,root);
	}
	return 0;
}