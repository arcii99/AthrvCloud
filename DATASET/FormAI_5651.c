//FormAI DATASET v1.0 Category: Email Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct email {
    char* sender;
    char* receiver;
    char* subject;
    char* body;
};

int main() {
    printf("Welcome to HappyMail!\n");
    printf("=====================\n");

    char* username = "happyuser";
    char* password = "happypassword";

    printf("Please enter your username: ");
    char input_username[50];
    fgets(input_username, 50, stdin);
    input_username[strcspn(input_username, "\n")] = 0;

    printf("Please enter your password: ");
    char input_password[50];
    fgets(input_password, 50, stdin);
    input_password[strcspn(input_password, "\n")] = 0;

    if (strcmp(input_username, username) == 0 && strcmp(input_password, password) == 0) {
        printf("\nWelcome, %s!\n", username);
        printf("=====================\n");

        char* recipient = NULL;
        char* email_subject = NULL;
        char* email_body = NULL;

        printf("Would you like to send or receive an email? (enter \"send\" or \"receive\")\n");
        char input[10];
        fgets(input, 10, stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "send") == 0) {
            printf("Please enter the recipient's email address: ");
            char recipient_input[50];
            fgets(recipient_input, 50, stdin);
            recipient_input[strcspn(recipient_input, "\n")] = 0;
            recipient = malloc(strlen(recipient_input) + 1);
            strcpy(recipient, recipient_input);

            printf("Please enter the email subject: ");
            char subject_input[100];
            fgets(subject_input, 100, stdin);
            subject_input[strcspn(subject_input, "\n")] = 0;
            email_subject = malloc(strlen(subject_input) + 1);
            strcpy(email_subject, subject_input);

            printf("Please enter the email body: ");
            char body_input[1000];
            fgets(body_input, 1000, stdin);
            body_input[strcspn(body_input, "\n")] = 0;
            email_body = malloc(strlen(body_input) + 1);
            strcpy(email_body, body_input);

            struct email new_email = {username, recipient, email_subject, email_body};
            printf("\nSending email...\n\n");
            printf("Sender: %s\nRecipient: %s\nSubject: %s\nBody: %s\n", new_email.sender, new_email.receiver, new_email.subject, new_email.body);

            free(recipient);
            free(email_subject);
            free(email_body);
        } else if (strcmp(input, "receive") == 0) {
            printf("Checking for new emails...\n");
            printf("None found.\n");
        } else {
            printf("Invalid input.\n");
        }
    } else {
        printf("\nIncorrect username or password.\n");
    }

    printf("\nThank you for using HappyMail! Have a great day!\n");

    return 0;
}