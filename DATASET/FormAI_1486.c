//FormAI DATASET v1.0 Category: Mailing list manager ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_LIST_SIZE 100

// Define a struct to store contact information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

// Define a struct to store the mailing list
typedef struct {
    Contact contacts[MAX_LIST_SIZE];
    int size;
} MailingList;

// Print the given contact's information
void printContact(Contact contact) {
    printf("Name: %s\n", contact.name);
    printf("Email: %s\n", contact.email);
    printf("\n");
}

// Add a contact to the mailing list
void addContact(MailingList *list, Contact contact) {
    // Check if the list is already full
    if (list->size >= MAX_LIST_SIZE) {
        printf("Error: Mailing list is full\n");
        return;
    }

    // Add the contact to the list
    list->contacts[list->size] = contact;
    list->size++;

    printf("Contact added:\n");
    printContact(contact);
}

// Remove a contact from the mailing list
void removeContact(MailingList *list, char *name) {
    int i;
    for (i = 0; i < list->size; i++) {
        if (strcmp(list->contacts[i].name, name) == 0) {
            // Shift all the contacts after the removed contact back by one position
            int j;
            for (j = i+1; j < list->size; j++) {
                list->contacts[j-1] = list->contacts[j];
            }
            list->size--;
            printf("Contact removed:\n");
            printContact(list->contacts[i]);
            return;
        }
    }
    printf("Error: Contact not found\n");
}

// Print all contacts in the mailing list
void printMailingList(MailingList list) {
    printf("Mailing list:\n");
    int i;
    for (i = 0; i < list.size; i++) {
        printf("%d.\n", i+1);
        printContact(list.contacts[i]);
    }

    if (list.size == 0) {
        printf("(empty)\n");
    }
}

int main() {
    MailingList list = {
        .size = 0
    };

    // Add some test contacts
    Contact alice = {
        .name = "Alice Johnson",
        .email = "alice.johnson@example.com"
    };
    addContact(&list, alice);

    Contact bob = {
        .name = "Bob Smith",
        .email = "bob.smith@example.com"
    };
    addContact(&list, bob);

    Contact charlie = {
        .name = "Charlie Brown",
        .email = "charlie.brown@example.com"
    };
    addContact(&list, charlie);

    // Print the mailing list
    printMailingList(list);

    // Remove a contact
    printf("Removing Bob Smith...\n");
    removeContact(&list, "Bob Smith");

    // Print the mailing list again
    printMailingList(list);

    return 0;
}