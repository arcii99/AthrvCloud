//FormAI DATASET v1.0 Category: Email Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the max length of the message body and the email addresses
#define MAX_BODY_LEN 500
#define MAX_EMAIL_ADDR_LEN 50

// Struct for holding the email information
struct Email {
    char sender[MAX_EMAIL_ADDR_LEN];
    char recipient[MAX_EMAIL_ADDR_LEN];
    char subject[100];
    char body[MAX_BODY_LEN];
};

// Function for sending the email
void sendEmail(struct Email email) {
    // Connect to the email server and send the email
    printf("Email sent from %s to %s\nSubject: %s\n%s", email.sender, email.recipient, email.subject, email.body);
}

int main() {
    // Create a new email
    struct Email email;

    // Ask for the user's email address
    printf("Enter your email address: ");
    scanf("%s", email.sender);

    // Ask for the recipient's email address
    printf("Enter the recipient's email address: ");
    scanf("%s", email.recipient);

    // Ask for the email subject
    printf("Enter the email subject: ");
    scanf("%s", email.subject);

    // Ask for the email body
    printf("Enter the email body: ");
    scanf(" %[^\n]s", email.body);
    
    // Send the email
    sendEmail(email);
    
    // Return 0 to indicate success
    return 0;
}