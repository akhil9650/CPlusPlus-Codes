#include<iostream>
using namespace std;

const int SIZE = 50;

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
	char gettop()
	{
		return top;
	}
};

struct node
{
    int info;
    struct node *next;
}*head1,*head2;

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

struct node *insert_begin(struct node *start, int value)
{


	struct node *temp = NULL;
	temp = create_node(value);
	if (start == NULL)
		{
		start = temp;
		start->next = NULL;
		}
	else
	{
	struct node *p = start;
	temp->next = p;
	start = temp;
	}
	return start;
}

/*
 * Display Elements of a link list
 */
void display(struct node *start)
{
    struct node *temp;
    if (start == NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    temp = start;
    cout<<"Elements of list are: "<<endl;
    while (temp != NULL)
    {
        cout<<temp->info<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void checkMerge(node *a, node *b)
{
	Stack s1,s2;
	struct node *temp;
	temp = a;
	int p,q,r;
	while (temp->next != NULL)
	{	cout<<"Pushing into 1 ----"<<temp->info<<endl;
		s1.push(temp->info);
		temp = temp->next;
	}
	cout<<endl;
	temp = b;
	while (temp->next != NULL)
	{
		cout<<"Pushing into 2 ----"<<temp->info<<endl;
		s2.push(temp->info);
		temp = temp->next;
	}


	p = s1.pop();
	q = s2.pop();


	while (p==q)
	{
		r = p;
		p = s1.pop();
		q = s2.pop();
	}
	

	cout<<"Lists merge at"<<r;	
}

main()
{
	head1 = head2 = NULL;
	head1 = insert_begin(head1,10);
	head1 = insert_begin(head1,9);
	head1 = insert_begin(head1,8);
	head1 = insert_begin(head1,7);
	head1 = insert_begin(head1,6);
	head1 = insert_begin(head1,6777);
	head1 = insert_begin(head1,5);
	head1 = insert_begin(head1,4);
	head1 = insert_begin(head1,3);
	head1 = insert_begin(head1,2);
	head1 = insert_begin(head1,1);
	head1 = insert_begin(head1,0);
	display(head1);
	head2 = insert_begin(head2,10);
	head2 = insert_begin(head2,9);
	head2 = insert_begin(head2,8);
	head2 = insert_begin(head2,7);
	head2 = insert_begin(head2,6);
	head2 = insert_begin(head2,5);
	head2 = insert_begin(head2,4);
	head2 = insert_begin(head2,3);
	head2 = insert_begin(head2,66);
	display(head2);
	checkMerge(head1,head2);

}
