#include<stdio.h>
#define max 5
int q[max];
int top=-1;
void insert();
int pop();
int peek();
void display();
int val;
int main()
{
	int choice;
	do
	{
		printf("\n*******MENU*******\n");
		printf("ENTER YOUR CHOICE\n ");
		printf("1-INSERT\n 2-POP\n 3-PEEK\n 4-DISPLAY\n 5-EXIT\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				val=pop();
				if(val!=-1)
				{
				printf("DELETED ELEMENT IS %d\n",val);
			    }
			    else
			    {
			    	printf("STACK IS EMPTY\n");
				}
				break;
			case 3:
			    val=peek();
			    if(val!=-1)
			    {
			    	printf("TOP MOST ELEMENT IS %d\n",val);
				}
				else
				{
					printf("STACK IS EMPTY\n");
				}
				break;
			case 4:
			    display();	
		}
	}while(choice!=5);
	return 0;
}

void insert()
{
	if(top==max-1)
	{
		printf("STACK IS OVERFLOW\n");
	}
	else
	{
		if(top==-1)
		{
			top++;
		}
		printf("ENTER THE NUMBER YOU WANT TO ENTER\n");
		scanf("%d",&val);
		q[top]=val;
		top++;
	}
}

int pop()
{
	if(top==-1)
	{
		printf("STACK IS IN UNDERFLOW CONDITION\n");
		return -1;	
	}
	else
	{
		val=q[top];
		top--;
		return 0;
	}
}

int peek()
{
	if(top==-1)
	{
		printf("STACK IS IN UNDERFLOW CONDITION\n");
		return -1;
	}
	else
	{
		return q[top];
	}
}

void display()
{
	int i;
	if(top==-1)
	{
		printf("STACK IS IN UNDERFLOW CONDITION\n");
	}
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("q[%d]=%d\n",i,q[i]);
		}
	}
}


