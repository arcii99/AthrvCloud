//FormAI DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 80
#define MAX_SUBJECT_LENGTH 50

typedef struct Email {
    char subject[MAX_SUBJECT_LENGTH];
    char sender[MAX_LINE_LENGTH];
    char recipient[MAX_LINE_LENGTH];
    char date[MAX_LINE_LENGTH];
    char message[MAX_LINES][MAX_LINE_LENGTH];
    int line_count;
} Email;

void print_email(Email *email)
{
    // Print email metadata
    printf("Subject: %s\n", email->subject);
    printf("From: %s\n", email->sender);
    printf("To: %s\n", email->recipient);
    printf("Date: %s\n", email->date);

    // Print email message
    for (int i = 0; i < email->line_count; i++) {
        printf("%s\n", email->message[i]);
    }

    // Print footer
    printf("--\n");
}

int main()
{
    // Initialize variables
    char input[MAX_LINE_LENGTH + 1]; // +1 for null terminator
    char command;
    Email current_email;
    current_email.line_count = 0;

    // Print header
    printf("Welcome to the C email client. Type 'help' to see a list of available commands.\n");

    // Main loop
    while (1) {
        printf("> ");
        fgets(input, MAX_LINE_LENGTH + 1, stdin);

        // Remove newline character from input
        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        // Parse command
        if (strcmp(input, "exit") == 0) {
            exit(0);
        } else if (strcmp(input, "help") == 0) {
            printf("Available commands:\n");
            printf("  - exit: exit the program\n");
            printf("  - help: display a list of available commands\n");
            printf("  - new: start composing a new email\n");
            printf("  - from: set the sender of the current email\n");
            printf("  - to: set the recipient of the current email\n");
            printf("  - subject: set the subject of the current email\n");
            printf("  - date: set the date of the current email\n");
            printf("  - message: add a new line to the message of the current email\n");
            printf("  - send: send the current email\n");
        } else if (strcmp(input, "new") == 0) {
            // Initialize new email
            memset(current_email.subject, 0, MAX_SUBJECT_LENGTH);
            memset(current_email.sender, 0, MAX_LINE_LENGTH);
            memset(current_email.recipient, 0, MAX_LINE_LENGTH);
            memset(current_email.date, 0, MAX_LINE_LENGTH);
            for (int i = 0; i < MAX_LINES; i++) {
                memset(current_email.message[i], 0, MAX_LINE_LENGTH);
            }
            current_email.line_count = 0;

            printf("Started a new email.\n");
        } else if (strcmp(input, "from") == 0) {
            printf("Sender: ");
            fgets(current_email.sender, MAX_LINE_LENGTH, stdin);
            if (current_email.sender[strlen(current_email.sender) - 1] == '\n') {
                current_email.sender[strlen(current_email.sender) - 1] = '\0';
            }
        } else if (strcmp(input, "to") == 0) {
            printf("Recipient: ");
            fgets(current_email.recipient, MAX_LINE_LENGTH, stdin);
            if (current_email.recipient[strlen(current_email.recipient) - 1] == '\n') {
                current_email.recipient[strlen(current_email.recipient) - 1] = '\0';
            }
        } else if (strcmp(input, "subject") == 0) {
            printf("Subject: ");
            fgets(current_email.subject, MAX_SUBJECT_LENGTH, stdin);
            if (current_email.subject[strlen(current_email.subject) - 1] == '\n') {
                current_email.subject[strlen(current_email.subject) - 1] = '\0';
            }
        } else if (strcmp(input, "date") == 0) {
            printf("Date: ");
            fgets(current_email.date, MAX_LINE_LENGTH, stdin);
            if (current_email.date[strlen(current_email.date) - 1] == '\n') {
                current_email.date[strlen(current_email.date) - 1] = '\0';
            }
        } else if (strcmp(input, "message") == 0) {
            if (current_email.line_count >= MAX_LINES) {
                printf("Error: message is too long.\n");
            } else {
                printf("Line %d: ", current_email.line_count+1);
                fgets(current_email.message[current_email.line_count], MAX_LINE_LENGTH, stdin);
                if (current_email.message[current_email.line_count][strlen(current_email.message[current_email.line_count]) - 1] == '\n') {
                    current_email.message[current_email.line_count][strlen(current_email.message[current_email.line_count]) - 1] = '\0';
                }
                current_email.line_count++;
            }
        } else if (strcmp(input, "send") == 0) {
            // Validate email
            if (strlen(current_email.sender) == 0) {
                printf("Error: sender cannot be empty.\n");
            } else if (strlen(current_email.recipient) == 0) {
                printf("Error: recipient cannot be empty.\n");
            } else if (strlen(current_email.subject) == 0) {
                printf("Error: subject cannot be empty.\n");
            } else if (strlen(current_email.date) == 0) {
                printf("Error: date cannot be empty.\n");
            } else if (current_email.line_count == 0) {
                printf("Error: message cannot be empty.\n");
            } else {
                printf("Sending email:\n");
                print_email(&current_email);
            }
        } else if (strlen(input) > 0) {
            printf("Error: unrecognized command.\n");
        }
    }

    return 0;
}