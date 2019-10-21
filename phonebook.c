#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phone_entry {
    char name[256];
    char number[256];
    struct phone_entry *next;
};

#define MAX_ENTRIES 50000

struct phone_entry entries[MAX_ENTRIES];
struct phone_entry *head = NULL;
struct phone_entry *tail = NULL;
struct phone_entry* search(char name[]);

void insert_to_phonebook_linkedlist() {
    struct phone_entry *entry = (struct phone_entry *)malloc(sizeof(struct phone_entry));
    printf("Name:\n");
    scanf("%s",entry->name);

    printf("Number:\n");
    scanf("%d",&entry->number);


    entry->next = NULL;

    if (head == NULL) {
        head = entry;
        tail = entry;
    } 
	else
	{
	
        tail->next = entry;
        tail = entry;
    }
}

void list_phonebook_linkedlist() {
    struct phone_entry *tmp = head;
    printf("\nEntries of the phonebook:\n");
    while (tmp->next=!NULL) {
        printf("Name: %s\n", tmp->name);
        printf("Number: %d\n\n", tmp->number);
        tmp = tmp->next;
    }
}

void delete_from_phonebook_linkedlist() {
    char name[1024];
    struct phone_entry *temp, *prev;
   /* if(head==NULL)
    {
    	printf("Contact list is empty\n");
	}*/

    printf("\nEnter the contact name you want to delete:\n");
    scanf("%s",name);
    temp=search(name);
   if(temp==NULL)
   {
   	printf("\n ** Contact name not found**");
   }
   else if(head->name==name)
   {
   	head=head->next;
   	free(temp);
   	printf("\n **Contct Successfully deleted");
   }
   else
   {
   	while(prev->next!=temp)
   	{
   		prev=prev->next;
	}
   	prev=temp->next;
   	free(prev);
   	printf("\n ** Contact Successfully deleted");
   }
	

  /*  tmp = head;
    prev = NULL;
    while (tmp) {
        if (!strcmp(tmp->name, name)) {            
            if (!tmp->next) {
                tail = prev;
            }
            if (prev) {
                prev->next = tmp->next;
            } else {
                head = tmp->next;
            }
            free(tmp);
            printf("Successfully deleted %s\n", name);
            break;
        }
        prev = tmp;
        tmp = tmp->next;
    }*/
}
struct phone_entry *search(char name[])
{
	struct phone_entry *ptr;
	struct phone_entry *ad=NULL;
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->name==name)
		{
			return ptr;
		}
		ptr=ptr->next;
	}
	
	return ad;
}

int main() {
    int choice;
    char tmp[1024];

    while (1) {
        printf("1. Create new entry\n");
        printf("2. List entries\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("Your choice: \n");
        scanf("%d",&choice);

        switch (choice) {
            case 1: {

                insert_to_phonebook_linkedlist();
                break;
            }
            case 2: {          
                list_phonebook_linkedlist();
                break;
            }
            case 3:{
                delete_from_phonebook_linkedlist();             
                break;
            }
            case 4: {
                return 0;
                break;
            }
        }
    }

    return 0;
}

