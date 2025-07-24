//FormAI DATASET v1.0 Category: Mailing list manager ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_LIST_SIZE 100

// define contact struct
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

// define mailing list struct
typedef struct {
    Contact contacts[MAX_LIST_SIZE];
    int size;
} MailingList;

// function prototypes
void addContact(MailingList *list);
void displayList(MailingList list);

int main() {
    // create new mailing list
    MailingList myList;
    myList.size = 0;

    // display menu
    printf("Welcome to the Mailing List Manager!\n");
    printf("-------------------------------------\n");
    printf("1. Add Contact\n");
    printf("2. Display List\n");
    printf("3. Exit\n");

    // get user input
    int choice;
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // switch on user choice
        switch (choice) {
            case 1:
                addContact(&myList);
                break;
            case 2:
                displayList(myList);
                break;
            case 3:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

// function to add contact to mailing list
void addContact(MailingList *list) {
    // check if list is full
    if (list->size == MAX_LIST_SIZE) {
        printf("\nThe mailing list is full. Cannot add any more contacts.\n");
        return;
    }

    // create new contact struct
    Contact newContact;

    // get user input for name
    printf("\nEnter the contact's name: ");
    scanf("%s", newContact.name);

    // get user input for email
    printf("Enter the contact's email: ");
    scanf("%s", newContact.email);

    // add new contact to list
    list->contacts[list->size] = newContact;
    list->size++;

    // display success message
    printf("\nContact added successfully!\n");
}

// function to display mailing list
void displayList(MailingList list) {
    // check if list is empty
    if (list.size == 0) {
        printf("\nThe mailing list is empty.\n");
        return;
    }

    // display list header
    printf("\nMailing List:\n");
    printf("%-20s\t%-30s\n", "Name", "Email");
    printf("-----------------------------------------\n");

    // loop through contacts and display them
    for (int i = 0; i < list.size; i++) {
        printf("%-20s\t%-30s\n", list.contacts[i].name, list.contacts[i].email);
    }
}