#include<iostream>
using namespace std;

const int SIZE = 100;

struct queue{
	int arr[SIZE];
	int front;
	int rear;
}q;
void createQ()
{
	q.front = q.rear = -1;
}

int isEmpty()
{
	return (q.rear == -1);
}

int isFull()
{
	return (q.rear == SIZE - 1);
}

void enQ(int value)
{
	if (isFull())
		cout<<"Full"<<endl;
	else
	{	if (isEmpty())
			q.front++;
		q.arr[++q.rear] = value;
	}
}

void deQ()
{
	if (isEmpty())
		cout<<"Empty";
	else
		q.front+=1;
}

void displayQ()
{
	for (int i = q.front; i<q.rear;i++)
		cout<<q.arr[i]<<"~~~~~";
	cout<<endl;
}

main()
{
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
