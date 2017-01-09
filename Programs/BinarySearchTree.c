		/*IMPLEMENTATION OF BINARY SEARCH TREE*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define n NULL
typedef struct tree tree;
typedef struct tree position;
struct tree
{
	int item;
	struct tree *right;
	struct tree *left;
};
void all(tree *&t)//to allocate memory for a tree
{
	t=(tree*)malloc(sizeof(tree));
}
void create(tree *&t)//to create a tree
{
	t=n;
}
void insert(tree *&t,int element)//to insert an itme in the tree
{
	tree *newnode,*traverse,*prev;
	int error=0;
	traverse=t;
	all(newnode);
	newnode->item=element;
	newnode->right=n;
	newnode->left=n;
	if(t==n)
	{
		t=newnode;
		printf("Item Inserted\n");
	}
	else
	{
		while(traverse!=n && error!=1)
		{
			if(element>traverse->item)
			{
				prev=traverse;
				traverse=traverse->right;
			}
			else if(element<traverse->item)
			{
				prev=traverse;
				traverse=traverse->left;
			}
			else
			{
				printf("Item is already present..cant duplicate\n");
				error=1;
			}
		}
		if(error!=1)
		{
			if(element>prev->item)
				prev->right=newnode;
			else
				prev->left=newnode;
			printf("Item Inserted\n");
		}
	}
}
void display(tree *&t,int l)//to display the tree
{
	int i;
	if(t!=n)
	{
		for(i=0;i<=l+12;i++)
			printf(" ");
		printf("%d\n\n",t->item);
		display(t->left,l-7);
		display(t->right,l+7);
	}
}
void del(tree *&t,int element)//to delete an item
{
	tree *temp,*prev,*deep,*prev1,*prev2;
	prev=n;
	if(t==n)
		printf("Tree empty.....cant delete any item\n");
	else
	{
		temp=t;
		while(temp->item!=element && temp!=n)
		{
			if(temp->item<element)
			{
				prev=temp;
				temp=temp->right;
			}
			if(temp->item>element)
			{
				prev=temp;
				temp=temp->left;
			}
		}
		if(temp==n)
			printf("No such itemfound\n");
		else
		{
			if(prev==n)
			{
				if(temp->right==n && temp->left==n)
					t=n;
				else if(temp->right==n && temp->left!=n)
					t=temp->left;
				else if(temp->left==n && temp->right!=n)
					t=temp->right;
				else
				{
					prev1=temp;
					deep=temp->right;
					if(deep->left==n)
					{
						deep->left=temp->left;
						t=deep;
					}
					else
					{
					while(deep->left!=n)
					{
						prev2=prev1;
						prev1=deep;
						deep=deep->left;
					}
					deep->right=temp->right;
					deep->left=temp->left;					prev2->left=n;
					prev1->left=n;
					t=deep;
					}
				}
			}
			else if(temp->right==n && temp->left==n)
			{
				if(prev->item<element)
				{
					prev->right=n;
				}
				else if(prev->item>element)
				{
					prev->left=n;
				}
			}
			else if(temp->right==n || temp->left==n)
			{
				if(temp->right==n)
				{
					if(prev->left==temp)
						prev->left=temp->left;
					else
						prev->right=temp->left;
				}
				else
				{
					if(prev->left==temp)
						prev->left=temp->right;
					else
						prev->right=temp->right;
				}
			}
			else
			{
				deep=temp;
				deep=deep->right;
				while(deep!=n)
				{
					prev1=deep;
					deep=prev->left;
				}
				deep->right=temp->right;
				deep->left=temp->left;
				prev1->left=n;
				if(prev->left==temp)
					prev->left=deep;
				else
					prev->right=deep;

			}
			printf("Item Deleted \n");
			free(temp);
		}

	}
}
void search(tree *&t)//to search for an item
{
	tree *temp;
	int element;
	temp=t;
	printf("Enter the item to b searched ");
	scanf("%d",&element);
	while(temp!=n && temp->item!=element)
	{
		if(temp->item<element)
			temp=temp->right;
		else if(temp->item>element)
			temp=temp->left;
	}
	if(temp==n)
		printf("Sorry..item no found\n");
	else
	{
		if(temp->right!=n && temp->left!=n)
			printf("Item %d is found with %d to its left and %d to its right \n",temp->item,temp->left->item,temp->right->item);
		else if(temp->right==n && temp->left!=n)
			printf("Item %d is found with %d to its left and no item to its right \n",temp->item,temp->left->item);
		else if(temp->right!=n && temp->left==n)
			printf("Item %d is found with no element to its left and %d to its right \n",temp->item,temp->right->item);
		else if(temp->right==n && temp->left==n)
			printf("Item %d is found as the leaf node \n",temp->item,temp->left->item);
	}
}
void finmax(tree *&t)//to find the maximum value
{
	tree *temp,*prev;
	temp=t;
	if(t==n)
		printf("Sorry.tree is empty.cant find maximun in this\n");
	else
	{
		while(temp!=n)
		{
			prev=temp;
			temp=temp->right;
		}
		printf("The maximun item in the tree is %d \n",prev->item);
	}
}
void finmin(tree *&t)//to find the minimum value
{
	tree *temp,*prev;
	temp=t;
	if(t==n)
		printf("Sorry.tree is empty.cant find minimun in this\n");
	else
	{
		while(temp!=n)
		{
			prev=temp;
			temp=temp->left;
		}
		printf("The minimun item in the tree is %d \n",prev->item);
	}
}

void main()
{
	clrscr();
	struct tree *t;
	t=n;
	int i,element;
	do
	{
		clrscr();
		printf("\t\t\tTREE EXECUTION\n");
		printf("\t\t\t#### #########\n\n");
		printf("  MENU\n\n");
		printf("1.Create a tree\n\n2.Insert an item\n\n3.Delete an item\n\n4.Search for an item\n\n5.Display the tree");
		printf("\n\n6.Find the maximun item\n\n7.Find the minimum number\n\n8.Exit\n");
		printf("\nChoose anyone of the above ");
		scanf("%d",&i);
		switch(i)
		{
		       case 1:
				create(t);
				printf("Tree  Created\n");
				break;
		       case 2:
				printf("Enter the item to be inserted\n");
				scanf("%d",&element);
				insert(t,element);
				break;
		       case 3:
				if(t==n)
					printf("Sorry.tree is empty.cant delete in this\n");
				else
				{
					printf("Enter the item to be deleted ");
					scanf("%d",&element);
					del(t,element);
				}
				break;
		       case 4:
				if(t==n)
					printf("Sorry.tree is empty.cant search in this\n");
				else
					search(t);
				break;
		       case 5:
				if(t==n)
					printf("Tree is empty.cant display any item\n");
				else
					display(t,27);
				break;
		       case 7:
				finmin(t);
				break;
		       case 6:
				finmax(t);
				break;
		       case 8:
				printf("Thank you for verifying my program\n");
				break;
		       default:
				printf("Choose any one of the above options only\n");
				break;
		}
		printf("\n");
		getch();
	}while(i!=8);
}
















		/*IMPLEMENTATION OF BINARY SEARCH TREE*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define n NULL
typedef struct tree tree;
typedef struct tree position;
struct tree
{
	int item;
	struct tree *right;
	struct tree *left;
};
void all(tree *&t)//to allocate memory for a tree
{
	t=(tree*)malloc(sizeof(tree));
}
void create(tree *&t)//to create a tree
{
	t=n;
}
void insert(tree *&t,int element)//to insert an itme in the tree
{
	tree *newnode,*traverse,*prev;
	int error=0;
	traverse=t;
	all(newnode);
	newnode->item=element;
	newnode->right=n;
	newnode->left=n;
	if(t==n)
	{
		t=newnode;
		printf("Item Inserted\n");
	}
	else
	{
		while(traverse!=n && error!=1)
		{
			if(element>traverse->item)
			{
				prev=traverse;
				traverse=traverse->right;
			}
			else if(element<traverse->item)
			{
				prev=traverse;
				traverse=traverse->left;
			}
			else
			{
				printf("Item is already present..cant duplicate\n");
				error=1;
			}
		}
		if(error!=1)
		{
			if(element>prev->item)
				prev->right=newnode;
			else
				prev->left=newnode;
			printf("Item Inserted\n");
		}
	}
}
void display(tree *&t,int l)//to display the tree
{
	int i;
	if(t!=n)
	{
		for(i=0;i<=l+12;i++)
			printf(" ");
		printf("%d\n\n",t->item);
		display(t->left,l-7);
		display(t->right,l+7);
	}
}
void del(tree *&t,int element)//to delete an item
{
	tree *temp,*prev,*deep,*prev1,*prev2;
	prev=n;
	if(t==n)
		printf("Tree empty.....cant delete any item\n");
	else
	{
		temp=t;
		while(temp->item!=element && temp!=n)
		{
			if(temp->item<element)
			{
				prev=temp;
				temp=temp->right;
			}
			if(temp->item>element)
			{
				prev=temp;
				temp=temp->left;
			}
		}
		if(temp==n)
			printf("No such itemfound\n");
		else
		{
			if(prev==n)
			{
				if(temp->right==n && temp->left==n)
					t=n;
				else if(temp->right==n && temp->left!=n)
					t=temp->left;
				else if(temp->left==n && temp->right!=n)
					t=temp->right;
				else
				{
					prev1=temp;
					deep=temp->right;
					if(deep->left==n)
					{
						deep->left=temp->left;
						t=deep;
					}
					else
					{
					while(deep->left!=n)
					{
						prev2=prev1;
						prev1=deep;
						deep=deep->left;
					}
					deep->right=temp->right;
					deep->left=temp->left;					prev2->left=n;
					prev1->left=n;
					t=deep;
					}
				}
			}
			else if(temp->right==n && temp->left==n)
			{
				if(prev->item<element)
				{
					prev->right=n;
				}
				else if(prev->item>element)
				{
					prev->left=n;
				}
			}
			else if(temp->right==n || temp->left==n)
			{
				if(temp->right==n)
				{
					if(prev->left==temp)
						prev->left=temp->left;
					else
						prev->right=temp->left;
				}
				else
				{
					if(prev->left==temp)
						prev->left=temp->right;
					else
						prev->right=temp->right;
				}
			}
			else
			{
				deep=temp;
				deep=deep->right;
				while(deep!=n)
				{
					prev1=deep;
					deep=prev->left;
				}
				deep->right=temp->right;
				deep->left=temp->left;
				prev1->left=n;
				if(prev->left==temp)
					prev->left=deep;
				else
					prev->right=deep;

			}
			printf("Item Deleted \n");
			free(temp);
		}

	}
}
void search(tree *&t)//to search for an item
{
	tree *temp;
	int element;
	temp=t;
	printf("Enter the item to b searched ");
	scanf("%d",&element);
	while(temp!=n && temp->item!=element)
	{
		if(temp->item<element)
			temp=temp->right;
		else if(temp->item>element)
			temp=temp->left;
	}
	if(temp==n)
		printf("Sorry..item no found\n");
	else
	{
		if(temp->right!=n && temp->left!=n)
			printf("Item %d is found with %d to its left and %d to its right \n",temp->item,temp->left->item,temp->right->item);
		else if(temp->right==n && temp->left!=n)
			printf("Item %d is found with %d to its left and no item to its right \n",temp->item,temp->left->item);
		else if(temp->right!=n && temp->left==n)
			printf("Item %d is found with no element to its left and %d to its right \n",temp->item,temp->right->item);
		else if(temp->right==n && temp->left==n)
			printf("Item %d is found as the leaf node \n",temp->item,temp->left->item);
	}
}
void finmax(tree *&t)//to find the maximum value
{
	tree *temp,*prev;
	temp=t;
	if(t==n)
		printf("Sorry.tree is empty.cant find maximun in this\n");
	else
	{
		while(temp!=n)
		{
			prev=temp;
			temp=temp->right;
		}
		printf("The maximun item in the tree is %d \n",prev->item);
	}
}
void finmin(tree *&t)//to find the minimum value
{
	tree *temp,*prev;
	temp=t;
	if(t==n)
		printf("Sorry.tree is empty.cant find minimun in this\n");
	else
	{
		while(temp!=n)
		{
			prev=temp;
			temp=temp->left;
		}
		printf("The minimun item in the tree is %d \n",prev->item);
	}
}

void main()
{
	clrscr();
	struct tree *t;
	t=n;
	int i,element;
	do
	{
		clrscr();
		printf("\t\t\tTREE EXECUTION\n");
		printf("\t\t\t#### #########\n\n");
		printf("  MENU\n\n");
		printf("1.Create a tree\n\n2.Insert an item\n\n3.Delete an item\n\n4.Search for an item\n\n5.Display the tree");
		printf("\n\n6.Find the maximun item\n\n7.Find the minimum number\n\n8.Exit\n");
		printf("\nChoose anyone of the above ");
		scanf("%d",&i);
		switch(i)
		{
		       case 1:
				create(t);
				printf("Tree  Created\n");
				break;
		       case 2:
				printf("Enter the item to be inserted\n");
				scanf("%d",&element);
				insert(t,element);
				break;
		       case 3:
				if(t==n)
					printf("Sorry.tree is empty.cant delete in this\n");
				else
				{
					printf("Enter the item to be deleted ");
					scanf("%d",&element);
					del(t,element);
				}
				break;
		       case 4:
				if(t==n)
					printf("Sorry.tree is empty.cant search in this\n");
				else
					search(t);
				break;
		       case 5:
				if(t==n)
					printf("Tree is empty.cant display any item\n");
				else
					display(t,27);
				break;
		       case 7:
				finmin(t);
				break;
		       case 6:
				finmax(t);
				break;
		       case 8:
				printf("Thank you for verifying my program\n");
				break;
		       default:
				printf("Choose any one of the above options only\n");
				break;
		}
		printf("\n");
		getch();
	}while(i!=8);
}




















