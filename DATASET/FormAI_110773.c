//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100 // Maximum length of user input
#define MAX_EMAILS 10 // Maximum number of emails in mailing list
#define MAX_EMAIL_LEN 50 // Maximum length of single email

int main() {
    char mailingList[MAX_EMAILS][MAX_EMAIL_LEN]; // Initialize mailing list
    char input[MAX_INPUT]; // Initialize user input
    int numEmails = 0; // Initialize number of emails in mailing list

    // Print welcome message and instructions
    printf("Welcome to the mailing list manager!\n");
    printf("Enter 'ADD' to add an email address to the mailing list,\n");
    printf("'REMOVE' to remove an email address from the mailing list, or\n");
    printf("'QUIT' to exit the program.\n\n");

    while (1) { // Loop until user quits
        printf("Enter command: ");
        fgets(input, MAX_INPUT, stdin); // Get user input

        // Handle ADD command
        if (strncmp(input, "ADD", 3) == 0) {
            if (numEmails >= MAX_EMAILS) { // Check if mailing list is full
                printf("Mailing list is full. Cannot add email address.\n");
            } else {
                printf("Enter email address to add: ");
                fgets(mailingList[numEmails], MAX_EMAIL_LEN, stdin); // Get email address from user
                numEmails++; // Increment number of emails in mailing list
                printf("Email address added to mailing list.\n");
            }
        }

        // Handle REMOVE command
        else if (strncmp(input, "REMOVE", 6) == 0) {
            if (numEmails == 0) { // Check if mailing list is empty
                printf("Mailing list is empty. Cannot remove email address.\n");
            } else {
                printf("Enter email address to remove: ");
                fgets(input, MAX_INPUT, stdin); // Get email address from user
                int removalIndex = -1; // Initialize index of email to remove
                for (int i = 0; i < numEmails; i++) {
                    if (strncmp(mailingList[i], input, strlen(input)-1) == 0) { // Find email address in mailing list
                        removalIndex = i; // Set index of email to remove
                        break;
                    }
                }
                if (removalIndex == -1) { // Email address not found in mailing list
                    printf("Email address not found in mailing list.\n");
                } else {
                    for (int i = removalIndex; i < numEmails-1; i++) {
                        strncpy(mailingList[i], mailingList[i+1], MAX_EMAIL_LEN); // Shift all emails after removal index left by one
                    }
                    numEmails--; // Decrement number of emails in mailing list
                    printf("Email address removed from mailing list.\n");
                }
            }
        }

        // Handle QUIT command
        else if (strncmp(input, "QUIT", 4) == 0) {
            printf("Exiting mailing list manager...\n");
            exit(0);
        }

        // Handle invalid command
        else {
            printf("Invalid command. Please enter 'ADD', 'REMOVE', or 'QUIT'.\n");
        }
    }

    return 0;
}