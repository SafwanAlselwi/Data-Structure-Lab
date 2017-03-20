/* by Assaad
Write a menu driven program to perform operations on a circular queue (linked list implementation).
*/
#include<stdio.h>
#include<stdlib.h>

struct list
{
	int info;
	struct list *link;
};
typedef struct list node;

node *front=NULL,*rear=NULL;

void inQ(){
	node *newnode;
	int n;
	newnode=(node *)malloc(sizeof(node));
	printf("\nEnter a number to Inqueue: ");
	scanf("%d",&n);
	newnode->info=n;
	newnode->link=NULL;
	if(front==NULL)
		front=newnode;
	else
		rear->link=newnode;

	rear = newnode;
	rear->link = front;
}

void deQ(){
	node *ptr;
	if(front==rear){
		free(front);
		front=NULL;
		rear=NULL;
	}
	else{
		ptr = front;
		front = front->link;
		rear->link = front;
		free(ptr);
	}
}

void display(void){
	node *ptr;
	int i;
	if(front==NULL)
		printf("\nEmpty Queue");
	else{
		printf("\nC.Queue is -->> ");
		ptr=front;
		printf("\t%d",ptr->info);
		ptr = ptr->link;
		while(ptr!=front){
		    printf("\t%d",ptr->info);
		    ptr = ptr->link;
		}
    }
}

void main(){
	int n,ch;
	clrscr();
	printf("\n\n\t\tC.I.R.C.U.L.A.R  Q.U.E.U.E");
	while(1){
		printf("\n1.Inqueue");
		printf("\n2.Dequeue");
		printf("\n3.Display");
		printf("\n0.Exit");
		printf("\n\nEnter Your Choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				inQ();
				display();
				break;

			case 2:
				if(front == NULL)
					printf("\nUNDERFLOW\n");
				else
					deQ();
					display();
					break;
			case 3: display();
					break;
			case 0: exit(0);
			default: printf("Wrong Choice\n");
		}//end of switch
		getch();
	}// end of while
}// end of main
