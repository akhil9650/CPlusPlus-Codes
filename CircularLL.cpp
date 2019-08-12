#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	node *next;
}*head;


void insert1(int value)
{

struct node *ptr = NULL,*temp = head; 
ptr = new(struct node);
ptr->data = value;
ptr->next = NULL;

if (head!= NULL)
{
	while (temp->next != head)
		temp = temp->next;
 temp->next = ptr;
	ptr->next = head;
	head = ptr;
}
else{
	ptr->next = ptr;
	head = ptr;
}
}

void insert2(int value)
{
struct node *ptr = NULL,*temp = head; 
ptr = new(struct node);
ptr->data = value;
//ptr->next = NULL;
if (head!= NULL)
{
	while (temp->next != head)
		temp = temp->next;
	temp->next = ptr;
	ptr->next = head;		
}
else
	cout<<"NULL";
}
void delete1()
{
struct node *a,*temp = head;
if (head!= NULL)
{
while (temp->next!= head)
{
		a = temp;
		temp = temp->next;
}

	
temp->next = head->next;
head = head->next;
}
else
	cout<<"Empty";	
}
void display()
{
	struct node *temp = head;
	if (temp == NULL)
		cout<<"Empty List";
		
	else{
	do
	{
		cout<<temp->data<<"-->";
		temp = temp->next;
	}while (temp!= head);

		cout<<"-------------->"<<head->data<<endl;	
	}
	
}

void split()
{
	cout<<"H1"<<endl;
	struct node *fast,*slow,*head2;
	cout<<"H1"<<endl;
	fast = slow = head;
	head2 = NULL;
	cout<<"H1"<<endl;
	while (fast->next != head  || fast->next->next != head)
	{	
		fast = fast->next->next;
		slow = slow->next;
	}
	cout<<"H1"<<endl;
	if (fast->next = head)
	{
		fast->next = slow->next;
		head2 = slow->next;
		slow->next = head;
		cout<<"Hiks"<<endl;
	}
	else if (fast->next->next = head)
	{	cout<<"Helses"<<endl;
		fast->next->next = slow->next;
		head2 = slow->next;
		slow->next = head;
	}
	cout<<"H3"<<endl;	
	struct node *temp;
	temp = head;
	cout<<"List 1  ::";
	while (temp->next != head)
	{
		cout<<temp->data<<"--->";
		temp=temp->next;
	}
	cout<<endl;
	temp = head2;
	cout<<"List 2  ::";
	while (temp->next != head2)
	{
		cout<<temp->data<<"-->";
		temp = temp->next;
	}
	
	
}

main()
{

	insert1(5);
	display();
	insert1(4);
	display();
	insert1(3);
	display();
	insert1(2);
	display();
	insert1(1);
	display();
	insert2(6);
	display();	
	insert2(7);
	display();	
	insert2(8);
	display();
//	delete1();
//	display();
//	delete1();
//	display();
	split();

}
