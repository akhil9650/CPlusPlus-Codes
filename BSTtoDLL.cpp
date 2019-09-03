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

void binarytoDLL(BST *root,BST *head)
{
	if (root == NULL)
		return;

	binarytoDLL(root->right,head);
	root->right= head;
	if (head)
		head->left = root;
	head = root;
	cout<<"Head ::"<<head->data<<endl;
	binarytoDLL(root->left,head);

}

void print(BST* head)
{
    struct BST* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->right;
    }
}

void convert(BST *root,BST *head,BST *prev)
{
	if (!root)
		return;
	convert(root->left,head,prev);
	
	if (prev)
		prev->right = root;
	else
		head = root;
	
	root->left = prev;
	prev = root;
	
	if (root->right)
		convert(root->right,head,prev);
		
	struct BST* temp = prev;
    while (temp) {
        cout << temp->data << "-->";
        temp = temp->right;
    }
    cout<<"______________________"<<endl;

		
	
}
main()
{
	BST *head = NULL;
	BST *prev = NULL;

	root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(8);
	root->right->left = newNode(5);
	root->right->left->right = newNode(7);
	root->right->left->right->left = newNode(6);
	root->right->right = newNode(10);

//	binarytoDLL(root,head);
//	cout<<head->data;
///	cout<<"Alog";
///	print(head);
//
	convert(root,head,prev);
	cout<<"Print List ::"<<endl;
	print(head);

	return 0;

}
