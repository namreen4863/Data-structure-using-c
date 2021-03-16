#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
void insert(void);
void display(void);
int peek(void);
int delete_elem(void);
int queue[MAX];
int front=-1;
int rear=-1;
int val;

int main()
{
	int choice;
	do
	{
		printf("\n******MAIN MENU******\n");
		printf("ENTER YOUR CHOICE\n");
		printf("1-INSERT\n2-DISPLAY\n3-DELETE\n4-PEAK\n5-EXIT\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;

			case 2:
				display();
				break;

			case 3:
				val=delete_elem();
				printf("DELETED ELEMENT IS %d\n",val);
				break;

			case 4:
				val=peek();
				if(val==-1)
				{
					break;
				}
				else
				{
					printf("TOP MOST ELEMENT IS:%d\n",val);
				    break;
				}
				
		}
	}while(choice!=5);
}

void insert(void)
{
	int num;
	printf("ENTER THE NUMBER YOU WANT TO ENTER\n");
	scanf("%d",&num);
	if(front==0&&rear==MAX-1)
	{
		printf("OVERFLOW CONDITION\n");
	}
	else if(front==-1&&rear==-1)
	{
		front=0;
		rear=0;
		queue[rear]=num;
	}
	else if(front!=0&&rear==MAX-1)
	{
		rear=0;
		queue[rear]=num;
	}
	else
	{
		rear++;
		queue[rear]=num;
	}
}

void display(void)
{
	int i;
	if(front==-1&&rear==-1)
	{
		printf("QUEUE IS EMPTY");
	}
	else
	{
		if(front<rear)
		{
			for(i=front;i<=rear;i++)
			{
				printf("queue[%d]=%d\n",i,queue[i]);
			}	
		}
		else
		{
			for(i=front;i<MAX;i++)
			{
				printf("queue[%d]=%d\n",i,queue[i]);
			}
			for(i=0;i<=rear;i++)
			{
				printf("queue[%d]=%d\n",i,queue[i]);
			}
		}
	}
}

int peek(void)
{ 
	if(front==-1&&rear==-1)
	{
		printf("QUEUE IS EMPTY\n");
		return -1;
	}
	else
	{
		return queue[front];
	}
}

int delete_elem(void)
{
	if(front==-1&&rear==-1)
	{
		printf("QUEUE IS EMPTY\n");
		return -1;
	}
	val=queue[front];
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
	    if(front==MAX-1)
		{
			front=0;
		}
		else
		{
			front++;
		}	
	}
	return val;
}
