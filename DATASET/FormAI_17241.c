//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Donald Knuth
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
    Contact list[MAX_LIST_SIZE];
    int size;
} MailingList;

// Initialize an empty mailing list
void init_list(MailingList* listPtr) {
    listPtr->size = 0;
}

// Add a contact to the mailing list
void add_contact(MailingList* listPtr, const char* name, const char* email) {
    if (listPtr->size >= MAX_LIST_SIZE) {
        printf("List is full. Cannot add more contacts.\n");
        return;
    }
    strncpy(listPtr->list[listPtr->size].name, name, MAX_NAME_LENGTH);
    listPtr->list[listPtr->size].name[MAX_NAME_LENGTH-1] = '\0'; // Ensure null termination
    strncpy(listPtr->list[listPtr->size].email, email, MAX_EMAIL_LENGTH);
    listPtr->list[listPtr->size].email[MAX_EMAIL_LENGTH-1] = '\0'; // Ensure null termination
    listPtr->size++;
}

// Remove a contact from the mailing list
void remove_contact(MailingList* listPtr, const char* email) {
    int i, j;
    for (i = 0; i < listPtr->size; i++) {
        if (strcmp(listPtr->list[i].email, email) == 0) {
            // Found contact to be removed, shift all contacts after it back by one
            for (j = i; j < listPtr->size-1; j++) {
                strcpy(listPtr->list[j].name, listPtr->list[j+1].name);
                strcpy(listPtr->list[j].email, listPtr->list[j+1].email);
            }
            listPtr->size--;
            printf("Contact removed.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

// Print all contacts in the mailing list
void print_list(MailingList* listPtr) {
    int i;
    printf("Mailing list (%d contacts):\n", listPtr->size);
    for (i = 0; i < listPtr->size; i++) {
        printf("%s -- %s\n", listPtr->list[i].name, listPtr->list[i].email);
    }
}

int main() {
    MailingList list;
    init_list(&list);
    add_contact(&list, "John Smith", "johnsmith@example.com");
    add_contact(&list, "Jane Doe", "janedoe@example.com");
    add_contact(&list, "Bob Johnson", "bjohnson@example.com");
    print_list(&list);
    remove_contact(&list, "janedoe@example.com");
    print_list(&list);
    return 0;
}