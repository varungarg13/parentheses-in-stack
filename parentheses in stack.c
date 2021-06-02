#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define maxstk 5
typedef struct stack{
	int data[maxstk];
	int top;
}stack;
void push(stack *,char);
int pop(stack *);
void display(stack);
int main()
{
	int i;
	stack s1;
	int ch;
	s1.top=-1;
	char item[10]={"[{({})}]"};
	for(i=0;i<10;i++)
	{
		if(item[i]=='[' ||item[i]=='{' ||item[i]=='(')
		{
			push(&s1,item[i]);
		}	
	}
	display(s1);
	
	for(i=0;i<10;i++)
	{
		if(item[i]==']' && s1.data[s1.top]=='[' || item[i]=='}' && s1.data[s1.top]=='{' || item[i]==')' && s1.data[s1.top]=='(')
		{
			pop(&s1);
			display(s1);
		}
	}
	display(s1);
	
	
	return 0;
}
void push(stack *s1,char item)
{
	if(s1->top==maxstk-1)
	{
		printf("Overflow!");
		return;
	}
	
	
		s1->top++;
		s1->data[s1->top]=item;
	
}
int pop(stack *s1)
{
	int item;
	if(s1->top==-1)
	{
		printf("Underflow!");
		return -1;
	}
	else{
		item=s1->data[s1->top];
		s1->top--;
	}
	return item;
}

void display(stack s1){
	int i;
	if(s1.top==-1)
	{
		printf("\nStack is empty! and Equation is balanced \n");
		return;
	}
	
	printf("The stack is :\n");
	for(i=s1.top;i>=0;i--)
	{
		printf("%c\n",s1.data[i]);
	}
}







