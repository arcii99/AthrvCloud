//FormAI DATASET v1.0 Category: Email Client ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_MSG_LENGTH 1024

int main() {

    char server_address[MAX_MSG_LENGTH];
    char username[MAX_MSG_LENGTH];
    char password[MAX_MSG_LENGTH];
    char recipient[MAX_MSG_LENGTH];
    char subject[MAX_MSG_LENGTH];
    char message[MAX_MSG_LENGTH];
    char choice[MAX_MSG_LENGTH];
    char exit_choice[MAX_MSG_LENGTH];

    // Enter email account details
    printf("Enter server address: ");
    fgets(server_address, MAX_MSG_LENGTH, stdin);
    printf("Enter username: ");
    fgets(username, MAX_MSG_LENGTH, stdin);
    printf("Enter password: ");
    fgets(password, MAX_MSG_LENGTH, stdin);
    printf("\n");

    // Login to email account
    printf("Connecting to %s as %s...\n", server_address, username);
    printf("Logged in successfully!\n\n");

    do {
        // Send email
        printf("Do you want to send an email? (yes/no): ");
        fgets(choice, MAX_MSG_LENGTH, stdin);

        if (strcmp(choice, "yes\n") == 0) {
            printf("Enter recipient email address: ");
            fgets(recipient, MAX_MSG_LENGTH, stdin);
            printf("Enter email subject: ");
            fgets(subject, MAX_MSG_LENGTH, stdin);
            printf("Enter email message: ");
            fgets(message, MAX_MSG_LENGTH, stdin);

            printf("Sending email to %s...\n", recipient);
            printf("From: %s\n", username);
            printf("To: %s\n", recipient);
            printf("Subject: %s", subject);
            printf("\n%s\n", message);
            printf("Email sent successfully!\n\n");
        }

        // Exit program
        printf("Do you want to exit? (yes/no): ");
        fgets(exit_choice, MAX_MSG_LENGTH, stdin);

        if (strcmp(exit_choice, "yes\n") == 0) {
            printf("Logging out...\n");
            printf("Logged out successfully!\n");
            break;
        }

    } while (strcmp(exit_choice, "no\n") == 0);

    return 0;
}