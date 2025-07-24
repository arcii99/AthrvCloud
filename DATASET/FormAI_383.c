//FormAI DATASET v1.0 Category: Email Client ; Style: calm
/* A Unique C Email Client Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024 /* Buffer size for storing messages */

/**
 * Struct for storing email message data
 * - from: email address of sender
 * - to: email address of recipient
 * - subject: message subject
 * - body: message body
 */
typedef struct {
    char from[256];
    char to[256];
    char subject[256];
    char body[BUFFER_SIZE];
} Email;

/* Function declarations */
void clear_input_buffer();
void print_menu();
void send_email(Email *email);

/* Main function */
int main() {
    Email email; /* Declare an instance of the Email struct */

    /* Display the menu and prompt the user for input */
    char choice;
    do {
        print_menu();

        printf("Enter your choice: ");
        choice = getchar();
        clear_input_buffer();

        switch (choice) {
            case '1': {
                printf("From: ");
                fgets(email.from, 256, stdin);
                printf("To: ");
                fgets(email.to, 256, stdin);
                printf("Subject: ");
                fgets(email.subject, 256, stdin);
                printf("Body: ");
                fgets(email.body, BUFFER_SIZE, stdin);

                /* Remove trailing newlines from the input strings */
                email.from[strcspn(email.from, "\n")] = '\0';
                email.to[strcspn(email.to, "\n")] = '\0';
                email.subject[strcspn(email.subject, "\n")] = '\0';
                email.body[strcspn(email.body, "\n")] = '\0';

                send_email(&email);
                break;
            }
            case '2': {
                printf("Exiting the program...\n");
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }

    } while (choice != '2');

    return 0;
}

/**
 * Clear the input buffer by reading and discarding any extra characters
 * after the first newline character.
 */
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Print the program menu.
 */
void print_menu() {
    printf("\n");
    printf("C Email Client\n");
    printf("===================================\n");
    printf("1. Send email\n");
    printf("2. Quit\n");
    printf("===================================\n");
}

/**
 * Send the email by printing its data to the console.
 */
void send_email(Email *email) {
    printf("\n");
    printf("Sending email...\n");
    printf("===================================\n");
    printf("From: %s\n", email->from);
    printf("To: %s\n", email->to);
    printf("Subject: %s\n", email->subject);
    printf("-----------------------------------\n");
    printf("%s\n", email->body);
    printf("===================================\n");
}