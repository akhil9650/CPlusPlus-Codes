#include<iostream>
#include<stdlib.h>
using namespace std;

struct BST{
	int data;
	BST *left;
	BST *right;
}*root;

BST *newNode(int value)
{
	BST *temp = new BST;
	temp->data = value;
	temp->left = temp->right = NULL;
	
	return temp;
}

void inOrder(BST *root)
{
	BST *temp = root;
	if (!root)
		return;
	inOrder(root->left);
	cout<<"->"<<root->data;
	inOrder(root->right);

}

BST *search(BST *root, int value)
{
	if (root == NULL)
		return NULL;
	if (root->data == value)
		return root;
	else if (root->data > value)
		return search(root->left,value);
	else
		return search(root->right,value);
	return root;
}

void insert(BST *root,int value)
{
	if (root == NULL)
		return;
	BST *k = search(root,value);
	
	if (k)
		cout<<"Element already exists";
	else
	{
		BST *prev;
		BST *temp = root;
		while(temp)
		{
			prev = temp;
			if (temp->data > value)
				temp = temp->left;
			else
				temp = temp->right;
		}
		temp = newNode(value);
		if (prev->data >value)
			prev->left = temp;
		else
			prev->right = temp;
		cout<<"Inserted"<<endl;
	}
}

BST *findMax(BST *root)
{
	if (!root)
		return NULL;
	while(root->right != NULL)
		root = root->right;
	return root;
}

void delNode(BST *root,int value)
{
	if (!search(root,value))
		cout<<"Doesn't Exist"<<endl;
	else{
		BST *temp = root;
		while (temp!= NULL)
		{	
			BST *prev= temp;
			if (value<temp->data)
				temp = temp->left;
			else if (value>temp->data)
				temp = temp->right;
			else{
				if (!temp->left && !temp->right){
					if (prev->left == temp){
						prev->left = NULL;
					}
					else
					{
						prev->right = NULL;
					}
					temp = NULL;
					}
				else if (!temp->left && temp->right)
					{
					prev->right = temp->right;
					temp = NULL;
					}
				else if (temp->left && !temp->right)
					{
					prev->left = temp->left;
					temp = NULL;
					}
				else{
					BST *max = findMax(temp->left);
					if (prev->left == temp){
						prev->left = max;
						temp = NULL;
					}
					else
					{
						prev->right = max;
						temp = NULL;
					}
				}
			}
		}
	}
}
int count = 0;

BST *kth(BST *root,int k)
{

	if (!root)
		return NULL;
	
	BST *l = kth(root->left,k);
	if(l)
		return l;
		
	if(++count == k)
		return root;
	return kth(root->right,k);
}


BST *lca(BST *root, BST *a,BST *b)
{
	if (a->data <root->data && b->data >root->data)
		return root;
	else if(a->data>root->data && b->data > root->data)
		return lca(root->right,a,b);
	else if (a->data >root->data && b->data <root->data)
		return root;	
	else
		return lca(root->left,a,b);

}
int flag =1;
int checkBST(BST *root)
{
	if (root == NULL)
		return 1;
	if (root->left && root->left->data > root->data)
		return 0;
	if (root->right && root->right->data < root->data)
		return 0;
		
	if (!checkBST(root->left) && (!checkBST(root->right)))
		return 0;

	return 1;

}

BST *successor(BST *ptr)
{
	if (!ptr)
		return ptr;
	BST *temp = ptr->right;
	while (temp!= NULL)
		temp = temp->left;
	return temp;
}

void inRange(BST *root,int k1,int k2)
{
	BST *temp = root;
	if (!root)
		return;
	inRange(root->left,k1,k2);
	if (root->data >k1 && root->data <k2)
		cout<<"->"<<root->data;
	inRange(root->right,k1,k2);

}

main()
{

	root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(8);
	root->right->left = newNode(5);
	root->right->left->right = newNode(7);
	root->right->left->right->left = newNode(6);
	root->right->right = newNode(10);


//	root = newNode(6);
//	root->left = newNode(2);
//	root->left->left = newNode(1);
//	root->left->right = newNode(3);
//	root->right = newNode(9);
//	root->right->left = newNode(7);
//	root->right->right = newNode(10);
	inOrder(root);
	cout<<endl;  

	BST *k = search(root,9);
	if (k)
		cout<<"Exists ::"<<k->data<<endl;
	else
		cout<<"Doesn't exist ::9"<<endl;
	k = search(root,5);
	if (k)
		cout<<"Exists ::"<<k->data<<endl;
	else
		cout<<"Doesn't exist ::5"<<endl;

//	insert(root,5);
//	
//	inOrder(root);
///	
//	cout<<endl;
//	
//	insert(root,8);
	
	//inOrder(root);
	
	
	BST *laca = lca(root,root->right->left->right->left,root->right->right);
	cout<<"Least common ancestor of ";
	cout<<root->right->left->right->left->data<<" and ";
	cout<<root->right->right->data<<" is ::"<<laca->data<<endl;

	cout<<"Checking for BST ::"<<checkBST(root)<<endl;
	inRange(root,2,8);
	
	

}
