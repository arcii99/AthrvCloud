//FormAI DATASET v1.0 Category: Phone Book ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 30
#define MAX_PHONE_LEN 10
#define MAX_CONTACTS 10

// Define Contact struct
struct Contact {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
};

// Global variable to hold contact list
struct Contact contactList[MAX_CONTACTS];

// Function to add a contact
void addContact()
{
    char newName[MAX_NAME_LEN];
    char newPhone[MAX_PHONE_LEN];

    // Prompt for name
    printf("Enter name: ");
    scanf("%s", newName);

    // Prompt for phone number
    printf("Enter phone number: ");
    scanf("%s", newPhone);

    // Create new contact and add to contact list
    struct Contact newContact;
    strcpy(newContact.name, newName);
    strcpy(newContact.phone, newPhone);

    int i;
    for (i = 0; i < MAX_CONTACTS; i++) {
        if (strlen(contactList[i].name) == 0 && strlen(contactList[i].phone) == 0) {
            contactList[i] = newContact;
            printf("\nContact added successfully!\n\n");
            return;
        }
    }
    printf("\nContact list is full, cannot add new contact.\n\n");
}

// Function to display all contacts
void displayContacts()
{
    if (strlen(contactList[0].name) == 0 && strlen(contactList[0].phone) == 0) {
        printf("\nContact list is empty.\n\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    int i;
    for (i = 0; i < MAX_CONTACTS; i++) {
        if (strlen(contactList[i].name) != 0 && strlen(contactList[i].phone) != 0) {
            printf("%s, %s\n", contactList[i].name, contactList[i].phone);
        }
    }
    printf("\n");
}

// Function to search for a contact
void searchContact()
{
    char searchName[MAX_NAME_LEN];

    // Prompt for name to search for
    printf("\nEnter contact name to search for: ");
    scanf("%s", searchName);

    // Search for contact
    int i;
    for (i = 0; i < MAX_CONTACTS; i++) {
        if (strcmp(contactList[i].name, searchName) == 0) {
            printf("\n%s, %s\n\n", contactList[i].name, contactList[i].phone);
            return;
        }
    }
    printf("\nContact not found.\n\n");
}

int main(void)
{
    char choice;

    // Initialize contact list
    int i;
    for (i = 0; i < MAX_CONTACTS; i++) {
        contactList[i].name[0] = '\0';
        contactList[i].phone[0] = '\0';
    }

    // Main program loop
    while (1) {
        printf("Enter choice:\n");
        printf("1. Add a contact\n");
        printf("2. Display all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Exit\n");

        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addContact();
                break;
            case '2':
                displayContacts();
                break;
            case '3':
                searchContact();
                break;
            case '4':
                printf("\nGoodbye!\n\n");
                return 0;
            default:
                printf("\nInvalid choice, please try again.\n\n");
                break;
        }
    }
    return 0;
}