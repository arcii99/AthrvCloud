//FormAI DATASET v1.0 Category: Mailing list manager ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_LIST_SIZE 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Contact contacts[MAX_LIST_SIZE];
    int count;
} MailingList;

void addContact(MailingList* list, char name[], char email[]);
void printList(MailingList list);

int main() {
    MailingList myContacts = {"My List", {}, 0};

    addContact(&myContacts, "Alice Smith", "alice@example.com");
    addContact(&myContacts, "Bob Johnson", "bob@example.com");
    addContact(&myContacts, "Charlie Brown", "charlie@example.com");

    printf("My Mailing List:\n");
    printList(myContacts);

    return 0;
}

void addContact(MailingList* list, char name[], char email[]) {
    if (list->count == MAX_LIST_SIZE) {
        printf("Error: Mailing list is full.\n");
        return;
    }

    Contact newContact;
    strncpy(newContact.name, name, sizeof newContact.name);
    strncpy(newContact.email, email, sizeof newContact.email);

    list->contacts[list->count++] = newContact;
}

void printList(MailingList list) {
    printf("%s:\n", list.name);

    for (int i = 0; i < list.count; i++) {
        printf("%s <%s>\n", list.contacts[i].name, list.contacts[i].email);
    }
}