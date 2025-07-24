//FormAI DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 50
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

struct Contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
};

struct PhoneBook {
    struct Contact contacts[MAX_CONTACTS];
    int num_contacts;
};

void add_contact(struct PhoneBook* pb) {
    if (pb->num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full. Cannot add new contact.\n");
        return;
    }

    struct Contact* c = &pb->contacts[pb->num_contacts];
    printf("Enter contact's name: ");
    fgets(c->name, MAX_NAME_LENGTH, stdin);
    c->name[strcspn(c->name, "\n")] = '\0';  // remove newline character
    printf("Enter contact's phone number: ");
    fgets(c->number, MAX_NUMBER_LENGTH, stdin);
    c->number[strcspn(c->number, "\n")] = '\0';  // remove newline character

    pb->num_contacts++;
    printf("Contact added successfully.\n");
}

void list_contacts(struct PhoneBook* pb) {
    if (pb->num_contacts == 0) {
        printf("Phone book is empty. No contacts to list.\n");
        return;
    }

    printf("Phone Book:\n");
    printf("-----------\n");
    for (int i = 0; i < pb->num_contacts; i++) {
        struct Contact* c = &pb->contacts[i];
        printf("%s: %s\n", c->name, c->number);
    }
}

int main() {
    struct PhoneBook pb = {0};

    while (1) {
        printf("\nEnter a command (add, list, quit): ");
        char cmd[10];
        fgets(cmd, 10, stdin);
        cmd[strcspn(cmd, "\n")] = '\0';  // remove newline character

        if (strcmp(cmd, "add") == 0) {
            add_contact(&pb);
        } else if (strcmp(cmd, "list") == 0) {
            list_contacts(&pb);
        } else if (strcmp(cmd, "quit") == 0) {
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    printf("Exiting phone book program.\n");
    return 0;
}