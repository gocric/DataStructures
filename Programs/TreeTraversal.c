/*TRAVERSAL  IN A TREE*/
#include<iostream.h>
#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define n NULL
typedef struct tree tree;
typedef struct tree position;
struct tree
{
	char item;
	struct tree *right;
	struct tree *left;
};

void all(tree *&t)//to allocate memory for a tree
{
	t=(tree*)malloc(sizeof(tree));
	t->right=n;
	t->left=n;
}
void create(tree *&t)//to create a tree
{
	t=n;
}
void intrav(tree *t)
{
	if(t->left!=n)
		intrav(t->left);
	printf("%c",t->item);
	if(t->right!=n)
		intrav(t->right);
}
void posttrav(tree *t)
{
	if(t->left!=n)
		posttrav(t->left);
	if(t->right!=n)
		posttrav(t->right);
	printf("%c",t->item);
}
void pretrav(tree *t)
{
	printf("%c",t->item);
	if(t->left!=n)
		pretrav(t->left);
	if(t->right!=n)
		pretrav(t->right);
}
void insert(tree *&t,char x)
{
	char x1,x2;
	tree *newnode,*newnode1;
	all(newnode);
	all(newnode1);
	printf("Enter the left of %c :",x);
	scanf("%c",&x2);
	x2=getchar();
	newnode1->item=x2;
	t->left=newnode1;
	printf("Enter the right of %c :",x);
	scanf("%c",&x1);
	x1=getchar();
	newnode->item=x1;
	t->right=newnode;
	if(t->left->item=='*' || '^'|| '/' || '-'|| '+')
	{
			insert(t->left,x2);
	}
	if(t->right->item=='*' ||’^' ||'/' || '-'|| '+' )
	{
		insert(t->right,x1);
	}
}
void main()
{
	clrscr();
	struct tree *t;
	tree *tr;
	all(tr);
	t=n;
	int i;
	char x;
	do
	{
		clrscr();
		printf("\t\t\tEXPRESSION TREE EXECUTION\n");
		printf("\t\t\t########## #### #########\n\n");
		printf("  MENU\n\n");
		printf("1.Create a tree\n2.Insert the tree\n");
		printf("3.Perform Inorder traversal\n4.Perform postorder traversal\n”);
printf(“5.Perform Preorder traversal\n6.Exit");
		printf("\nChoose anyone of the above ");
		scanf("%d",&i);
		switch(i)
		{
		       case 1:
				create(t);
				printf("Tree  Created\n");
				break;
		       case 2:
				printf("Enter the root node:");
				scanf("%c",&x);
				x=getchar();
				tr->item=x;
				t=tr;
				insert(t,x);
				break;
		       case 3:
				if(t==n)
					printf("Tree is empty.cannot traverse\n");
				else
				{
					printf("The inorder expression is :\n");
					intrav(t);
				}
				break;
		       case 4:
				if(t==n)
					printf("Tree is empty.cannot travrse\n");
				else
				{
					printf("The postorder expression is :\n");
					posttrav(t);
				}
				break;
		       case 5:
				if(t==n)
					printf("Tree is empty.cannot traverse\n");
				else
				{
					printf("The preorder expression is :\n");
					pretrav(t);
				}
				break;
		       case 6:
				printf("Thank you for verifying my program\n");
				break;
		       default:
				printf("Choose any one of the above options only\n");
				break;
		}
		printf("\n");
		getch();
	}while(i!=6);
}

