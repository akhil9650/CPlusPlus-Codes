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

main()
{
	Stack s;
	string str;
	cout<<"Enter elements :: ";
	getline(cin,str);
	int n = str.length();
	int i,flag;
	i = flag = 0;

		while (str[i] != 'X')
		{
			s.push(str[i]);
			i++;	
		}
		for (int j = 0 ; j<i ; j++)
		{
			if (s.pop() != str[i+j+1])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			cout<<"Pal";
		else
			cout<<"Not pal";
	}
		
	

