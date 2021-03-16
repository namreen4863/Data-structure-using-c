#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_af(struct node *);
struct node *insert_bef(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_af(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *sort_list(struct node *);
int val;

int main()
{
	int choice;
	do
	{
		printf("\n*************MAIN MENU****************\n");
		printf("SELECT THE OPRATION YOU WANT TO PERFORM\n");
		printf("1-CREATE LIST\n");
		printf("2-INSERT THE ELEMENT IN BEG\n");
		printf("3-INSERT ELEMENT IN THE END\n");
		printf("4-INSERT ELEMENT AFTER\n");
		printf("5-INSERT ELEMENT BEFORE\n");
		printf("6-DELETE ELEMENT AT THE BEG\n");
		printf("7-DELETE ELEMENT AFTER\n");
		printf("8-DELETE ELEMENT AT THE END\n");
		printf("9-DELETE NODE\n");
		printf("10-DISPLAY\n");
		printf("11-SORT LIST\n");
		printf("12-TO EXIT\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			start = create_ll(start);
			printf("LINKED LIST CREATED\n");
			break;

		case 2:
			start = insert_beg(start);
			break;

		case 3:
			start = insert_end(start);
			break;

		case 4:
			start = insert_af(start);
			break;

		case 5:
			start = insert_bef(start);
			break;

		case 6:
			start = delete_beg(start);
			break;

		case 7:
			start = delete_af(start);
			break;

		case 8:
			start = delete_end(start);
			break;

		case 9:
			start = delete_node(start);
			break;

		case 10:
			start = display(start);
			break;
			
		case 11:
		    start = sort_list(start);
			break;	
		}
	} while (choice != 12);

	return 0;
}

struct node *create_ll(struct node *start)
{
	struct node *ptr, *new_node;
	int num;
	printf("ENTER -1 TO EXIT\n");
	printf("ENTER THE NUMBER\n");
	scanf("%d", &num);
	while (num != -1)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->data = num;
		if (start == NULL)
		{
			new_node->next = NULL;
			start = new_node;
		}
		else
		{
			ptr = start;
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = new_node;
			new_node->next = NULL;
		}
		printf("ENTER THE NUMBER\n");
		scanf("%d", &num);
	}
	return start;
}

struct node *insert_beg(struct node *start)
{
	struct node *ptr, *new_node;
	ptr = start;
	int num;
	if (start == NULL)
	{
		create_ll(start);
	}
	else
	{
		printf("ENTER THE NUMBER\n");
		scanf("%d", &num);
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->next = start;
		new_node->data = num;
		start = new_node;
		return start;
	}
}

struct node *insert_end(struct node *start)
{
	struct node *ptr, *new_node;
	ptr = start;
	int num;
	if (start == NULL)
	{
		create_ll(start);
	}
	else
	{
		printf("ENTER THE NUMBER\n");
		scanf("%d", &num);
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->data = num;
		new_node->next = NULL;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = new_node;
		return start;
	}
}

struct node *insert_af(struct node *start)
{
	struct node *ptr, *new_node, *preptr;
	int num;
	ptr = start;
	preptr = ptr;
	new_node = (struct node *)malloc(sizeof(struct node));
	if (start == NULL)
	{
		create_ll(start);
	}
	else
	{
		printf("ENTER THE NUMBER\n");
		scanf("%d", &val);
		printf("ENTER THE NUMBER YOU WANT TO PLACE AFTER %d\n", val);
		scanf("%d", &num);
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->data = num;
		while (preptr->data != val)
		{
			preptr = ptr;
			ptr = ptr->next;
		}
		preptr->next = new_node;
		new_node->next = ptr;
		return start;
	}
}

struct node *insert_bef(struct node *start)
{
	struct node *ptr, *preptr, *new_node;
	ptr = start;
	preptr=ptr;
	int num, val;
	if (start == NULL)
	{
		create_ll(start);
	}
	else
	{
		printf("ENTER THE NUMBER\n");
		scanf("%d", &val);
		printf("ENTER THE NUMBER YOU WANT TO PLACE BEFORE %d\n",val);
		scanf("%d", &num);
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->data = num;
		if (ptr->data == val)
		{
			insert_beg(start);
		}
		else
		{
			while (ptr->data != val)
			{
				preptr = ptr;
				ptr = ptr->next;
			}
			preptr->next = new_node;
			new_node->next = ptr;
		}
	}
	return start;
}

struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr = start;
	start = ptr->next;
	free(ptr);
	return start;
}

struct node *delete_end(struct node *start)
{
	struct node *ptr, *preptr;
	ptr = start;
	while (ptr->next != NULL)
	{
		preptr = ptr;
		ptr = ptr->next;
	}
	free(ptr);
	preptr->next = NULL;
	return start;
}

struct node *delete_node(struct node *start)
{
	struct node *ptr, *preptr;
	int num;
	printf("ENTER THE ELEMENT\n");
	scanf("%d", &num);
	ptr = start;
	if (ptr->next == NULL)
	{
		start = delete_end(start);
	}
	else if (ptr->data == num)
	{
		start = delete_beg(start);
	}
	else
	{
		while (ptr->data != num)
		{
			preptr = ptr;
			ptr = ptr->next;
		}
		preptr->next = ptr->next;
		free(ptr);
		return start;
	}
}

struct node *delete_af(struct node *start)
{
	struct node *ptr, *preptr;
	int num;
	ptr = start;
	preptr = start;
	printf("ENTER THE ELEMENT YOU WANT TO DELETE AFTER\n");
	scanf("%d", &num);
	while (preptr->data != num)
	{
		preptr = ptr;
		ptr = ptr->next;
	}
	preptr->next = ptr->next;
	free(ptr);
	return start;
}

struct node *display(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
	return start;
}

struct node *sort_list(struct node *start)
{
	struct node *ptr1,*ptr2;
	int temp;
	ptr1=start;
	while(ptr1->next!=NULL)
	{
		ptr2=ptr1->next;
		while(ptr2!=NULL)
		{
			if(ptr1->data > ptr2->data)
			{
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
	return start;
}
