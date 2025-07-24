//FormAI DATASET v1.0 Category: Phone Book ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char address[100];
    char phone_number[15];
};

void add_contact(struct contact *phonebook, int *size)
{
    printf("Enter name: ");
    scanf("%49s", phonebook[*size].name);
    printf("Enter address: ");
    scanf("%99s", phonebook[*size].address);
    printf("Enter phone number: ");
    scanf("%14s", phonebook[*size].phone_number);

    (*size)++;
}

void view_contacts(struct contact *phonebook, int size)
{
    if(size == 0){
        printf("No contacts found.\n");
        return;
    }
    printf("Contacts:\n");
    for(int i=0; i<size; i++){
        printf("%s: %s, %s\n", phonebook[i].name, phonebook[i].address, phonebook[i].phone_number);
    }
}

void search_contacts(struct contact *phonebook, int size, char *name)
{
    for(int i=0; i<size; i++){
        if(strcmp(phonebook[i].name, name) == 0){
            printf("%s: %s, %s\n", phonebook[i].name, phonebook[i].address, phonebook[i].phone_number);
            return;
        }
    }
    printf("Contact not found.\n");
}

int main()
{
    struct contact phonebook[100];
    int size = 0;
    int choice;
    char name[50];

    printf("Welcome to your phone book!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add contact\n");
        printf("2. View contacts\n");
        printf("3. Search contact\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_contact(phonebook, &size);
                break;
            case 2:
                view_contacts(phonebook, size);
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%49s", name);
                search_contacts(phonebook, size, name);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;

        }
    } while(choice != 4);

    return 0;
}