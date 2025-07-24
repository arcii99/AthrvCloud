//FormAI DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100 // Maximum number of emails the client can handle
#define MAX_SUBJECT_LENGTH 100 // Maximum length of a subject line
#define MAX_BODY_LENGTH 1000 // Maximum length of an email body

// Structure representing an email
typedef struct {
    char *subject; // The email's subject line
    char *body; // The body of the email
    char *recipient; // The email's recipient
} Email;

// Function to create a new email
Email *new_email(char *subject, char *body, char *recipient) {
    Email *email = malloc(sizeof(Email));
    email->subject = strdup(subject);
    email->body = strdup(body);
    email->recipient = strdup(recipient);
    return email;
}

int main() {
    Email *emails[MAX_EMAILS]; // Array of emails
    int num_emails = 0; // Number of emails currently in the client
    char input_buffer[100]; // Buffer for user input
    int input_num; // Number input by user

    printf("Welcome to the C Email Client!\n");

    while (1) { // Main loop
        printf("\nWhat would you like to do?\n");
        printf("1. Compose a new email\n");
        printf("2. View existing emails\n");
        printf("3. Exit\n");

        fgets(input_buffer, sizeof(input_buffer), stdin);
        input_num = atoi(input_buffer);

        if (input_num == 1) { // Compose a new email
            if (num_emails >= MAX_EMAILS) {
                printf("Sorry, the client can only handle %d emails at a time.\n", MAX_EMAILS);
                continue;
            }

            printf("\nEnter the recipient's email address: ");
            char recipient[MAX_SUBJECT_LENGTH];
            fgets(recipient, sizeof(recipient), stdin);

            printf("Enter the email's subject line: ");
            char subject[MAX_SUBJECT_LENGTH];
            fgets(subject, sizeof(subject), stdin);

            printf("Enter the email's body: ");
            char body[MAX_BODY_LENGTH];
            fgets(body, sizeof(body), stdin);

            emails[num_emails] = new_email(subject, body, recipient);
            num_emails++;

            printf("\nEmail sent successfully!\n");
        } else if (input_num == 2) { // View existing emails
            if (num_emails == 0) {
                printf("No emails to display.\n");
                continue;
            }

            printf("\nHere are your existing emails:\n");

            for (int i = 0; i < num_emails; i++) {
                Email *email = emails[i];
                printf("Email %d:\n", i+1);
                printf("Recipient: %s\n", email->recipient);
                printf("Subject: %s\n", email->subject);
                printf("Body: %s\n", email->body);
            }
        } else if (input_num == 3) { // Exit
            printf("\nThank you for using the C Email Client!\n");
            break;
        } else { // Invalid input
            printf("\nInvalid input. Please enter a number between 1 and 3.\n");
        }
    }

    // Clean up allocated memory
    for (int i = 0; i < num_emails; i++) {
        free(emails[i]->subject);
        free(emails[i]->body);
        free(emails[i]->recipient);
        free(emails[i]);
    }

    return 0;
}