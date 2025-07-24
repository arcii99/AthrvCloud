//FormAI DATASET v1.0 Category: Mailing list manager ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_NAME_LENGTH 30
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

typedef struct {
    Contact contacts[MAX_EMAILS];
    int size;
} ContactList;

void add_contact(ContactList *list, Contact contact) {
    if (list->size >= MAX_EMAILS) {
        printf("Contact list has reached maximum capacity.\n");
        return;
    }
    list->contacts[list->size++] = contact;
}

void remove_contact(ContactList *list, char *email) {
    int index = -1;
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->contacts[i].email, email) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Contact with email %s does not exist.\n", email);
        return;
    }
    for (int i = index; i < list->size - 1; i++) {
        list->contacts[i] = list->contacts[i+1];
    }
    list->size--;
    printf("Contact with email %s has been removed.\n", email);
}

void print_contacts(ContactList *list) {
    printf("Contact List:\n");
    for (int i = 0; i < list->size; i++) {
        printf("%s: %s\n", list->contacts[i].name, list->contacts[i].email);
    }
}

int main() {
    ContactList list = {0};
    int choice = 0;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Print contacts\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  // Clear input buffer of newline character
        switch (choice) {
            case 1: {
                Contact contact;
                printf("Enter name: ");
                fgets(contact.name, MAX_NAME_LENGTH, stdin);
                contact.name[strlen(contact.name)-1] = '\0';  // Remove newline character from input
                printf("Enter email: ");
                fgets(contact.email, MAX_EMAIL_LENGTH, stdin);
                contact.email[strlen(contact.email)-1] = '\0';  // Remove newline character from input
                add_contact(&list, contact);
                break;
            }
            case 2: {
                char email[MAX_EMAIL_LENGTH];
                printf("Enter email to remove: ");
                fgets(email, MAX_EMAIL_LENGTH, stdin);
                email[strlen(email)-1] = '\0';  // Remove newline character from input
                remove_contact(&list, email);
                break;
            }
            case 3:
                print_contacts(&list);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}