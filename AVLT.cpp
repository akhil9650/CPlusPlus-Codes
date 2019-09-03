#include<iostream>
#include<stdlib.h>
using namespace std;

struct AVL{
	int data;
	AVL *right;
	AVL *left;
}*root;

AVL *create(int value)
{
	AVL *temp = new AVL;
	temp->data = value;
	temp->right =NULL;
	temp->left = NULL;
	return temp;
}

AVL *single_left(AVL *X)
{
	AVL *W = X->right;
	X->right = W->left;
	W->left = X;
	return W;
}

AVL *single_right(AVL *X)
{
	AVL *W = X->left;
	X->left = W->right;
	W->right = X;
	return W;
}

AVL *left_right(AVL *X)
{
	X->right = single_right(X->right);
	return single_left(X);
}

AVL *right_left(AVL *X)
{
	X->left = single_left(X->left);
	return single_right(X);
}

int lh,rh;

int height(AVL *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

int diff(AVL *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}

AVL *balance(AVL *root)
{
	int bal = diff(root);
	if (bal>1)
	{	
		if (diff(root->left)>0){
			root = single_right(root);}
		else{
			root = right_left(root);}
	}
	else if (bal<-1)
	{
		if (diff(root->right)>0){
			root = left_right(root);}
		else{
			root = single_left(root);}
	}
	return root;
}

AVL *insert(AVL *root, int value)
{
	
	if (root == NULL)
	{
		return create(value);
	}
	if (root->data > value)
	{
		root->left = insert(root->left,value);	
		root = balance(root);
	}
	else if (root->data <= value)
	{	
		root->right = insert(root->right,value);
		root = balance(root);
	}
	return root;

}

void inOrder(AVL *root)
{
	if (!root)
		return;
	inOrder(root->left);
	cout<<"->"<<root->data;
	inOrder(root->right);
}

void display(AVL *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level + 1);
    	cout<<endl;
        if (ptr == root)
        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->data;
        display(ptr->left, level + 1);
    }
}

AVL *pruneAVL(AVL *root,int a,int b)
{
	if (!root)
		return NULL;
	root->left = pruneAVL(root->left,a,b);
	root->right = pruneAVL(root->right,a,b);
	if (root->data >a && root->data <b)
		return root;
	if (root->data <a)
		return root->right;
	if (root->data >b)
		return root->left;

	return root;
}

main()
{
	root = create(6);
	root->left = create(4);
	root->left->left = create(3);
	root->left->right = create(5);
	root->right = create(9);
	root->right->left = create(7);
	root->right->right = create(15);
	cout<<"Difference of heights of tree is "<<diff(root)<<endl;
	display(root,0);
	cout<<endl;
	root = insert(root,1);
	display(root,0);
	root = insert(root,2);
	display(root,0);
	root = insert(root,1);
	display(root,0);
	root = insert(root,14);
	display(root,0);
	root = insert(root,12);
	display(root,0);
	cout<<endl;
//	cout<<"Inordering"<<endl;
//	inOrder(root);
	
	
	cout<<"Pruning"<<endl;
	
	pruneAVL(root,2,10);
	display(root,0);



}
