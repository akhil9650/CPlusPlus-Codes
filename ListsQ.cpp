#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	node *next;
};

struct queue{
	node *front;
	node *rear;
}q;
queue *createQ()
{
	queue *q;
	node *temp;
	q = (queue *)malloc(sizeof(struct queue));
	if (!q)
		cout<<"Memory can't be allocated";
	temp = (node *)malloc(sizeof(struct node));
	q->front = q->rear = NULL;
	return q;

}

void enQ(int value)
{
	node *temp  =(node *)malloc(sizeof(struct node));

	if (!temp)
		cout<<"Full"<<endl;
	else
	{	
		temp->data = value;
		temp->next = NULL;
		if (q.rear == NULL)
		{
			q.front =temp;
			q.rear =temp; 
		}
		else
		{	
			q.rear->next = temp;
			q.rear = temp;
		}		
		
	}
}

void deQ()
{
	if (q.front == NULL)
		cout<<"Empty";
	else
		q.front = q.front->next;
}

void displayQ()
{
	struct node *temp = q.front;
	while (temp != NULL){
		cout<<temp->data<<"~~~~~";
		temp = temp->next;
	}
	cout<<endl;
}

main()
{
	createQ();
	enQ(1);

	displayQ();
	enQ(2);
	displayQ();
	enQ(3);
	displayQ();
	enQ(4);
	displayQ();
	enQ(5);
	displayQ();
	enQ(6);
	displayQ();
	enQ(7);
	displayQ();
	enQ(8);
	displayQ();
	enQ(9);
	displayQ();
	enQ(10);
	displayQ();
	deQ();
	displayQ();
	deQ();
	displayQ();
	deQ();
	displayQ();
	deQ();
	displayQ();
	deQ();
	displayQ();
	deQ();
	displayQ();
	deQ();
	displayQ();
	deQ();
	displayQ();
	deQ();
	displayQ();
	deQ();
	displayQ();
	
	
}
