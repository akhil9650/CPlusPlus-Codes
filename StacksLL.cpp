#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node *next;
}*top;
void create(){
	top = NULL;
}

void push(int value)
{	
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = value;
	if (top == NULL)
		{
			temp->next = NULL;	
		}
	else
	{
	temp->next = top;
	}
	top = temp;
	cout<<value<<" pushed"<<endl;

	
}

void pop()
{
	if (top == NULL)
		cout<<"Empty";
	struct node *temp = top;
	cout<<temp->data<<" popped out"<<endl;
	top = top->next;
	free(temp);
}

void display()
{
	struct node *temp = top;
	if (!temp)
		cout<<"Empty"<<endl;
	
	while (temp != NULL)
	{
		cout<<temp->data<<"------";
		temp = temp->next;
	}
	cout<<endl;
}

main()
{
	create();
	cout<<"Created"<<endl;
	push(1);
	display();
	push(2);
	display();
	push(3);
	display();
	push(4);
	display();
	push(5);
	display();
	push(6);
	display();
	pop();
	display();
	pop();
	display();	
	pop();
	display();
	pop();
	display();
	pop();
	display();
	pop();
	display();

}
