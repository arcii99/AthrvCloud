//FormAI DATASET v1.0 Category: Mailing list manager ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_LIST_SIZE 10

// Create a struct to hold the mailing list data
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

// Create an array to hold mailing list data
Contact mailingList[MAX_LIST_SIZE];

// Keeps track of how many contacts are currently in the mailing list
int listSize = 0;

// Function prototypes
void addContact();
void removeContact(char *email);
void printList();

int main() {
    printf("Welcome to the Mailing List Manager!\n\n");

    // Main program loop
    while (1) {
        // Display menu options
        printf("Please select an option:\n");
        printf("1. Add a contact\n");
        printf("2. Remove a contact\n");
        printf("3. Print the mailing list\n");
        printf("4. Quit\n");

        // Get user input
        char input[10];
        fgets(input, 10, stdin);

        // Handle user selection
        if (strcmp(input, "1\n") == 0) {
            addContact();
        } else if (strcmp(input, "2\n") == 0) {
            printf("Enter the email address of the contact you would like to remove:\n");
            char email[MAX_EMAIL_LENGTH];
            fgets(email, MAX_EMAIL_LENGTH, stdin);
            removeContact(email);
        } else if (strcmp(input, "3\n") == 0) {
            printList();
        } else if (strcmp(input, "4\n") == 0) {
            printf("Thank you for using the Mailing List Manager!\n");
            return 0;
        } else {
            printf("Invalid input, please try again.\n");
        }

        printf("\n");
    }
}

void addContact() {
    // Check if the mailing list is full
    if (listSize == MAX_LIST_SIZE) {
        printf("The mailing list is full. Cannot add any more contacts.\n");
        return;
    }

    // Prompt user for contact information
    printf("Please enter the name of the contact:\n");
    char name[MAX_NAME_LENGTH];
    fgets(name, MAX_NAME_LENGTH, stdin);
    printf("Please enter the email address of the contact:\n");
    char email[MAX_EMAIL_LENGTH];
    fgets(email, MAX_EMAIL_LENGTH, stdin);

    // Create a new contact struct and add it to the mailing list
    Contact newContact;
    strcpy(newContact.name, name);
    strcpy(newContact.email, email);
    mailingList[listSize] = newContact;
    listSize++;

    printf("Contact added!\n");
}

void removeContact(char *email) {
    // Loop through the mailing list to find the contact with the matching email
    int found = 0;
    for (int i = 0; i < listSize; i++) {
        if (strcmp(mailingList[i].email, email) == 0) {
            // Shift all contacts after the removed contact over by 1 position
            for (int j = i; j < listSize-1; j++) {
                mailingList[j] = mailingList[j+1];
            }
            listSize--;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Contact removed!\n");
    } else {
        printf("Contact not found.\n");
    }
}

void printList() {
    printf("Mailing List:\n");
    for (int i = 0; i < listSize; i++) {
        printf("%s - %s", mailingList[i].name, mailingList[i].email);
    }
}