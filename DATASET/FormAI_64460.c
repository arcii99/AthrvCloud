//FormAI DATASET v1.0 Category: Mailing list manager ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_EMAIL_LENGTH 50
#define MAX_LIST_CAPACITY 100

struct contact {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

struct mailing_list {
    struct contact contacts[MAX_LIST_CAPACITY];
    int size;
};

int add_contact(struct mailing_list* list, char* name, char* email) {
    if (list->size >= MAX_LIST_CAPACITY) {
        return 0;
    }
    struct contact* new_contact = &(list->contacts[list->size++]);
    strncpy(new_contact->name, name, MAX_NAME_LENGTH);
    strncpy(new_contact->email, email, MAX_EMAIL_LENGTH);
    return 1;
}

int remove_contact(struct mailing_list* list, char* name) {
    int index = find_contact_index(list, name);
    if (index == -1) {
        return 0;
    }
    list->contacts[index] = list->contacts[--list->size];
    return 1;
}

int find_contact_index(struct mailing_list* list, char* name) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->contacts[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct mailing_list list = { .size = 0 };
    
    // add some initial contacts
    add_contact(&list, "Alice", "alice@example.com");
    add_contact(&list, "Bob", "bob@example.com");
    add_contact(&list, "Charlie", "charlie@example.com");
    
    // print out the current list
    printf("Current list:\n");
    for (int i = 0; i < list.size; i++) {
        printf("%s (%s)\n", list.contacts[i].name, list.contacts[i].email);
    }
    
    // add a new contact
    add_contact(&list, "Dave", "dave@example.com");
    
    // print out the updated list
    printf("\nUpdated list:\n");
    for (int i = 0; i < list.size; i++) {
        printf("%s (%s)\n", list.contacts[i].name, list.contacts[i].email);
    }
    
    // remove a contact
    remove_contact(&list, "Charlie");
    
    // print out the final list
    printf("\nFinal list:\n");
    for (int i = 0; i < list.size; i++) {
        printf("%s (%s)\n", list.contacts[i].name, list.contacts[i].email);
    }
    
    return 0;
}