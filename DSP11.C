/* Checked and modified by: Raf
Write a program to convert the given infix expression into its postfix form.
*/
#include<stdio.h>

void intopost(char[],char[]);
int G(char);
int F(char);
int top= -1;

void main()
{       
	char infix[20],postfix[20];
	clrscr();
	printf("\n Enter a valid infix expression: ");
	scanf("%s",infix);
	intopost(infix,postfix);
	printf("\n postfix expression is: %s",postfix);
	getch();
}

int G(char symbol)
{       
	switch(symbol)
	{       
		case '+': case '-': return(1);
		case '*': case '/': return(3);
		case '^': case '$': return(6);
		case '(': 			return(9);
		case ')': 			return(0);
		default:  			return(7);
	}
}

int F(char symbol)
{       
	switch(symbol)
	{       
		case '+': case '-': return(2);
		case '*': case '/': return(4);
		case '^': case '$': return(5);
		case '(': 			return(0);
		case '#': 			return(-1);
		default : 			return(8);
	}
}

void intopost(char infix[],char postfix[]){       
	int i,p=0;
	char s[30],symbol;
	s[++top]='#';
	for(i=0 ; i<strlen(infix) ; i++)
	{	
		symbol=infix[i];
		while( F(s[top]) > G(symbol) )
			postfix[p++]=s[top--];
		if( F(s[top]) != G(symbol) )
			s[++top]=symbol;
		else
			top--;
	}
	while(s[top]!='#')
	     postfix[p++]=s[top--];

	postfix[p]='\0';
}