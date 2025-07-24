//FormAI DATASET v1.0 Category: Email Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print a funny error message
void printError() {
    printf("Oh no, you made a mistake! But don't worry,\n");
    printf("I'm a C Email Client, not a therapist, so I'll just show you the code instead.\n\n");
}

// Function to send an email
void sendEmail(char* to, char* subject, char* message) {
    printf("Sending email to %s with subject '%s' and message:\n", to, subject);
    printf("%s\n\n", message);
    printf("Email sent successfully!\n");
}

int main() {
    // Welcome message
    printf("Welcome to the C Email Client!\n");
    printf("Type 'help' to see a list of available commands.\n\n");

    // Command loop
    while (1) {
        // Get user input
        char input[100];
        printf("> ");
        fgets(input, 100, stdin);
        strtok(input, "\n");

        if (strcmp(input, "help") == 0) {
            // Help menu
            printf("Available commands:\n");
            printf("send - Send an email\n");
            printf("exit - Exit the program\n\n");
        } else if (strcmp(input, "send") == 0) {
            // Get email details
            char to[50];
            printf("To: ");
            fgets(to, 50, stdin);
            strtok(to, "\n");

            char subject[50];
            printf("Subject: ");
            fgets(subject, 50, stdin);
            strtok(subject, "\n");

            char message[300];
            printf("Message: ");
            fgets(message, 300, stdin);
            strtok(message, "\n");

            // Send the email
            sendEmail(to, subject, message);
        } else if (strcmp(input, "exit") == 0) {
            // Exit the program
            printf("Goodbye!\n");
            exit(0);
        } else {
            // Invalid command
            printError();
            printf("Invalid command: '%s'\n", input);
        }
    }

    return 0;
}