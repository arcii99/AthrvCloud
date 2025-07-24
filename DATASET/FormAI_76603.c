//FormAI DATASET v1.0 Category: Phone Book ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[20];
};

void addContact(struct Contact contacts[], int *numContacts);
void searchContacts(struct Contact contacts[], int numContacts, char query[]);
void printContacts(struct Contact contacts[], int numContacts);

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    char input[100];

    printf("Paranoid Phone Book - Enter 'help' for commands\n");

    while (1) {
        printf("> ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "help") == 0) {
            printf("Commands:\n");
            printf("add - add a contact to the phone book\n");
            printf("search - search for a contact in the phone book\n");
            printf("print - display all contacts in the phone book\n");
            printf("exit - exit the phone book\n");
        } else if (strcmp(input, "add") == 0) {
            addContact(contacts, &numContacts);
        } else if (strcmp(input, "search") == 0) {
            printf("Enter search query: ");
            fgets(input, 100, stdin);
            input[strcspn(input, "\n")] = 0;
            searchContacts(contacts, numContacts, input);
        } else if (strcmp(input, "print") == 0) {
            printContacts(contacts, numContacts);
        } else if (strcmp(input, "exit") == 0) {
            printf("Goodbye\n");
            exit(0);
        } else {
            printf("Unknown command - Enter 'help' for commands\n");
        }
    }
}

void addContact(struct Contact contacts[], int *numContacts) {
    struct Contact newContact;

    // Get contact name
    printf("Enter contact name: ");
    fgets(newContact.name, 50, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0;

    // Get contact phone number
    printf("Enter contact phone number: ");
    fgets(newContact.phone, 20, stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = 0;

    // Add contact to array
    contacts[*numContacts] = newContact;
    (*numContacts)++;
    printf("Contact added successfully\n");
}

void searchContacts(struct Contact contacts[], int numContacts, char query[]) {
    printf("Search results:\n");

    for (int i = 0; i < numContacts; i++) {
        // Check if name or phone number contains query
        if (strstr(contacts[i].name, query) != NULL || strstr(contacts[i].phone, query) != NULL) {
            printf("%s - %s\n", contacts[i].name, contacts[i].phone);
        }
    }
}

void printContacts(struct Contact contacts[], int numContacts) {
    printf("Contacts:\n");

    for (int i = 0; i < numContacts; i++) {
        printf("%s - %s\n", contacts[i].name, contacts[i].phone);
    }
}