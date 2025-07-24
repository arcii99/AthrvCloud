//FormAI DATASET v1.0 Category: Phone Book ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum number of contacts */
#define MAX_CONTACTS 1000

/* Define the contact structure */
struct Contact {
    char name[50];
    char phone_number[20];
};

/* Define the phone book structure */
struct PhoneBook {
    struct Contact contacts[MAX_CONTACTS];
    int num_contacts;
};

/* Function to add a new contact to the phone book */
void add_contact(struct PhoneBook *pb) {
    char name[50];
    char phone_number[20];

    /* Get the new contact's name */
    printf("Enter the name of the new contact: ");
    fgets(name, 50, stdin);

    /* Remove the newline character from the end of the name */
    strtok(name, "\n");

    /* Get the new contact's phone number */
    printf("Enter the phone number of the new contact: ");
    fgets(phone_number, 20, stdin);

    /* Remove the newline character from the end of the phone number */
    strtok(phone_number, "\n");

    /* Add the new contact to the phone book */
    strcpy(pb->contacts[pb->num_contacts].name, name);
    strcpy(pb->contacts[pb->num_contacts].phone_number, phone_number);
    pb->num_contacts++;

    /* Print a message indicating that the contact was added */
    printf("Contact added successfully!\n");
}

/* Function to search for a contact in the phone book by name */
void search_contact(struct PhoneBook *pb) {
    char name[50];
    int i;

    /* Get the name of the contact to search for */
    printf("Enter the name of the contact to search for: ");
    fgets(name, 50, stdin);

    /* Remove the newline character from the end of the name */
    strtok(name, "\n");

    /* Search for the contact in the phone book */
    for (i = 0; i < pb->num_contacts; i++) {
        if (strcmp(pb->contacts[i].name, name) == 0) {
            /* Print the contact's phone number and return */
            printf("Phone number: %s\n", pb->contacts[i].phone_number);
            return;
        }
    }

    /* Print a message indicating that the contact was not found */
    printf("Contact not found.\n");
}

/* Main function */
int main() {
    struct PhoneBook pb;

    /* Initialize the phone book to have no contacts */
    pb.num_contacts = 0;

    /* Print the main menu */
    printf("Phone Book\n");
    printf("==========\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Quit\n");

    /* Get the user's choice */
    int choice;
    do {
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        /* Handle the user's choice */
        switch (choice) {
            case 1:
                add_contact(&pb);
                break;
            case 2:
                search_contact(&pb);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}