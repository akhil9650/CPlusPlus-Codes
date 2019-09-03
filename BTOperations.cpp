#include<iostream>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
}*root;

struct node *insert(node *root , int value)
{
	node *temp = new node;
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;
	if (root == NULL)
	{
		root = temp;
		cout<<"Root Node Added"<<endl;
	}
//	if (root->data == value)
//	{
//		cout<<"Element already in the tree"<<endl;
//	}
else{
	if (root->data > value)
	{
		if (root->left != NULL)
			root->left = insert(root->left,value);
		else{
			root->left = temp;
			cout<<"Node added to left"<<endl;
		}
	}
	else
	{
	if (root->right != NULL)
		root->right = insert(root->right, value);
	else{
		root->right = temp;
		cout<<"Node added to right"<<endl;
	}	
	} 
	}
	
	return root;
}

void preOrder(node *root)
{
	if (root == NULL)
		return;
		
	cout<<root->data<<"--------";
	preOrder(root->left);
	preOrder(root->right);
	cout<<endl;
}

void inOrder(node *root)
{
	if (root == NULL)
		return;
	preOrder(root->left);
	cout<<root->data<<"--------";
	preOrder(root->right);
	cout<<endl;
}

void postOrder(node *root)
{
	if (root == NULL)
		return;
		
	preOrder(root->left);
	preOrder(root->right);
	cout<<root->data<<"--------";
	cout<<endl;
}

main(){
//	root = new node;
	root = NULL;
	root = insert(root , 1);
	preOrder(root);
	root = insert(root , 12);
	cout<<"Root   ";
	cout<<root->data<<endl;
//	cout<<root->data<<endl;
//	if (root->left == NULL)
//			cout<<"LA      ";
//	if (root->right == NULL)
//		cout<<"ra    "; 
//	cout<<root->left->data<<endl;
//	cout<<root->right->data<<endl;
//	preOrder(root);
	root = insert(root , 9);
	cout<<"Root   ";
	cout<<root->data<<endl;
//	preOrder(root);
	root = insert(root , 5);
	cout<<"Root   ";
	cout<<root->data<<endl;	
//	preOrder(root);
	root = insert(root , 6);
	cout<<"Root   ";
	cout<<root->data<<endl;
//	preOrder(root);
//	insert(root , 4);
	preOrder(root);	
	inOrder(root);
	postOrder(root);

}
