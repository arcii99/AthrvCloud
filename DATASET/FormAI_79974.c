//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_LIST_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

int addContact(Contact list[], int size) {
    if (size >= MAX_LIST_LENGTH) {
        printf("The contact list is full!\n");
        return size;
    }
    
    Contact newContact;
    printf("Enter name: ");
    fgets(newContact.name, MAX_NAME_LENGTH, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0; // remove trailing newline character
    printf("Enter email: ");
    fgets(newContact.email, MAX_EMAIL_LENGTH, stdin);
    newContact.email[strcspn(newContact.email, "\n")] = 0; // remove trailing newline character
    
    list[size] = newContact;
    printf("%s with email %s added to contact list.\n", newContact.name, newContact.email);
    return size + 1;
}

void printContacts(Contact list[], int size) {
    if (size == 0) {
        printf("The contact list is empty!\n");
    } else {
        printf("Contact List:\n");
        for (int i = 0; i < size; i++) {
            printf("%s (%s)\n", list[i].name, list[i].email);
        }
    }
}

int main() {
    Contact contactList[MAX_LIST_LENGTH];
    int size = 0;
    char input[10];

    printf("Welcome to the contact list manager!\n");

    while (1) {
        printf("\nEnter 'add' to add a contact, 'print' to print the contact list, or 'exit' to quit: ");
        fgets(input, 10, stdin);
        input[strcspn(input, "\n")] = 0; // remove trailing newline character

        if (strcmp(input, "add") == 0) {
            size = addContact(contactList, size);
        } else if (strcmp(input, "print") == 0) {
            printContacts(contactList, size);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid input.\n");
        }
    }

    printf("Goodbye!\n");
    return 0;
}