/*
 * C++ Program to Implement Singly Linked List
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
/*
 * Node Declaration
 */
struct node
{
    int info;
    struct node *next;
}*start;
node *create_node(int value)
{
    struct node *temp;
    temp = new(struct node); 
    if (temp == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else
    {
        temp->info = value;
        temp->next = NULL;     
        return temp;
    }
}
struct node *insert_last(struct node *start,int value)
{

    struct node *p;
    p = create_node(value);
	struct node *temp = start;
	if (temp->next == NULL)
	{
		p->next = NULL;
		temp->next = p;
	}
	else{
	
	while( temp->next != NULL){
		temp = temp->next;
	}
	p->next = NULL;
	temp->next = p;
	}
	return start;
	
}
struct node *merger(node *a, node *b)
{
	struct node *temp,*k;
	k = temp = NULL;
	
		if (a->info < b->info)
		{
		temp = a;
		k = temp;
		temp->next = NULL;
		a = a->next;
		cout<"He";
		}
		else
		{
		temp = b;
		k = temp;
		temp->next = NULL;
		b = b->next;
		}
		
	while ((a != NULL) || (b != NULL))
	{
		if (a->info < b->info)
		{
			temp->next = a;
			temp = temp->next;
			a = a->next;
		}
		else
		{
			temp->next = b;
			temp = temp->next;
			b = b->next;
		}
	}
	if (a != NULL)
		temp->next = a;
	else
		temp->next = b;
	

	return temp;	
}
void display(struct node *start)
{
    struct node *temp;
    if (start == NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    temp = start;
    cout<<"Elements: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->info<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
 
main()
{

struct node *a = NULL;
a = create_node(1);
struct node * b = NULL;
b = create_node(2);
a = insert_last(a,3);
a = insert_last(a,5);
a = insert_last(a,7);
b = insert_last(b,4);
b = insert_last(b,6);
b = insert_last(b,8);
b = insert_last(b,10);
b = insert_last(b,12);
cout<<"List a ";
display(a);
cout<<"List b ";
display(b);
struct node *m = merger(a,b);
display(m);

}
