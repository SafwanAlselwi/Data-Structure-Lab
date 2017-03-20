/*
Write a menu driven program to create Binary Tree and perform insert and delete operations.
*/
#include<stdio.h>
#include<conio.h>
struct tree
{
	struct tree *left;
	int info;
	struct tree *right;
};
typedef struct tree node;

void insert(node **root,int item)
{
	if(*root==NULL)
	{
		*root = (node *)malloc(sizeof(node));
		(*root)->left = NULL;
		(*root)->info=item;
		(*root)->right = NULL;
		return;
	}
	else
	{
		if(item<(*root)->info)
			insert(&((*root)->left),item);
		else
			insert(&((*root)->right),item);
		return;
	}
}

void delete_tree(node **root,int item)
{
	node *ptr,*back,*temp;

	if(*root==NULL){
		   printf("\nEmpty tree");
		   return;
	}
	else
	{
		ptr=*root;
		back=ptr;
		while(ptr->info != item)
		{
			back=ptr;
			if(item<ptr->info)
				ptr=ptr->left;
			else
				ptr=ptr->right;
		}
		if(ptr->left!=NULL && ptr->right!=NULL){
			temp=ptr->right;
			while(temp->left!=NULL)
			{
				back=temp;
				temp=temp->left;
			}
			ptr->info=temp->info;
			ptr=temp;
		}
		if(ptr->left==NULL && ptr->right==NULL){
			if(back->right==ptr)
				back->right=NULL;
			else
				back->left=NULL;
			
			free(ptr);
			return;
		}
		if(ptr->left==NULL && ptr->right!=NULL){
			if(back->left==ptr)
				back->left=ptr->right;
			else
				back->right=ptr->right;

			free(ptr);
			return;
		}
		if(ptr->left!=NULL && ptr->right==NULL){
			if(back->left==ptr)
				back->left=ptr->left;
			else
				back->right=ptr->left;

			free(ptr);
			return;
		}

	}
}

void preorder(node *root){
	node *ptr=root;
	if(ptr!=NULL)
	{
	   printf(" %d ",ptr->info);
	   preorder(ptr->left);
	   preorder(ptr->right);
	}
	else return;
}

void main()
{
	node *root=NULL;
	int item,ch;
	clrscr();
	printf("\n.B.I.N.A.R.Y. .T.R.E.E. .O.P.E.R.A.T.I.O.N.S.");
	getch();
	do{
		printf("\n1.Insert");
		printf("\n2.Delete");
		printf("\n3.Preorder  Traversal");
		printf("\n0.Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: 
				while(1){
					printf("\nEnter the element to be inserted, or enter -1 to exit:  ");
					scanf("%d",&item);
					if(item ==-1) break;
					insert(&root,item);
				}
				break;
			case 2:
				printf("\nEnter the element to be deleted :   ");
				scanf("%d",&item);
				delete_tree(&root,item);
				break;
			case 3:
				printf("\nPreorder  Traversal:  ");
				preorder(root);
				break;
			case 0: exit(0);
			default: printf("\nWrong Choice ,, Try Again ");
		}
		fflush(stdin);
	}while(ch!=0);
}