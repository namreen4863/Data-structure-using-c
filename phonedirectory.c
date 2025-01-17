#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phone_entry
{
    char name[256];
    char number[256];
    struct phone_entry *next;
};

#define MAX_ENTRIES 50000

struct phone_entry entries[MAX_ENTRIES];
struct phone_entry *head = NULL;
struct phone_entry *tail = NULL;
int search(char name[]);

void insert_to_phonebook_linkedlist()
{
    int temp;
    struct phone_entry *entry = (struct phone_entry *)malloc(sizeof(struct phone_entry));
    printf("Name:\n");
    scanf("%s", &entry->name);

    printf("Number:\n");
    scanf("%d", &entry->number);

    entry->next = NULL;

    if (head == NULL)
    {
        head = entry;
        tail = entry;
    }

    else
    {
        temp = search(entry->name);
        if (temp == -1)
        {
            printf("\n\tThis name is already present\n");
        }
        else
        {
            tail->next = entry;
            tail = entry;
        }
    }
}

void list_phonebook_linkedlist()
{
    struct phone_entry *tmp = head;
    if (tmp == NULL)
    {
        printf("\n\tNo entries to display\n");
    }
    else
    {
        printf("\nEntries of the phonebook:\n");
        while (tmp != NULL)
        {
            printf("\n\tName: %s\n", tmp->name);
            printf("\tNumber: %d\n\n", tmp->number);
            tmp = tmp->next;
        }
    }
}

void delete_from_phonebook_linkedlist()
{
    char name[1024];
    struct phone_entry *prev, *ptr;
    int temp;

    if (head == NULL)
    {
        printf("\n\tContact list is empty\n");
    }
    else
    {
        printf("\nEnter the contact name you want to delete:\n");
        scanf("%s", &name);
        ptr = head;

        temp = search(name);
        if (temp == 0)
        {
            printf("\n\t ** Contact not found **\n");
        }

        else if (strcmp(head->name, name) == 0)
        {
            head = head->next;
            free(ptr);
            printf("\n\t **Contact Successfully deleted **\n");
        }
        else
        {
            while (strcmp(ptr->name, name) != 0)
            {
                prev = ptr;
                ptr = ptr->next;
            }
            prev->next = ptr->next;
            free(ptr);
            printf("\n ** Contact Successfully deleted **\n");
        }
    }
}
int search(char name[])
{
    struct phone_entry *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(ptr->name, name) == 0)
        {
            return -1;
        }
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        return 0;
    }
}

int main()
{
    int choice;
    char tmp[1024];

    while (1)
    {
        printf("\n1. Create new entry\n");
        printf("2. List entries\n");
        printf("3. Delete entry\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {

            insert_to_phonebook_linkedlist();
            break;
        }
        case 2:
        {
            list_phonebook_linkedlist();
            break;
        }
        case 3:
        {
            delete_from_phonebook_linkedlist();
            break;
        }
        case 4:
        {
            return 0;
            break;
        }
        }
    }

    return 0;
}
