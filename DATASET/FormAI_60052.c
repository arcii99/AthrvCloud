//FormAI DATASET v1.0 Category: Mailing list manager ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_LIST_LENGTH 1000

/* Define a struct for storing each contact */
typedef struct contact_t {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

/* Main function to run the mailing list manager */
int main() {
    /* Declare variables */
    int numContacts = 0;
    contact contacts[MAX_LIST_LENGTH];
    int choice;

    /* Loop through until user exits */
    while (1) {
        /* Display menu */
        printf("Mailing List Manager\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. View all contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        /* Get user input */
        scanf("%d", &choice);

        /* Take action based on user choice */
        switch (choice) {
        case 1:
            addContact(&numContacts, contacts);
            break;
        case 2:
            removeContact(&numContacts, contacts);
            break;
        case 3:
            viewContacts(numContacts, contacts);
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice, please try again.\n");
            break;
        }
    }

    return 0;
}

/* Function to add a new contact */
void addContact(int *numContacts, contact contacts[]) {
    /* Check if list is full */
    if (*numContacts == MAX_LIST_LENGTH) {
        printf("Error: List is full.\n");
        return;
    }

    /* Get new contact information */
    printf("Enter name: ");
    scanf("%s", contacts[*numContacts].name);
    printf("Enter email: ");
    scanf("%s", contacts[*numContacts].email);

    /* Increment contact count */
    (*numContacts)++;
}

/* Function to remove a contact */
void removeContact(int *numContacts, contact contacts[]) {
    /* Check if list is empty */
    if (*numContacts == 0) {
        printf("Error: List is empty.\n");
        return;
    }

    /* Get contact to remove */
    printf("Enter name to remove: ");
    char nameToRemove[MAX_NAME_LENGTH];
    scanf("%s", nameToRemove);

    /* Find contact in list */
    int i;
    for (i = 0; i < *numContacts; i++) {
        if (strcmp(contacts[i].name, nameToRemove) == 0) {
            /* Shift all contacts after this one back by one */
            int j;
            for (j = i + 1; j < *numContacts; j++) {
                contacts[j - 1] = contacts[j];
            }
            /* Decrement contact count */
            (*numContacts)--;
            /* Print success message and return */
            printf("Contact removed successfully.\n");
            return;
        }
    }

    /* Contact not found */
    printf("Error: Contact not found.\n");
}

/* Function to view all contacts */
void viewContacts(int numContacts, contact contacts[]) {
    /* Check if list is empty */
    if (numContacts == 0) {
        printf("List is empty.\n");
    }

    /* Display all contacts */
    int i;
    for (i = 0; i < numContacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Email: %s\n", contacts[i].email);
    }
}