#include<iostream>
using namespace std;

const int SIZE = 100;

struct queue{
	int arr[SIZE];
	int front;
	int rear;
}q;

class Stack
{
private:
	
	int names[SIZE];
	int top;

public:
		
	Stack()
	{ 
		top = -1; 
	}
	
	~Stack(){}
	
	bool isFull()
	{
		return top == SIZE-1;
	}
	
	bool isEmpty()
	{
		return top == -1;
	}
	
	void makeEmpty()
	{
		top = -1;
	}
	
	void push(int item)
	{
		top++; 
		names[top] = item;
	}
	
	int pop()
	{
		if(top <0)
	{
		cout<<"Empty";
		exit(1);
	}	
	else{
	int item;
		item = names[top];
		top--;
		return item;
	}
	}
	int gettop()
	{
		return top;
	}
	void display()
	{
		int i;
    if(top>=0)
    {
        for(i=top; i>=0; i--)
            cout<<"---"<<names[i];
        cout<<endl;
    }
    else
    {
        cout<<" The STACK is empty";
    }
    
	}
}s1,s2;

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
		s1.push(value);
}

void deQ()
{
	if (isEmpty())
		cout<<"Empty";
	else
		while (!s1.isEmpty())
		{
			s2.push(s1.pop());
		}
	cout<<endl;
	cout<<"~~~~~~~~~~~"<<s2.pop();
	
}

void displayQ()
{
	s1.display();
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
