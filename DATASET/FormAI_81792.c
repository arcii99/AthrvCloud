//FormAI DATASET v1.0 Category: Mailing list manager ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact *contacts;
    int capacity;
    int size;
} MailingList;

void initializeList(MailingList *list, int capacity) {
    list->capacity = capacity;
    list->size = 0;
    list->contacts = (Contact*) malloc(sizeof(Contact) * capacity);
}

void addContact(MailingList *list, char *name, char *email) {
    if (list->size == list->capacity) {
        printf("Mailing list is full. Cannot add new contact.\n");
        return;
    }
    Contact newContact;
    strncpy(newContact.name, name, MAX_NAME_LENGTH);
    strncpy(newContact.email, email, MAX_EMAIL_LENGTH);
    list->contacts[list->size++] = newContact;
    printf("Added contact: %s - %s\n", newContact.name, newContact.email);
}

void printList(MailingList *list) {
    printf("Mailing list:\n");
    for (int i = 0; i < list->size; i++) {
        printf("%s - %s\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    MailingList myContacts;
    initializeList(&myContacts, 5);
    addContact(&myContacts, "John Doe", "jdoe@gmail.com");
    printList(&myContacts);
    addContact(&myContacts, "Jane Smith", "jsmith@yahoo.com");
    addContact(&myContacts, "Bob Johnson", "bjohnson@hotmail.com");
    addContact(&myContacts, "Sarah Lee", "slee@gmail.com");
    addContact(&myContacts, "Jim Brown", "jbrown@yahoo.com");
    addContact(&myContacts, "Karen Davis", "kdavis@hotmail.com");
    printList(&myContacts);
    free(myContacts.contacts);
    return 0;
}