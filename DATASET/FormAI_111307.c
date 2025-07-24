//FormAI DATASET v1.0 Category: Email Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 256
#define MAX_EMAILS 50

// Email struct to store information about an email
typedef struct {
    char sender[MAX_INPUT];
    char receiver[MAX_INPUT];
    char subject[MAX_INPUT];
    char body[MAX_INPUT];
} Email;

// Function to display menu options
void displayMenu() {
    printf("\n=======C Email Client=======\n");
    printf("1. Send Email\n");
    printf("2. View Inbox\n");
    printf("3. Exit\n");
}

// Function to get user input
void getUserInput(char input[]) {
    printf("\nEnter your choice: ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove new line character
}

// Function to send an email
void sendEmail(Email *emails, int *count) {
    printf("\n=====Send Email=====\n");

    // Prompt user to enter sender email address
    printf("Enter sender email address: ");
    fgets(emails[*count].sender, MAX_INPUT, stdin);
    emails[*count].sender[strcspn(emails[*count].sender, "\n")] = '\0';

    // Prompt user to enter recipient email address
    printf("Enter recipient email address: ");
    fgets(emails[*count].receiver, MAX_INPUT, stdin);
    emails[*count].receiver[strcspn(emails[*count].receiver, "\n")] = '\0';

    // Prompt user to enter email subject
    printf("Enter email subject: ");
    fgets(emails[*count].subject, MAX_INPUT, stdin);
    emails[*count].subject[strcspn(emails[*count].subject, "\n")] = '\0';

    // Prompt user to enter email body
    printf("Enter email body: ");
    fgets(emails[*count].body, MAX_INPUT, stdin);
    emails[*count].body[strcspn(emails[*count].body, "\n")] = '\0';

    printf("\nEmail sent!\n");
    (*count)++;
}

// Function to view inbox
void viewInbox(Email *emails, int count) {
    if (count == 0) {
        printf("\nInbox is currently empty.\n");
    } else {
        printf("\n=====Inbox=====\n");
        for (int i = 0; i < count; i++) {
            printf("\nEmail #%d\n", i+1);
            printf("Sender: %s\n", emails[i].sender);
            printf("Recipient: %s\n", emails[i].receiver);
            printf("Subject: %s\n", emails[i].subject);
            printf("Body: %s\n", emails[i].body);
        }
    }
}

int main() {
    Email emails[MAX_EMAILS]; // Array of Emails
    int count = 0; // Counter for number of emails sent
    char choice[MAX_INPUT]; // User's menu choice

    do {
        displayMenu();
        getUserInput(choice);

        if (isdigit(choice[0])) {
            switch(atoi(choice)) {
                case 1: 
                    sendEmail(emails, &count);
                    break;
                case 2: 
                    viewInbox(emails, count);
                    break;
                case 3: 
                    printf("\nGoodbye!\n");
                    break;
                default: 
                    printf("\nInvalid option. Please try again.\n");
                    break;
            }
        } else {
            printf("\nInvalid input. Please enter a number from the menu.\n");
        }

    } while(atoi(choice) != 3);

    return 0;
}