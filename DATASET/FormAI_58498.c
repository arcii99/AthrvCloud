//FormAI DATASET v1.0 Category: Mailing list manager ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum number of contacts that can be stored
#define MAX_CONTACTS 1000

// structure to store contact information
typedef struct Contact {
    char name[50];
    char email[50];
    char phone[20];
} Contact;

// function to add a contact to the mailing list
void add_contact(Contact mailing_list[], int *num_contacts) {
    // check if the mailing list is full
    if (*num_contacts == MAX_CONTACTS) {
        printf("Mailing list is full!\n");
        return;
    }

    // add a new contact
    Contact new_contact;
    printf("Enter name: ");
    fgets(new_contact.name, 50, stdin);
    printf("Enter email: ");
    fgets(new_contact.email, 50, stdin);
    printf("Enter phone: ");
    fgets(new_contact.phone, 20, stdin);

    // remove newline character from input
    new_contact.name[strcspn(new_contact.name, "\n")] = '\0';
    new_contact.email[strcspn(new_contact.email, "\n")] = '\0';
    new_contact.phone[strcspn(new_contact.phone, "\n")] = '\0';

    // add the contact to the mailing list
    mailing_list[*num_contacts] = new_contact;
    (*num_contacts)++;
}

// function to print all contacts in the mailing list
void print_contacts(Contact mailing_list[], int num_contacts) {
    printf("Contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s, Email: %s, Phone: %s\n",
            mailing_list[i].name, mailing_list[i].email, mailing_list[i].phone);
    }
}

// function to search for a contact by name
void search_contact(Contact mailing_list[], int num_contacts) {
    char search_name[50];
    printf("Enter name to search: ");
    fgets(search_name, 50, stdin);
    // remove newline character from input
    search_name[strcspn(search_name, "\n")] = '\0';

    // search for the contact
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(mailing_list[i].name, search_name) == 0) {
            printf("Name: %s, Email: %s, Phone: %s\n",
                mailing_list[i].name, mailing_list[i].email, mailing_list[i].phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

// main function
int main() {
    // initialize the mailing list
    Contact mailing_list[MAX_CONTACTS];
    int num_contacts = 0;

    // main loop to manage the mailing list
    while (1) {
        // print menu
        printf("\nMailing List Manager\n");
        printf("--------------------\n");
        printf("1. Add contact\n");
        printf("2. View all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Exit\n");

        // get selection from user
        char input[5];
        printf("Enter selection: ");
        fgets(input, 5, stdin);
        // remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // process selection
        if (strcmp(input, "1") == 0) {
            add_contact(mailing_list, &num_contacts);
        }
        else if (strcmp(input, "2") == 0) {
            print_contacts(mailing_list, num_contacts);
        }
        else if (strcmp(input, "3") == 0) {
            search_contact(mailing_list, num_contacts);
        }
        else if (strcmp(input, "4") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid selection!\n");
        }
    }

    return 0;
}