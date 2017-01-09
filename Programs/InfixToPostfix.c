		/*PROGRAM FOR INFIX TO POSTFIX CONVERSION*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int n=0;
char c[100];
void sprior(char a,int &i)				//it gives the stack priority of the character
			  				//a is the character
						            //i is the priority
{
	if(a=='*')
		i=2;
	else if(a== '/')
		i=2;
	else if(a=='+')
		i=1;
	else if(a=='-')
		i=1;
	else if(a=='(')
		i=0;
	else if(a=='#')
		i=0;

}
void iprior(char a,int &i)				//it gives the infix priority of the character
			  				//a is the character
						            //i is the priority
{
	if(a=='*')
		i=2;
	else if(a== '/')
		i=2;
	else if(a=='+')
		i=1;
	else if(a=='-')
		i=1;
	else if(a=='(')
		i=3;
	else if(a=='#')
		i=0;


}
void push(char s[],int &top,char x)			//it enters an item into the stack
							//s is the stack
				  		            //top is the posiiton of the last item
							//x is the item to be inserted
{		
	int i,j;
	sprior(s[top],i);
	iprior(x,j);
	if(i<j)
	{
		top++;
		s[top]=x;
	}
	else
	{
		while(i>=j)
		{
			c[n]=s[top];
			n++;
			top--;
			sprior(s[top],i);
			iprior(x,j);
		}
		top++;
		s[top]=x;
	}
}
void pop(char s[],int &top)			//it deletes an item from the stack
			  			 //s i the stack
			   			//top is the position of the last item of the stack
{
	while(s[top]!='(')
	{
		c[n]=s[top];
		n++;
		top--;
	}
	top--;
}
void convert(char a[])				    //it converts the infix to postfix expression
		   				   //a is the expression
{
	char s[100];
	int i=0,top=0;
	s[top]='#';
	while(a[i]!='#')
	{
		switch(a[i])
		{
			case '*':
				push(s,top,a[i]);
				break;
			case '/':
				push(s,top,a[i]);
				break;
			case '+':
				push(s,top,a[i]);
				break;
			case '-':
				push(s,top,a[i]);
				break;
			case '(':
				push(s,top,a[i]);
				break;
			case ')':
				pop(s,top);
				break;
			default:
				c[n]=a[i];
				n++;
				break;
		}
		i++;
	}
	while(s[top]!='#')
	{
		c[n]=s[top];
		n++;
		top--;
	}
	strcpy(a,c);
	printf("The postfix expression is :\n%s",a);
}
void input(char a[])					//it gets the expression to be verified
		  				            //s is the expression
{
	int l;
	printf("\t\t\tINFIX TO POSTFIX CONVERSION\n");
	printf("\nEnter the items of the expression:\n");
	scanf("%s",a);
	l=strlen(a);
	a[l]='#';
	convert(a);
}
void main()
{
	clrscr();
	char a[100];
	int i;
	do
	{
		input(a);
		getch();
		printf("\nEnter 1 to continue ...click anyother number to exit\n");
		scanf("%d",&i);
		getch();
	}while(i==1);
	printf("Thank you\n");
	getch();
}


