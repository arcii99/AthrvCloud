//FormAI DATASET v1.0 Category: Email Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum lengths for the email fields
#define MAX_SUBJECT_LENGTH 100
#define MAX_SENDER_LENGTH 50
#define MAX_RECIPIENT_LENGTH 50
#define MAX_BODY_LENGTH 1000

// Define the email structure
typedef struct Email {
    char subject[MAX_SUBJECT_LENGTH];
    char sender[MAX_SENDER_LENGTH];
    char recipient[MAX_RECIPIENT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

// Function to clear the input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Function to get a valid email address
void get_email_address(char *address, int max_length) {
    // Loop until a valid email address is entered
    while (1) {
        // Get the user input
        fgets(address, max_length, stdin);
        // Trim any whitespace characters at the beginning and end of the address
        int len = strlen(address);
        while (len > 0 && isspace(address[len - 1])) {
            address[--len] = '\0';
        }
        while (isspace(*address)) {
            ++address;
        }
        // Check if the address is valid
        if (len > 0 && strchr(address, '@') != NULL) {
            // Address is valid, return it
            return;
        } else {
            // Address is invalid, ask user to enter another one
            printf("Invalid email address, please enter a valid one:\n");
        }
    }
}

// Main function
int main() {

    // Initialize the email
    Email email;
    strcpy(email.sender, "me@example.com");

    // Get the recipient's email address
    printf("Enter the recipient's email address:\n");
    get_email_address(email.recipient, MAX_RECIPIENT_LENGTH);

    // Get the email subject
    printf("Enter the email subject:\n");
    fgets(email.subject, MAX_SUBJECT_LENGTH, stdin);
    clear_input_buffer();

    // Get the email body
    printf("Enter the email body:\n");
    fgets(email.body, MAX_BODY_LENGTH, stdin);
    clear_input_buffer();

    // Print the email
    printf("\n\n");
    printf("From: %s\n", email.sender);
    printf("To: %s\n", email.recipient);
    printf("Subject: %s\n", email.subject);
    printf("Body:\n%s\n", email.body);

    return 0;
}