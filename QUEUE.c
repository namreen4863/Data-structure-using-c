#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
int val;
int front=-1;
int rear=-1;
int q[MAX];
void insert();
int del();
int peek();
void display();
int main()
{
	int choice;
	
	do{
		printf("\n******MAIN MENU*******\n");
	        printf("1-INSERTION\n 2-DELETE\n 3-PEEK\n 4-DISPLAY\n 5-EXIT\n");
		printf("ENTER YOUR CHOICE: \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				
				insert();
				    break;
				case 2:
				    val=del();
				    if(val==-1)
				    {
				    	printf("QUEUE IS EMPTY\n");
					}
					else
					{
						printf("DELETED ELEMENT IS %d\n",val);
					}
				    break;
				case 3:
				    peek();
				    break;
				case 4:
				    display();
				    break;
				}
		}while(choice!=5);
}

void insert()
{
	printf("ENTER THE VALUE TO INSERT\n");
	scanf("%d",&val);
	if(rear==MAX-1)
	{
		printf("QUEUE IS FULL\n");
	}
	else if(front==-1&&rear==-1)
	{
		front=0;
		rear=0;
		q[rear]=val;
		rear++;
	}
	else
	{
		q[rear]=val;
		rear++;
	}
}

int del()
{
	if(front==-1||front>rear)
	{
		printf("QUEUE IS EMPTY\n");
		return -1;
	}
	else
	{
		val=q[front];
		front++;
		return val;
	}
}

int peek()
{
	if(front==-1||front>rear)
	{
		printf("QUEUE IS EMPTY\n");
		return -1;
	}
	else
	{
		return q[front];
	}
}

void display()
{
	int i;
	if(front==-1||front>rear)
	{
		printf("QUEUE IS EMPTY\n");
	}
	else
	{
		for(i=front;i<rear;i++)
		{
			printf("q[%d]:%d \n",i,q[i]);
		}
	}
}
