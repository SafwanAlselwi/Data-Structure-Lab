/*
Write a program to add two polynomiaals using a linked list.
*/
# include <stdio.h>
# include <malloc.h>

struct list
{
	float coef;
	int expo;
	struct list *link;
};
typedef struct list node;

node *poly_add(node *,node *);
node *enter(node *);
node *insert(node *,float,int);

void main(){
	node *p1_start=NULL,*p2_start=NULL,*p3_start=NULL;

	clrscr();

	printf("\n1st Polynomial :\n");
	p1_start=enter(p1_start);

	printf("\n2nd Polynomial :\n");
	p2_start=enter(p2_start);

	p3_start = poly_add(p1_start,p2_start);
	printf("Polynomial 1 is : ");
	display(p1_start);
	printf("Polynomial 2 is : ");
	display(p2_start);
	printf("Added polynomial is : ");
	display(p3_start);

	getch();
}/*End of main()*/

node *enter(node *start){
	int i,n,ex;
	float co;
	printf("\nHow many terms u want to enter : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("\nEnter coeficient for term %d : ",i);
		scanf("%f",&co);
		printf("Enter exponent for term %d     : ",i);
		scanf("%d",&ex);
		start=insert(start,co,ex);
	}
	return start;
}/*End of enter*/

node *insert(node *start,float co,int ex){
	node *ptr,*tmp;
	tmp = (node *)malloc(sizeof(node));
	tmp->coef = co;
	tmp->expo = ex;

	/*list empty or exp greater than first one */
	if(start==NULL || tmp->expo > start->expo)
	{
		tmp->link = start;
		start=tmp;
	}
	else
	{
		ptr=start;
		while(ptr->link!=NULL && ptr->link->expo > tmp->expo) //insert new node in order
			ptr = ptr->link;

		tmp->link = ptr->link;
		ptr->link = tmp;

		//if(ptr->link==NULL) /*item to be added in the end */
			//tmp->link=NULL;
	}
	return start;
}/*End of insert*/


display(node *ptr){
	if(ptr==NULL){
		printf("Empty\n");
		return;
	}
	while(ptr!=NULL){
		printf("(%.1fx^%d) + ", ptr->coef,ptr->expo);
		ptr=ptr->link;
	}
	printf("\b\b \n");
	/* \b\b to erase the last + sign */
	return;
}/*End of display()*/

node *poly_add(node *p1,node *p2){
	node *p3_start,*p3,*tmp;
	p3_start=NULL;
	if(p1==NULL && p2==NULL) //if no equations then return
		return p3_start;

	while(p1!=NULL && p2!=NULL ){
		tmp=(node *)malloc(sizeof(node));
		if(p3_start==NULL){
			p3_start=tmp;
			p3=p3_start;
		}
		else{
			p3->link=tmp;
			p3=p3->link;
		}


		if(p1->expo > p2->expo){
			tmp->coef=p1->coef;
			tmp->expo=p1->expo;
			p1=p1->link;
		}
		else if(p2->expo > p1->expo){
			tmp->coef=p2->coef;
			tmp->expo=p2->expo;
			p2=p2->link;
		}
		else if(p1->expo == p2->expo){
			tmp->coef=p1->coef + p2->coef;	// sum the coefficeint of both polynomial that have the same exponenet
			tmp->expo=p1->expo; // tmp->expo=p2->expo; // both same
			p1=p1->link;
			p2=p2->link;
		}
	}/*End of while*/

	while(p1!=NULL){
		tmp=(node *)malloc(sizeof(node));
		tmp->coef=p1->coef;
		tmp->expo=p1->expo;
		if (p3_start==NULL) /*poly 2 is empty*/
		{
			p3_start=tmp;
			p3=p3_start;
		}
		else
		{
			p3->link=tmp;
			p3=p3->link;
		}
		p1=p1->link;
	}/*End of while */

	while(p2!=NULL){
		tmp=(node *) malloc(sizeof(node));
		tmp->coef=p2->coef;
		tmp->expo=p2->expo;
		if (p3_start==NULL) /*poly 1 is empty*/
		{
			p3_start=tmp;
			p3=p3_start;
		}
		else
		{
			p3->link=tmp;
			p3=p3->link;
		}
		p2=p2->link;
	}/*End of while*/

	p3->link=NULL; // link the last node p3 to null
	//tmp->link=NULL; // same as above as p3 and tmp point to last node
	return p3_start;
}/*End of poly_add() */