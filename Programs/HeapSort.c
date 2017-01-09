			/*HEAP SORTING*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
void sort(int a[],int &size)				//to sort the array
			    				//a is the array
			 			           //size is the number of items inserted
{
	int i;
	i=size;
	int temp;
	while(i!=0)
	{
		if(a[i]<a[i/2])
		{
			temp=a[i];
			a[i]=a[i/2];
			a[i/2]=temp;
		}
		i=i/2;
	}
}
void disp(int b[],int &value,int i,int level)                     //to print the heap tree
{
	int j;
	if(2*i+1<=value)
		disp(b,value,2*i+1,level+1);
	printf("\n\n");
	for(j=0;j<=level;j++)
		printf(" \t ");
	printf("%d",b[i]);
	if(2*i<=value)
		disp(b,value,2*i,level+1);
}

void out(int a[],int &size) 				//to arrange the inserted array
			    				//a is the array
			   				 //size is the number of items inserted
{
	int i=1;
	int temp;
	while(((2*i)+1)<=size || 2*i<=size)
	{

		if(a[2*i]>a[2*i+1])
		{
			if(a[i]>a[(2*i)+1])
			{
				temp=a[i];
				a[i]=a[i*2+1];
				a[i*2+1]=temp;
				i=((2*i)+1);
			}
			else
			i=size;
		}
		else
		{
			if(a[i]>a[2*i])
			{
				temp=a[i];
				a[i]=a[i*2];
				a[i*2]=temp;
				i=(2*i);
			}
			else
			i=size;
		}
	}
}
void get(int a[],int &size) 				 //to get the array
			   				 //a is the array
			  			             //size is the number of items inserted
{
	int i=0,x;
	printf("Enter the no. of items going to be entered\n");
	scanf("%d",&x);
	printf("Enter the items :\n");
	if(x==1)
	{
		scanf("%d",&a[size+1]);
		size++;
		sort(a,size);
	}
	else
	{
		while(i<=x-1)
		{
			size++;
			scanf("%d",&a[size]);
			sort(a,size);
			i++;
		}
	}
}
void display(int a[],int size,int d[],int &top)		//to sort the array
							//a is the array
					 		//size is the number of items inserted
							//d is the array with the sorted numbers
							//top is the size of d
{
	//int i=1,x;
	while(size!=0)
	{
		top++;
		d[top]=a[1];
		a[1]=a[size];
		//i++;
		size--;
		out(a,size);

		//i++;
	}
}
void max(int a[],int size,int d[],int &top)		 //to sort the array in descending order
							//a is the array
							 //size is the number of items inserted
							//d is the array with the sorted numbers
							//top is the size of d
{
	int i;
	display(a,size,d,top);
	i=top;
	while(i!=0)
	{
		printf("%d ",d[i]);
		i--;
	}
}
void main()
{
	clrscr();
	int a[100],d[100],b[100],c[100];
	int size=0,top=0,value=0;
	int ch,j;
	int i=1;
	do
	{
		clrscr();
		printf("\t\t\tHEAP SORTING\n\n");
		printf("1.Enter new set of numbers\n\n2.Sort in ascending order\n\n”);
printf(“3.Sort in descending order\n\n");
		printf("4.Tree\n\n5.Exit\nChoose any one of the above :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				size=0;
				top=0;
				get(a,size);
				value=size;
				while(i<=size)
				{
					b[i]=a[i];
					c[i]=a[i];
					i++;
				}
				display(a,size,d,top);
				break;
			case 2:
				if(size==0 && top==0)
					printf("Please enter the numbers and then sort them\n");
				else
				{
					printf("The ascending order is :\n");
					//top=0;

					j=1;
					while(j<=top)
					{
						printf("%d ",d[j]);
						j++;
					}
				}
				break;
			case 3:
				if(top==0 && size==0)
					printf("Please enter the numbers and then sort them\n");
				else
				{
					printf("The descending order is :\n");
					j=top;
					while(j!=0)
					{
						printf("%d ",d[j]);
						j--;
					}
				}
				break;
			case 4:
				if(top==0 && size==0)
					printf("Please enter the numbers them diaplay\n");
				else
				disp(c,value,1,1);
				break;
			case 5:
				printf("Thank you very much\n");
				break;
			default:
				printf("Choose any one from the given list\n");
				break;
		}
		getch();
	}while(ch!=5);
}




                