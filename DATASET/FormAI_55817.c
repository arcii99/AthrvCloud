//FormAI DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the maximum integer value for each string
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 50

// Define the struct that will hold our contact data
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

// Declare our array of contacts, with a maximum length of 100
Contact contacts[100];

// Declare a variable to keep track of how many contacts we have
int num_contacts = 0;

// Declare a function to get input from the user
void get_input(char *input, int max_length) {
    fgets(input, max_length, stdin);
    input[strcspn(input, "\n")] = '\0';
}

// Define a function to add a new contact to the database
void add_contact() {
    printf("Enter the name of the new contact:\n");
    get_input(contacts[num_contacts].name, MAX_NAME_LENGTH);

    printf("Enter the phone number of the new contact:\n");
    get_input(contacts[num_contacts].phone, MAX_PHONE_LENGTH);

    printf("Enter the email address of the new contact:\n");
    get_input(contacts[num_contacts].email, MAX_EMAIL_LENGTH);

    printf("New contact added!\n");

    num_contacts++;
}

// Define a function to print out all the contacts in the database
void print_contacts() {
    printf("CONTACT LIST\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n", contacts[i].email);
        printf("\n");
    }
}

// Define a function to search for a contact by name
void search_contacts() {
    printf("Enter the name of the contact you want to search for:\n");
    char search_name[MAX_NAME_LENGTH];
    get_input(search_name, MAX_NAME_LENGTH);

    int found = 0;

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            printf("\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No contact found with that name.\n");
    }
}

int main() {
    char input[10];

    while (1) {
        printf("Enter a command: (add, list, search, exit)\n");
        get_input(input, 10);

        if (strcmp(input, "add") == 0) {
            add_contact();
        }

        else if (strcmp(input, "list") == 0) {
            print_contacts();
        }

        else if (strcmp(input, "search") == 0) {
            search_contacts();
        }

        else if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            exit(0);
        }

        else {
            printf("Invalid command. Try again.\n");
        }
    }

    return 0;
}