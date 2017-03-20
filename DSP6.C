/* By Raf
Write a menu driven program to perform operations on stack.(Linked List implementation)
HINT: PUSH new node at the beginning of list and POP node also from the beginning, so STACK CONCEPTS are used
*/
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct list
{
	int info;
	struct list *link;
};
typedef struct list node;

node *push(node *);
node *pop(node*);
void display(node *);

void main(){
	int ch;
	node *start=NULL;
	clrscr();
	do{
		getch();
		clrscr();
		printf("\nS.T.A.C.K   O.P.E.R.A.T.I.O.N.S");
		printf("\n1. Display");
		printf("\n2. PUSH");
		printf("\n3. POP");
		printf("\n0. Exit");
		printf("\n\tEnter choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				display(start);
				break;
			case 2:
				start=push(start);
				break;
			case 3:
				start=pop(start);
				break;
			case 0:	exit(0);
			default:printf("\nWrong Choice!!, Try agian");
		}
	}while(ch!=0);
	getch();
}
node *push(node *start){
	node *newnode;
	int x;
	newnode=(node *)malloc(sizeof(node));
	printf("\n\tEnter the value to PUSH:");
	scanf("%d",&x);
	newnode->info=x;
	newnode->link=start;
	start=newnode;
	return start;
}
node *pop(node *start){
	node *ptr=start;
	if(ptr==NULL)
		printf("\n\tSTACK is EMPTY!");
	else{
		start=start->link;
		printf("\n\tPoped value is : %d",ptr->info);
		free(ptr);
	}
	return start;
}
void display(node *start){
	node *ptr=start;
	if(ptr==NULL)
		printf("\STACK is EMPTY: ");
	else
	{
		while(ptr!=NULL)
		{
			printf("\t%d",ptr->info);
			ptr=ptr->link;
		}
	}
}