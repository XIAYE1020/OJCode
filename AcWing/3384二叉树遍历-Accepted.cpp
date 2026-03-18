#include<iostream>
#include<queue>
using namespace std;

typedef struct BiTreeNode{
	char data;
	struct BiTreeNode* left;
	struct BiTreeNode* right;
	
	BiTreeNode(char val):data(val),left(nullptr),right(nullptr){
	}
}Node;

Node* Build(){
	char tempCh;
	cin>>tempCh;
	if(tempCh=='#'){
		return nullptr;
	}else{
		Node* root = new Node(tempCh);
		root->left = Build();
		root->right = Build();
		return root;
	}
}

void InSearch(Node* root){
	if(root!=nullptr){
		InSearch(root->left);
		cout<<root->data<<' ';
		InSearch(root->right);
	}else{
		return;
	}
}

int main(){
	Node* root;
	root = Build();
	InSearch(root);
	return 0;
}