//FormAI DATASET v1.0 Category: Email Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the email body
#define BODY_SIZE 2500

// Struct for each email
struct Email {
    char sender[50];
    char recipient[50];
    char subject[100];
    char body[BODY_SIZE];
};

// Function to send an email
void send_email(struct Email email) {
    // Connect to the SMTP server and send the email
    printf("Sending email \"%s\" from %s to %s...\n", email.subject, email.sender, email.recipient);
    printf("Email body: \n%s\n", email.body);
    printf("Email sent successfully!\n");
}

int main() {
    // Prompt the user to enter the email details
    printf("Welcome to MyMail - The Best Email Client in C\n");
    printf("Enter the email details below:\n");

    // Initialize an email struct
    struct Email email;
    memset(&email, 0, sizeof(email));

    // Get the sender email
    printf("From: ");
    fgets(email.sender, sizeof(email.sender), stdin);
    email.sender[strcspn(email.sender, "\n")] = '\0';

    // Get the recipient email
    printf("To: ");
    fgets(email.recipient, sizeof(email.recipient), stdin);
    email.recipient[strcspn(email.recipient, "\n")] = '\0';

    // Get the email subject
    printf("Subject: ");
    fgets(email.subject, sizeof(email.subject), stdin);
    email.subject[strcspn(email.subject, "\n")] = '\0';

    // Get the email body
    printf("Body:\n");
    fgets(email.body, sizeof(email.body), stdin);
    email.body[strcspn(email.body, "\n")] = '\0';

    // Send the email
    send_email(email);

    // Exit the program
    printf("Thank you for using MyMail!\n");
    return 0;
}