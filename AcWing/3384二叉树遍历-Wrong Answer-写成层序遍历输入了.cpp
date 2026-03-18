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

void ChildInput(Node*& parent, queue<Node*>& NodeQue){
	char leftCh,rightCh;
	cin>>leftCh;
	cin>>rightCh;
	if(leftCh!='#'){
		parent->left = new Node(leftCh);
		NodeQue.push(parent->left);
	}
	if(rightCh!='#'){
		parent->right = new Node(rightCh);
		NodeQue.push(parent->right);
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
	queue<Node*> NodeQue;
	Node* root;
	char tempCh;
	cin>>tempCh;
	if(tempCh!='#'){
		root = new Node(tempCh);
		NodeQue.push(root);
	}else{
		cout<<"empty Tree!";
		return 0;
	}
	
	while(!NodeQue.empty()){
		Node* tempNode = NodeQue.front();
		NodeQue.pop();
		ChildInput(tempNode,NodeQue);
	}
	
	InSearch(root);
	
	return 0;
}