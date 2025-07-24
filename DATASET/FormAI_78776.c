//FormAI DATASET v1.0 Category: Mailing list manager ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants to set the maximum buffer size and email list size
#define MAX_BUFFER_SIZE 100
#define MAX_EMAIL_LIST_SIZE 1000

// Struct to hold each email in the list
typedef struct email {
    char recipient[MAX_BUFFER_SIZE];
    char subject[MAX_BUFFER_SIZE];
    char message[MAX_BUFFER_SIZE];
} Email;

// Function to print out the help menu
void printHelpMenu() {
    printf("Available commands:\n");
    printf("add [recipient] [subject] [message] - Add a new email to the list\n");
    printf("remove [index] - Remove the email at the specified index\n");
    printf("view [index] - View the email at the specified index\n");
    printf("list - List all emails in the list\n");
    printf("help - Show this help menu\n");
    printf("quit - Quit the program\n");
}

int main() {
    // Create an array to hold the email list and initialize count to 0
    Email emailList[MAX_EMAIL_LIST_SIZE];
    int emailCount = 0;

    // Print out a welcome message
    printf("Welcome to the Email List Manager!\n");
    printf("Type 'help' to see a list of available commands.\n");

    // Loop to read in and process user input
    while (1) {
        // Create a buffer to hold the user input
        char inputBuffer[MAX_BUFFER_SIZE];
        printf("> ");
        fgets(inputBuffer, MAX_BUFFER_SIZE, stdin);

        // Strip the newline character from the input
        int inputLength = strlen(inputBuffer);
        if (inputBuffer[inputLength - 1] == '\n') {
            inputBuffer[inputLength - 1] = '\0';
        }

        // Tokenize the command
        char *commandName = strtok(inputBuffer, " ");

        // Process the command
        if (strcmp(commandName, "add") == 0) {
            // Get the recipient, subject, and message
            char *recipient = strtok(NULL, " ");
            char *subject = strtok(NULL, " ");
            char *message = strtok(NULL, "");

            // Make sure all fields were provided
            if (recipient && subject && message) {
                // Add the email to the list
                Email newEmail;
                strcpy(newEmail.recipient, recipient);
                strcpy(newEmail.subject, subject);
                strcpy(newEmail.message, message);
                emailList[emailCount] = newEmail;
                emailCount++;

                printf("Email added to list.\n");
            } else {
                printf("Usage: add [recipient] [subject] [message]\n");
            }
        } else if (strcmp(commandName, "remove") == 0) {
            // Get the index to remove
            char *indexString = strtok(NULL, "");

            // Make sure the index was provided
            if (indexString) {
                // Convert the index to integer
                int index = atoi(indexString);

                // Make sure the index is valid
                if (index >= 0 && index < emailCount) {
                    // Shift all elements after the removed element to the left
                    for (int i = index; i < emailCount - 1; i++) {
                        emailList[i] = emailList[i + 1];
                    }
                    emailCount--;

                    printf("Email removed from list.\n");
                } else {
                    printf("Invalid index.\n");
                }
            } else {
                printf("Usage: remove [index]\n");
            }
        } else if (strcmp(commandName, "view") == 0) {
            // Get the index to view
            char *indexString = strtok(NULL, "");

            // Make sure the index was provided
            if (indexString) {
                // Convert the index to integer
                int index = atoi(indexString);

                // Make sure the index is valid
                if (index >= 0 && index < emailCount) {
                    printf("Recipient: %s\n", emailList[index].recipient);
                    printf("Subject: %s\n", emailList[index].subject);
                    printf("Message: %s\n", emailList[index].message);
                } else {
                    printf("Invalid index.\n");
                }
            } else {
                printf("Usage: view [index]\n");
            }
        } else if (strcmp(commandName, "list") == 0) {
            // Print out all emails in the list
            for (int i = 0; i < emailCount; i++) {
                printf("Index: %d\n", i);
                printf("Recipient: %s\n", emailList[i].recipient);
                printf("Subject: %s\n", emailList[i].subject);
                printf("Message: %s\n\n", emailList[i].message);
            }
        } else if (strcmp(commandName, "help") == 0) {
            // Print out the help menu
            printHelpMenu();
        } else if (strcmp(commandName, "quit") == 0) {
            // Exit the program
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Unrecognized command.\n");
        }
    }

    return 0;
}