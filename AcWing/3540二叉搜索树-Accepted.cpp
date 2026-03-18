#include<iostream>
using namespace std;

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	
	Node(int val):data(val),left(nullptr),right(nullptr){}
}Node;

Node* Insert(Node* root, const int val){
	if(root==nullptr){
		root = new Node(val);
		return root;
	}
	
	if(root->data>val){
		root->left = Insert(root->left, val);
	}else if(root->data<val){
		root->right = Insert(root->right, val);
	}
	return root;
}

void PreOrder(Node* root){
	if(root==nullptr){
		return ;
	}
	cout<<root->data<<' ';
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(Node* root){
	if(root==nullptr){
		return ;
	}
	InOrder(root->left);
	cout<<root->data<<' ';
	InOrder(root->right);
}

void PostOrder(Node* root){
	if(root==nullptr){
		return ;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<' ';
}

int main(){
	int n;
	cin>>n;
	Node* root = nullptr;
	for(int i = 0;i<n;i++){
		int num;
		cin>>num;
		root = Insert(root,num);
	}
	
	PreOrder(root);
	cout<<endl;
	InOrder(root);
	cout<<endl;
	PostOrder(root);
	cout<<endl;
	return 0;
}