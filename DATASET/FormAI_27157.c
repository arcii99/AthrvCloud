//FormAI DATASET v1.0 Category: Email Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define max length of string inputs
#define MAX_INPUT_LENGTH 100

// Struct for holding email data
typedef struct {
    char sender[MAX_INPUT_LENGTH];
    char recipient[MAX_INPUT_LENGTH];
    char subject[MAX_INPUT_LENGTH];
    char body[MAX_INPUT_LENGTH*10];
} email;

// Function for sending email
void send_email(email e) {
    printf("\nEncrypting email...");
    printf("\nSending email from %s to %s", e.sender, e.recipient);
    printf("\nSubject: %s", e.subject);
    printf("\nBody: %s", e.body);
    printf("\nEmail sent.\n");
}

int main() {
    printf("Welcome to the Cyberpunk Email Client!\n");

    // Declare email struct and buffer for user input
    email e;
    char buffer[MAX_INPUT_LENGTH];
    
    // Get sender name
    printf("\nEnter your name: ");
    fgets(buffer, MAX_INPUT_LENGTH, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    strncpy(e.sender, buffer, MAX_INPUT_LENGTH);

    // Get recipient email
    printf("\nEnter recipient email: ");
    fgets(buffer, MAX_INPUT_LENGTH, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    strncpy(e.recipient, buffer, MAX_INPUT_LENGTH);

    // Get email subject
    printf("\nEnter email subject: ");
    fgets(buffer, MAX_INPUT_LENGTH, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    strncpy(e.subject, buffer, MAX_INPUT_LENGTH);

    // Get email body
    printf("\nEnter email body: ");
    fgets(buffer, MAX_INPUT_LENGTH*10, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    strncpy(e.body, buffer, MAX_INPUT_LENGTH*10);

    // Send the email
    send_email(e);

    return 0;
}