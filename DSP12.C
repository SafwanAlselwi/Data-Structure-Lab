/*
Write a program to evaluate the postfix expression with a set of values.
*/
#include <ctype.h>

int s[100];
int top=-1;

void push(int item){
	s[++top] = item; printf("\n%d",item);
}
int pop(){
	return(s[top--]);
}

void main()
{
	char pofx[100],ch;
	int i=0,op1,op2;
	clrscr();
	printf("\nWrite a Postfix Expression : ");
	scanf("%s",pofx);
	while( (ch=pofx[i++]) != '\0')
	{
		if(isdigit(ch)) /* Operand, Push the operand */
			push(ch-'0');
		else /* Operator,pop two  operands */
		{
			op2=pop();
			op1=pop();
			switch(ch)
			{
				case '+': push(op1+op2);	break;
				case '-': push(op1-op2);	break;
				case '*': push(op1*op2);	break;
				case '/': push(op1/op2);	break;
				default : printf("\nInvalid Operation");
			}
		}
	}
	printf("\nGiven Postfix : %s",pofx);
	printf("\nResult After Evaluation: %d",s[top]);
	getch();
}