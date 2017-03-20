/*
Write a menu driven program to perform insert and delete operations in a circular linked list.
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct list
{
	int info;
	struct list *link;
};
typedef struct list node;

void insert(node *,int);
void erase(node*, int);
void display(node*, node*);

void main(){
	node *start;
	int ch,info;
	clrscr();

	start = (node*) malloc(sizeof(node)); // create first node
	start->link = start;

	while(1){
		printf("\n1.INSERT");
		printf("\n2.ERASE");
		printf("\n3.DISPLAY");
		printf("\n0.EXIT");
		printf("\n\nENTER YOUR CHOICE: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:	printf("\nEnter the element you want to insert: ");
					scanf("%d",&info);
					insert(start,info);
					break;
			case 2:	printf("\nEnter the element you want to delete: ");
					scanf("%d",&info);
					erase(start,info);
					break;
			case 3:	printf("\nThe List is:\n");
					display(start,start->link);
					break;
			case 0:	exit(1);
			default:printf("\nWrong Answer, Try Again");
		}
		getch();
	}
}

void insert(node * ptr,int info){
	node *newnode, *start = ptr;
	while(ptr->link != start)
		ptr = ptr->link; /* move ptr to last node and make it points to start i.e let the order be  start .... ptr->start, so it's circular LL */

	newnode = (node*) malloc(sizeof(node));
	newnode->info = info;
	newnode->link = start;
	ptr->link = newnode;
}
void erase(node *start,int item){
	node *prev,*ptr=start;
	while(ptr->link != start && ptr->info != item){
		prev=ptr;
		ptr=ptr->link;
	}
	if( ptr->info != item){
		printf("\nElement not in List");
		return;
	}
	prev->link=ptr->link;
	free(ptr);
}
void display(node *start, node* ptr){
	if(ptr == start)
		return;
	else
	{
		printf("\t%d",ptr->info);
		display(start,ptr->link);
	}
}