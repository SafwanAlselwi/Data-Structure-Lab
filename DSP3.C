/*
Write a menu driven program to create a linked list and to perform insert and delete operations.
*/
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<alloc.h>
struct list
{
	int info;
	struct list *link;
};
typedef struct list node;

node *create();
void display(node *);

node *insert_beg(node *);
node *insert_after(node *);
node *insert_end(node *);

node *del_beg(node *);
node *del_k_node(node *);
node *del_last(node *);

void main(){
	node *start = NULL;
	int ch;
	clrscr();
	while(1){
		printf("\n1.CREATE LINKED LIST");
		printf("\n2.DISPLAY DATA");
		printf("\n3.INSERTION AT FRONT");
		printf("\n4.INSERTION AFTER");
		printf("\n5.INSERTION AT END");
		printf("\n6.DELETE FROM FRONT");
		printf("\n7.DELETE FROM K POSITION");
		printf("\n8.DELETE LAST");
		printf("\n0.EXIT");
		printf("\n\nENTER YOUR CHOICE: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:	start=create();				break;
			case 2:	display(start);				break;
			case 3:	start=insert_beg(start);	break;
			case 4:	start=insert_after(start);	break;
			case 5:	start=insert_end(start);	break;
			case 6:	start=del_beg(start);		break;
			case 7:	start=del_k_node(start);	break;
			case 8:	start=del_last(start);		break;
			case 0:	exit(1);
			default: printf("\nWrong Answer, Try Again");
		}
		getch();
	}
}

node *create(){
	node *start,*ptr,*newnode;
	int i,x;
	for(i=1;;i++)
	{
		printf("\nEnter the node value or Enter -1 to Exit: ");
		scanf("%d",&x);
		if(x==-1)
			break;
		newnode=(node *)malloc(sizeof(node));
		newnode->info=x;
		newnode->link=NULL;
		if(i==1)
		{
			start=newnode;
			ptr = newnode;
		}
		else
		{
			ptr->link=newnode;
			ptr=newnode;
		}
	}
	return start;
}

void display(node *start){
	node *ptr=start;
	if(ptr==NULL)
		printf("\nList is empty: ");
	else
	{
		while(ptr!=NULL)
		{
			printf("\t%d",ptr->info);
			ptr=ptr->link;
		}
	}
}

node *insert_beg(node *start){
	node *newnode;
	int x;
	newnode=(node *)malloc(sizeof(node));
	printf("\n\nEnter the value of the new node: ");
	scanf("%d",&x);
	newnode->info=x;
	newnode->link=start;
	start=newnode;
	return start;
}

node *insert_end(node *start){
	node *newnode,*ptr=start;
	int x;
	newnode=(node *)malloc(sizeof(node));
	printf("\nEnter the new node value: ");
	scanf("%d",&x);
	newnode->info=x;
	newnode->link=NULL;

	while(ptr->link != NULL)
		ptr=ptr->link; //ptr will points to NULL

	ptr->link=newnode; // nodes will be as :  Prev->newnode
	return start;
}

node *insert_after(node *start){
	node *newnode,*prev,*ptr=start;
	int n,x;
	printf("\nEnter the order of node after which you want to insert: ");
	scanf("%d",&n);
	while(ptr!=NULL && n>0){// n>1 in delete_k_node & n>0 in insert_after
		prev=ptr;
		ptr=ptr->link;
		n--;
	}
	newnode=(node *)malloc(sizeof(node));
	printf("\n\nEnter the value for new node: ");
	scanf("%d",&x);
	newnode->info=x;
	newnode->link=ptr;
	prev->link=newnode; // nodes will be as :  Prev->newnode->ptr
	return start;
}

node *del_beg(node *start){
	node *ptr;
	if(start==NULL)
		printf("LIST IS EMPTY");
	else
	{
		ptr=start;
		start=start->link;
		free(ptr);
	}
	return start;
}

node *del_last(node *start){
	node *prev,*ptr=start;
	while(ptr->link != NULL){
		prev=ptr;
		ptr=ptr->link; //ptr will points to last node, prev will points to the node before last
	}
	prev->link=NULL; // remove link with last node
	free(ptr);      // free last node from memory
	return start;
}
node *del_k_node(node *start){
	int n;
	node *prev,*ptr=start;
	printf("\nENTER THE ORDER OF NODE YOU WANT TO DELETE: ");
	scanf("%d",&n);

	while(ptr!=NULL && n>1){ // n>1 in delete_k_node & n>0 in insert_after
		prev=ptr;
		ptr=ptr->link;
		n--;
	}
	prev->link=ptr->link; //If we have Node A->B->C in order then Node A points to Node C, deleting node B. i.e A->C
	free(ptr);
	return start;
}