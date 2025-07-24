//FormAI DATASET v1.0 Category: Phone Book ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct contact {
    char name[30];
    char phone_number[15];
    char email[50];
} Contact;

int read_int() {
    char buffer[100];
    fgets(buffer, 100, stdin);
    return atoi(buffer);
}

void flush_input() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void print_contact(Contact *contact) {
    printf("Name: %s\n", contact->name);
    printf("Phone Number: %s\n", contact->phone_number);
    printf("Email: %s\n", contact->email);
    printf("\n");
}

void print_contacts(Contact *contacts, int count) {
    for (int i = 0; i < count; i++) {
        printf("Contact %d:\n", i + 1);
        print_contact(&contacts[i]);
    }
}

void add_contact(Contact *contacts, int *count) {
    Contact new_contact;
    printf("Enter name: ");
    fgets(new_contact.name, 30, stdin);
    printf("Enter phone number: ");
    fgets(new_contact.phone_number, 15, stdin);
    printf("Enter email: ");
    fgets(new_contact.email, 50, stdin);
    contacts[*count] = new_contact;
    *count += 1;
}

void search_contacts(Contact *contacts, int count) {
    char name[30];
    printf("Enter name to search for: ");
    fgets(name, 30, stdin);
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found:\n");
            print_contact(&contacts[i]);
            return;
        }
    }
    printf("Contact not found.\n");
}

void delete_contact(Contact *contacts, int *count) {
    char name[30];
    printf("Enter name of contact to delete: ");
    fgets(name, 30, stdin);
    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i + 1; j < *count; j++) {
                contacts[j - 1] = contacts[j];
            }
            *count -= 1;
            printf("Contact deleted.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;

    printf("Welcome to MyPhoneBook\n");
    while (1) {
        printf("Please select an option:\n");
        printf("1. Add a contact\n");
        printf("2. View all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Delete a contact\n");
        printf("5. Exit\n");

        int choice = read_int();
        flush_input();

        switch (choice) {
            case 1:
                add_contact(contacts, &count);
                break;
            case 2:
                print_contacts(contacts, count);
                break;
            case 3:
                search_contacts(contacts, count);
                break;
            case 4:
                delete_contact(contacts, &count);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}