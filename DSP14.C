/*
Write a menu driven program to create Binary Tree and perform inorder, preorder and postorder traversals.
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

void inorder(node *root){
	node *ptr=root;
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		printf(" %d ",ptr->info);
		inorder(ptr->right);
	}
	else return;
}

void postorder(node *root){
	node *ptr=root;
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf(" %d ",ptr->info);
	}
	else return;
}

void main()
{
	node *root=NULL;
	int item,ch;
	clrscr();
	printf("\n.B.I.N.A.R.Y. .T.R.E.E. .T.R.A.V.E.R.S.A.L.S.");
	getch();
	do{
		printf("\n1.Insert");
		printf("\n2.Preorder  Traversal");
		printf("\n3.Inorder   Traversal");
		printf("\n4.Postorder Traversal");
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
				printf("\nPreorder  Traversal:  ");
				preorder(root);
				break;
			case 3:
				printf("\nInorder    Traversal:  ");
				inorder(root);
				break;
			case 4:
				printf("\nPostorder  Traversal:  ");
				postorder(root);
				break;
			case 0: exit(0);
			default: printf("\nWrong Choice ,, Try Again ");
		}
		fflush(stdin);
	}while(ch!=0);
}