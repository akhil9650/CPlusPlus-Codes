#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *prev;
	struct node *next;
}*head;

struct node *create_node(int value)
{
	node *temp;
	temp = new(struct node);
	if (!temp)
		cout<<"Memory Not Allocated";
	else
	{
		temp->data = value;
		temp->prev = temp->next = NULL;
		return temp;
		cout<<temp->data<<" h ";
	}
}

void insertAtStart(int value)
{	
	struct node *temp;
	if (head == NULL)
	{	
		head = create_node(5);
	}
	else
	{
	temp = create_node(value);
	temp->next = head;
	head->prev = temp;
	head = temp;
	}

}
void insertAtEnd(int value)
{	
	struct node *ptr,*temp = head;
	
	if (head == NULL)
	{	
		cout<<"Empty List";
	}
	else
	{
	while (temp->next != NULL)
	{
	temp = temp->next;
	}
	ptr = create_node(value);
	temp->next = ptr;
	ptr->prev = temp;
	}

}
void insertAtPos(int value, int pos)
{	
	int count = 0, k = 1;
	struct node *ptr,*temp = head;
	
	if (head == NULL)
	{	
		cout<<"Empty List";
	}
	else
	{
	while (temp->next != NULL)
	{
	temp = temp->next;
	count++;
	}
	temp = head;
	if (pos>count)
		cout<<"Out of bounds"<<endl;
	else
	{
	while (k<(pos-1))
	{
	temp = temp->next;
	k++;
	}
	ptr = create_node(value);
	ptr->next = temp->next;
	temp->next = ptr;
	ptr->prev = temp;	
	}
}
}


void display()
{
	struct node *temp = head;
	if (head == NULL)
		cout<<"Empty List";
	else{
		while(temp != NULL)
		{
			cout<<temp->data<<"->";
			temp = temp->next;
		}
		cout<<"NULL"<<endl;
		}
}
main()
{
	
//	struct node *head = create_node(5);

	insertAtStart(5);
	display();
	insertAtStart(6);
	display();		
	insertAtStart(7);
	display();	
	insertAtEnd(8);
	display();	
	insertAtEnd(9);
	display();	
	insertAtEnd(10);
	display();	
	insertAtPos(1,3);
	display();	
	insertAtPos(2,8);
	display();	
	insertAtPos(3,5);
	display();
		
}
