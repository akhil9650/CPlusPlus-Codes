#include <iostream>
#include<stdlib.h>
using namespace std;
 
struct BNode {
    BNode* left, *right;
    int data;
};
 
struct QNode {
    QNode* next;
    BNode* BData;
};
 
struct Queue {
    QNode* front, *rear;
};
 
QNode* newQNode(BNode* data)
{
    QNode* temp = new QNode;
    temp->BData = data;
    temp->next = NULL;
    return temp;
}
 
BNode* newBNode(int data)
{
    BNode* temp = new BNode;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
void enQueue(Queue* q, BNode* data)
{
    QNode* temp = newQNode(data);
    if (q->front == NULL && q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
 
    q->rear->next = temp;
    q->rear = temp;
}
 
BNode* pop(Queue* q)
{
    if (q->front == NULL)
        return NULL;
 
    QNode* temp = q->front;
    BNode* bdata = temp->BData;
    q->front = q->front->next;
 
    if (q->front == NULL)
        q->rear = NULL;
 
    return bdata;
}
 
bool IsEmpty(Queue* q)
{
    return (q->front == NULL && q->rear == NULL);
}
 
void inorder(struct BNode* temp)
{
    if (!temp)
        return;
 
    inorder(temp->left);
    cout << temp->data <<" ";
    inorder(temp->right);
}
 
 
 
void insert(BNode* root, int key)
{
	
Queue *Q = new Queue;
Q->front = Q->rear = NULL;
BNode *temp = newBNode(key);

enQueue(Q,root);
while (!IsEmpty(Q))
{
	BNode *ptr = pop(Q);	
	if (ptr->left == NULL){
		ptr->left = temp;
		return;
		}
	else 
		enQueue(Q, ptr->left);
	if (ptr->right == NULL){
		ptr->right = temp;
		return;
		}
	else
		enQueue(Q, ptr->right);
}
}

	int MAX = 0;
int findMax(BNode *root)
{
	
	if (!root)
		return MAX;
	
	if (root->data > MAX)
		MAX = root->data;
		
	findMax(root->left);
	findMax(root->right);
}
 
int findMax1(BNode *root){
	MAX = 0;
	Queue *Q = new Queue;
	if (root->data > MAX)
		MAX = root->data;	
	enQueue(Q,root);
	while (!IsEmpty(Q)){
		BNode *ptr = pop(Q);
		if (ptr->left != NULL)
		{	
			enQueue(Q,ptr->left);
			if (ptr->left->data > MAX)
				MAX = ptr->left->data;
		}
		if (ptr->right != NULL)
		{	
			enQueue(Q,ptr->right);
			if (ptr->right->data > MAX)
				MAX = ptr->right->data;
			
		}		
	}
return MAX;
} 
 int SIZE = 0;
 int findSize(BNode *root)
 {
 	if (root)
 		SIZE++;
 	else
 		return SIZE;
 	findSize(root->left);
 	findSize(root->right);
 }
 
 int findSize1(BNode *root)
 {
 	SIZE = 1;
 	
 	Queue *Q = new Queue;
 	
 	enQueue(Q, root);
 	while (!IsEmpty(Q))
 	{
 		BNode *ptr = pop(Q);
 		if (ptr->left)
 		{
			enQueue(Q,ptr->left);
			SIZE++;
		}
		if (ptr->right)
		{
			enQueue(Q,ptr->right);
			SIZE++;
		}
	}
	return SIZE;
 }
 
 bool findNum(BNode *root, int value)
 {
 	SIZE = 1;
 	
 	Queue *Q = new Queue;
 	if (root->data == value)
 		return 1;
 	
 	enQueue(Q, root);
 	while (!IsEmpty(Q))
 	{
 		BNode *ptr = pop(Q);
 		if (ptr->left)
 		{
 			if (ptr->left->data == value)
 				return 1;
 			else
				enQueue(Q,ptr->left);
		}
		if (ptr->right)
		{
			if (ptr->right->data == value)
				return 1;
			else
				enQueue(Q,ptr->right);
		}
	}
	return 0;
 }
 
 int height(BNode *root)
 {
 	if (root == NULL)
 		return 0;
 	int lh = height(root->left);
 	int rh = height(root->right);
 	
 	if (lh>rh)
 		return (lh+1);
 	else
 		return (rh+1);
 }
 
 BNode *findDeepest(BNode *root)
 {
 	BNode *temp;
 	Queue *Q = new Queue;
 	enQueue(Q,root);
 	do
 	{
 		temp = pop(Q);
 		if (temp->left)
		 	enQueue(Q,temp->left);
		if (temp->right)
			enQueue(Q,temp->right) ;
	}while (Q->front != Q->rear);
	
	temp = pop(Q);
	cout<<"Deepest ::"<<temp->data<<endl;
	return temp;
 }
 
 int search(BNode *root,int value)
 {
 	if (root->data == value)
 		{
 			cout<<"Found";
 			cout<<"At root";
 			return 1;
		}
	Queue *Q = new Queue;
 	enQueue(Q,root);
 	while (!IsEmpty(Q))
 	{	
	    BNode *temp = pop(Q);
 		if (temp->data == value)
 			return 1;
		if (root->left)
 			enQueue(Q,temp->left);
 		if (root->right)
 			enQueue(Q,temp->right);
	}
	if (IsEmpty(Q))
		return 0;
 }
 
 int sumAll(BNode *root)
 {
 	if (root == NULL)
 		return 0;
 	else
		return (root->data + sumAll(root->left) + sumAll(root->right));
 }
 void delNode(BNode *root,BNode *ptr)
 {
 	if (!root)
 		cout<<"Empty";
 	BNode *temp = findDeepest(root);
 	BNode *ap = ptr;
 	ptr->data = temp->data;
 	temp->data = ap->data;
 	delete(temp);
 	
 }
 
void delTree(BNode *root)
 {
 	if (root == NULL)
 		return;
 	delTree(root->left);
	delTree(root->right);
	cout<<"Deleting ->"<<root->data<<endl;
	free(root);	
 }
  
 
int main() 
{
    BNode* root = newBNode(1);
    root->left = newBNode(2);
    root->left->left = newBNode(4);
    root->right = newBNode(3);
 //   root->right->left = newBNode(15);
    root->left->right = newBNode(5);
    root->right->right = newBNode(10);
    root->right->right->left = newBNode(177);
 
    cout << "Inorder traversal before insertion:";
    inorder(root);
 
    int key = 12;
    insert(root, key);
 
    cout << endl;
    cout << "Inorder traversal after insertion:";
    inorder(root);
    
    cout<<"MAX element :: ";
    int m = findMax(root);
    cout<<m<<endl;
    
    
    
    
    
    insert(root , 1222);

 
    cout << endl;
    cout << "Inorder traversal after insertion:";
    inorder(root); 


    
    cout<<"MAX element :: ";
    m = findMax(root);
    cout<<m<<endl;
    
    
    cout<<"Without recursion ::";
    m = findMax1(root);
    cout<<m<<endl;
    
    cout<<"SIZE ::"<<findSize(root)<<endl;
    cout<<"SIZE without recursion "<<findSize1(root)<<endl;
    
    cout<<"Does 3 exist in the list "<<findNum(root,3)<<endl;
    
    cout<<"Height ::"<<height(root)<<endl;
    
    BNode *ptr = findDeepest(root);
    
    int query = search(root,12);
    cout<<"Find 12 in the list ::"<<query<<endl;
    
    cout<<"Sum of all elements ::"<<sumAll(root)<<endl;
 //	delNode(root,root->left->right);
//	cout<<"After deletion ::"; 
//	inorder(root);
	cout<<"Root  ::"<<root->data<<endl;
	
	delTree(root);
	cout<<"Deletion of tree  :::::::::";
//	inorder(root);
	cout<<"Root  ::"<<root->data;	
	cout<<"Root  ::"<<root->left->data;
	return 0;

}
