//FormAI DATASET v1.0 Category: Mailing list manager ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 30
#define MAX_CONTACTS 100

/* Data structure to represent a contact */
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

/* Data structure to represent a contact list */
typedef struct {
    Contact contacts[MAX_CONTACTS];
    int size;
} ContactList;

/* Function to add a contact to the contact list */
void addContact(ContactList *list, Contact contact) {
    if(list->size < MAX_CONTACTS) {
        list->contacts[list->size++] = contact;
    } else {
        printf("Contact list is full!\n");
    }
}

/* Function to remove a contact from the contact list */
void removeContact(ContactList *list, Contact contact) {
    int i, j;
    for(i = 0; i < list->size; i++) {
        if(strcmp(list->contacts[i].name, contact.name) == 0 &&
            strcmp(list->contacts[i].email, contact.email) == 0) {
            for(j = i; j < list->size - 1; j++) {
                list->contacts[j] = list->contacts[j+1];
            }
            list->size--;
            printf("%s's contact removed from the list.\n", contact.name);
            break;
        }
    }
}

/* Function to display all contacts in the contact list */
void displayContacts(ContactList *list) {
    int i;
    for(i = 0; i < list->size; i++) {
        printf("%s: %s\n", list->contacts[i].name, list->contacts[i].email);
    }
}

/* Function to search for a contact by name or email */
void searchContact(ContactList *list, char *searchString) {
    int i;
    for(i = 0; i < list->size; i++) {
        if(strcmp(list->contacts[i].name, searchString) == 0 ||
            strcmp(list->contacts[i].email, searchString) == 0) {
            printf("%s: %s\n", list->contacts[i].name, list->contacts[i].email);
        }
    }
}

/* Main function to test the contact list manager */
int main() {
    ContactList list;
    list.size = 0;

    /* Add some test contacts */
    Contact c1 = {"John Doe", "john.doe@example.com"};
    Contact c2 = {"Jane Doe", "jane.doe@example.com"};
    addContact(&list, c1);
    addContact(&list, c2);

    /* Search for a contact */
    printf("Searching for contact 'John Doe':\n");
    searchContact(&list, "John Doe");

    /* Remove a contact */
    printf("Removing Jane Doe's contact:\n");
    removeContact(&list, c2);

    /* Display the final contact list */
    printf("Final Contact List:\n");
    displayContacts(&list);

    return 0;
}