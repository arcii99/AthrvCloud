//FormAI DATASET v1.0 Category: Email Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is a unique C Email Client example program in a Claude Shannon style

// Define a structure to hold email data
typedef struct {
    char sender[50];
    char recipient[50];
    char subject[100];
    char message[1000];
} Email;

// Function to prompt user for email input
Email getEmail() {
    Email email;
    printf("Enter sender email: ");
    fgets(email.sender, 50, stdin);
    printf("Enter recipient email: ");
    fgets(email.recipient, 50, stdin);
    printf("Enter email subject: ");
    fgets(email.subject, 100, stdin);
    printf("Enter email message: ");
    fgets(email.message, 1000, stdin);
    return email;
}

// Function to print email data
void printEmail(Email email) {
    printf("\nSender: %s", email.sender);
    printf("Recipient: %s", email.recipient);
    printf("Subject: %s", email.subject);
    printf("Message: %s", email.message);
}

// Main function
int main() {
    // Greet the user
    printf("Welcome to the C Email Client Example Program in a Claude Shannon Style\n");

    // Prompt for email input
    Email email = getEmail();

    // Print email data
    printf("\nEmail Data:");
    printEmail(email);

    // Exit the program
    printf("\n\nExiting Program. Thank you for using the C Email Client Example Program in a Claude Shannon Style.");
    return 0;
}