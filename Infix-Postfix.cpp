#include<iostream>
#include<ctype.h>
#include<string.h>
using namespace std;
const int SIZE = 50;

class Stack
{
private:
	
	char names[SIZE];
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
	
	void push(char &item)
	{
		top++; 
		names[top] = item;
	}
	
	char pop()
	{
		if(top <0)
	{
		cout<<"Empty";
		exit(1);
	}	
	else{
	char item;
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

 int precedance(char ch)
 {
 	if (ch == '^')
 		return 3;
 	else if (ch == '*' || ch == '/')
 		return 2;
 	else if (ch == '+'  || ch == '-')
 		return 1;
 	else
 		return 0;
 }
 
 main()
 {
 	Stack stack;
 	
 	string s;
 	char ch,cha;
 	cout<<"Enter string ::"<<endl;
 	getline(cin,s);;
 	int n = s.length();
 	for (int i = 0; i<n ; i++)
 	{
 		if (isalpha(s[i]) || isdigit(s[i]))
 			cout<<s[i];
 		else if (s[i] == '(')
 			{
			stack.push(s[i]);
			}
		else if (s[i] == ')')
	 	{	
	 		cha = stack.pop();
			while(cha != '('  || (stack.isEmpty()))
	 		{	
	 			cout<<cha<<" Bugs ";
				cha = stack.pop();
			}	
			}
		else if (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^')
			 {	
			 		if (stack.isEmpty() || stack.gettop() == '(')
						stack.push(s[i]);
					else
					{	
			 		ch = stack.pop();
				 	if (precedance(ch) > precedance(s[i]))
						cout<<ch;	
					else 
					{	
						stack.push(s[i]);
				 	}
					}
				 }
		 }
	 if (!stack.isEmpty())
	 {
 	while(!stack.isEmpty())
 		cout<<stack.pop();
	 }
 }
 
