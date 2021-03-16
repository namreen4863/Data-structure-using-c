#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
int val;
struct node *top = NULL;
struct node *push(struct node *);
struct node *pop(struct node *);
int peek(struct node *);
struct node *display(struct node *);

int main()
{
	int choice;
	do
	{
		printf("ENTER YOUR CHOICE\n");
		printf("\n***********MENU************\n");
		printf("1-PUSH\n2-POP\n3-PEAK\n4-DISPLAY\n");
		printf("ENTER 5 TO EXIT\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			    top=push(top);
			    break;
			case 2:
			    top=pop(top);
			    break;
			case 3:
			    val=peek(top);
			    if(val==-1)
			    {
			    	printf("STACK IS EMPTY\n");
			    }
			    else
			    {
				 printf("TOP MOST ELEMENT IS : %d\n",val);
			    }
			    break;
			case 4:
			    top=display(top);
			    break;	
		}
	}while(choice!=5);
	return 0;
}

struct node *push(struct node *top)
{
	int val1;
	struct node *ptr,*new_node;
	ptr=top;
	printf("ENTER THE VALUE TO BE ENTERED\n");
	scanf("%d",&val1);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=val1;
        if(top==NULL)
	{
		new_node->next=NULL;
		top=new_node;
		return top;
	}
	else
        {
    	        new_node->next=top;
    	        top=new_node;
	        return top;
	}	
}

int peek(struct node *top)
{
	if(top==NULL)
	{
        return -1;
	}
	else
	{
		return top->data;
	}
}

struct node *pop(struct node *top)
{
	struct node *ptr;
	ptr=top;
	if(top==NULL)
	{
		printf("UNDERFLOW CONDITION\n");
		return top;
	}
	else
	{
		top=top->next;
		printf("DELETED ELEMENT IS : %d",ptr->data);
		free(ptr);
		return top;
	}
}

struct node *display(struct node *top)
{
	struct node *ptr;
	ptr=top;
	if(top==NULL)
	{
		printf("STACK IS EMPTY\n");
		return top;
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}
		return top;
	}
}
