//FormAI DATASET v1.0 Category: Email Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining max length for email ID and password
#define MAX_LENGTH_EMAIL 50
#define MAX_LENGTH_PASSWORD 20

// defining a struct for an email
typedef struct {
    char sender[MAX_LENGTH_EMAIL];
    char recipient[MAX_LENGTH_EMAIL];
    char subject[MAX_LENGTH_EMAIL];
    char message[MAX_LENGTH_EMAIL];
} Email;

int main() {
    // initializing variables
    int option;
    char email[MAX_LENGTH_EMAIL];
    char password[MAX_LENGTH_PASSWORD];
    Email myEmail;

    // displaying menu and taking input
    printf("---Welcome to XYZ Email---\n");
    printf("Enter your email ID: ");
    fgets(email, MAX_LENGTH_EMAIL, stdin);
    printf("Enter your password: ");
    fgets(password, MAX_LENGTH_PASSWORD, stdin);

    // checking if login credentials are valid
    printf("\nChecking login credentials...\n\n");
    if (strcmp(email, "example@xyz.com\n") == 0 && strcmp(password, "password123\n") == 0) {
        printf("Login successful!\n\n");
        do {
            // displaying menu and taking input
            printf("---Menu---\n");
            printf("1. Send Email\n");
            printf("2. Exit\n");
            printf("Enter an option: ");
            scanf("%d", &option);
            getchar(); // remove trailing newline

            switch (option) {
                case 1:
                    // taking input for email details
                    printf("\n---Compose a New Email---\n");
                    printf("Sender's email ID: ");
                    fgets(myEmail.sender, MAX_LENGTH_EMAIL, stdin);
                    printf("Recipient's email ID: ");
                    fgets(myEmail.recipient, MAX_LENGTH_EMAIL, stdin);
                    printf("Subject: ");
                    fgets(myEmail.subject, MAX_LENGTH_EMAIL, stdin);
                    printf("Message: ");
                    fgets(myEmail.message, MAX_LENGTH_EMAIL, stdin);

                    // confirmation message
                    printf("\nSending email...\n");
                    printf("\n---Email Details---\n");
                    printf("From: %s", myEmail.sender);
                    printf("To: %s", myEmail.recipient);
                    printf("Subject: %s", myEmail.subject);
                    printf("Message: %s\n", myEmail.message);
                    printf("Email sent successfully!\n\n");
                    break;

                case 2:
                    printf("\nExiting...\n");
                    break;

                default:
                    printf("\nInvalid option. Please enter a valid option.\n\n");
            }
        } while (option != 2);
    } else {
        printf("Invalid login credentials. Please try again.\n");
    }

    return 0;
}