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

/*
 * Creating Node
 */
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
 
/*
 * Inserting element in beginning
 */
void insert_begin()
{
    int value;
    cout<<"Enter the value to be inserted: ";
    cin>>value;
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
	cout<<"Inserted";
}

 
/*
 * Inserting Node at last
 */
void insert_last()
{
    int value;
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    struct node *p;
    p = create_node(value);
	struct node *temp = start;
	while( temp->next != NULL){
		temp = temp->next;
	}
	p->next = NULL;
	temp->next = p;
	cout<<"Inserted";   
}
 
/*
 * Insertion of node at a given position
 */
void insert_pos()
{
    int value, pos, count = 0,k=0; 
    cout<<"Enter the value to be inserted: ";
    cin>>value;
    struct node *temp,*p,*t;
	p = create_node(value);
    cout<<"Enter the postion at which node to be inserted: ";
    cin>>pos;
	temp = start;
	if (start != NULL)
	{
			
	while (temp->next != NULL)
	{
		count++;
		temp = temp->next;
	}  
	}
	if ((pos-1)>count)
		{
		cout<<"Out of bounds"<<endl;
	}
	
	else if ( pos == 1 )
	{
		if (start == NULL)
		{
			start = p;
			start->next = NULL;
			cout<<"Kh";
		}
		else{
		
			temp = start;
			start = p;
			start->next = temp;
			cout<<"Inster";
			}
	}
	
	else 
	{
	temp = start;	
	while (k < (pos-1))
	{
	t=temp;
	temp = temp->next;
	k++;	
	}	
	t->next =p;
	p->next = temp;
	cout<<"D";
	}
	
}
 
/*
 * Sorting Link List
 */
void sort()
{
int value;
node *temp,*s;
temp = start;
if (start == NULL)
	cout<<"Empty List";
else {
	while (temp != NULL)
	{
		for (s = temp->next; s != NULL; s = s->next)
		{
			if (s->info < temp->info)
			{
				value = temp->info;
				temp->info = s->info;
				s->info = value;
			}
		}
	temp = temp->next;
	}
}
}
 
/*
 * Delete element at a given position
 */
void delete_pos()
{
    int pos, i,k,count;
	k = count = 0;
    node *temp,*s;
    temp = start;
    s = NULL;
    cout<<"Enter position of element to be deleted";
    cin>>pos;
    if (start == NULL)
    	cout<<"Empty List";
    else{
    	while(temp->next != NULL)
    	{
    		temp = temp->next;
    		count++;
		}
		if (pos > count)
			cout<<"Out of Bounds";
		else{
			temp = start;
			if (pos==1)
			{
				start = temp->next; 
			}
			else{
			
			while (k < (pos-1))
			{	s = temp;
				temp = temp->next;
				k++;
			}
		 s->next = temp->next;
		 cout<<"Deleted";
		 free(temp);
		}
    }
	}
    
    
}
 
/*
 * Update a given Node
 */
void update()
{
   int pos,value,count,k;
   k = count = 0;
   node *temp = start;
   cout<<"Enter position of node to be updated  ";
   cin>>pos;
   cout<<"Enter new value of node  ";
   cin>>value;
   
   if (start == NULL)
    	cout<<"Empty List";
    else{
    	while(temp->next != NULL)
    	{
    		temp = temp->next;
    		count++;
		}
		if (pos > count)
			cout<<"Out of Bounds";
		else{
			temp = start;

			
			while (k < (pos-1))
			{
				temp = temp->next;
				k++;
			}
			temp->info = value;
		
		}
    }

   
    cout<<"Node Updated"<<endl;
} 
 
/*
 * Searching an element
 */
void search()
{
	int value,flag = 0;
	struct node *temp;
	temp = start;
	cout<<"Enter value to be searched ";
	cin>>value;	
  while (temp->next != NULL)
  {
  	if (temp->info == value)
  	{
  		flag = 1;
  		break;
	  }
	else
	{
		temp = temp->next;
	}
  }
if (flag == 1)
	cout<<"Found in the list";
else
	cout<<"Not Found";
}
 
/*
 * Reverse Link List
 */
struct node *reverse()
{	struct node *curr,*prev,*nxt;
	curr = start;
	prev = nxt = NULL;
	if (start == NULL)
		cout<<"Empty List";
	

	else
	{
		while (curr != NULL)
		{
			nxt = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nxt;
		}
		start = prev;
	}
	return prev;
  }
  
/*
* Revese elements in pairs
*/
struct node *reversePairs()
{
	struct node *a,*b,*curr;
	curr = start;
	a = b = NULL;
	while (curr != NULL && curr->next != NULL)
	{
		if (a!= NULL)
		a->next->next = curr->next;
	
	a = curr->next;
	curr->next = curr->next->next;
	a->next = curr;
	
	if (b == NULL)
		b = a;
	
	curr = curr->next;
	}
	start = b;
	cout<<"Pairs Reversed";
}
  
/*
 * Display Elements of a link list
 */
void display()
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

void palindrome()
{
	int i = 0, count = 0, flag;
	struct node *a,*b,*temp;
	a = start;
	b = reverse();
	temp = b;
	  while (temp != NULL)
    {
        cout<<temp->info<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
	while (a->next != NULL)
	{
		if (a->info == b->info)
			{
			flag = 1;
			a = a->next;
			b = b->next;
			}
		else
		{
		cout<<"Break";
		flag = 0;
		break;	
		}
	}
	if (flag == 1)
		cout<<"Palindrome";
	else
		cout<<"Not Palindrome";
}

 
/*
 * Main :contains menu 
 */
main()
{
    int choice, nodes, element, position, i;
    start = NULL;
    while (1)
    {
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Operations on singly linked list"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1.Insert Node at beginning"<<endl;
        cout<<"2.Insert node at last"<<endl;
        cout<<"3.Insert node at position"<<endl;
        cout<<"4.Sort Link List"<<endl;
        cout<<"5.Delete a Particular Node"<<endl;
        cout<<"6.Update Node Value"<<endl;
        cout<<"7.Search Element"<<endl;
        cout<<"8.Display Linked List"<<endl;
        cout<<"9.Reverse Linked List "<<endl;
        cout<<"10.Reverse Linked List in pairs "<<endl;
        cout<<"11.Check for palindrome "<<endl;
		cout<<"12.Exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Inserting Node at Beginning: "<<endl;
            insert_begin();
            cout<<endl;
            break;
        case 2:
            cout<<"Inserting Node at Last: "<<endl;
            insert_last();
            cout<<endl;
            break;
        case 3:
            cout<<"Inserting Node at a given position:"<<endl;
            insert_pos();
            cout<<endl;
            break;
        case 4:
            cout<<"Sort Link List: "<<endl;
            sort();
            cout<<endl;
            break;
        case 5:
            cout<<"Delete a particular node: "<<endl;
            delete_pos();
            break;
        case 6:
            cout<<"Update Node Value:"<<endl;  
            update();
            cout<<endl;
            break;
        case 7:
            cout<<"Search element in Link List: "<<endl;
            search();
            cout<<endl;
            break;
        case 8:
            cout<<"Display elements of link list"<<endl;
            display();
            cout<<endl;
            break;
        case 9:
            cout<<"Reverse elements of Link List"<<endl;
            reverse();
            cout<<endl;
        case 10:
            cout<<"Reverse elements of Link List in pairs"<<endl;
            reversePairs();
            cout<<endl;
            break;
        case 11:
            cout<<"Checking for Palindrome"<<endl;
            palindrome();
            cout<<endl;
            break;
		case 12:
            cout<<"Exiting..."<<endl;
            exit(1);
            break;  
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}
 

