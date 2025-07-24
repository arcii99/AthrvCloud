//FormAI DATASET v1.0 Category: Email Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_SENDER_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char sender[MAX_SENDER_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

int numEmails = 0;
Email emails[MAX_EMAILS];

int main() {
    char input[100];

    while (1) {
        printf("\nEnter a command (type 'help' for a list of commands):\n");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        if (strcmp(input, "help") == 0) {
            printf("Available commands:\n");
            printf("new - Create a new email\n");
            printf("list - List all emails\n");
            printf("read [n] - Read the nth email\n");
            printf("exit - Exit the program\n");
        }
        else if (strcmp(input, "new") == 0) {
            if (numEmails == MAX_EMAILS) {
                printf("Error: Maximum number of emails reached.\n");
            }
            else {
                Email newEmail;
                printf("Enter the subject: ");
                fgets(newEmail.subject, MAX_SUBJECT_LENGTH, stdin);
                newEmail.subject[strcspn(newEmail.subject, "\n")] = '\0';
                printf("Enter the sender: ");
                fgets(newEmail.sender, MAX_SENDER_LENGTH, stdin);
                newEmail.sender[strcspn(newEmail.sender, "\n")] = '\0';
                printf("Enter the body: ");
                fgets(newEmail.body, MAX_BODY_LENGTH, stdin);
                newEmail.body[strcspn(newEmail.body, "\n")] = '\0';
                emails[numEmails] = newEmail;
                numEmails++;
                printf("Email sent!\n");
            }
        }
        else if (strcmp(input, "list") == 0) {
            if (numEmails == 0) {
                printf("No emails to display.\n");
            }
            else {
                for (int i = 0; i < numEmails; i++) {
                    printf("%d. %s\n", i+1, emails[i].subject);
                }
            } 
        }
        else if (strncmp(input, "read", 4) == 0) {
            if (numEmails == 0) {
                printf("No emails to display.\n");
            }
            else {
                int index = atoi(input+5);
                if (index < 1 || index > numEmails) {
                    printf("Invalid email index.\n");
                }
                else {
                    printf("Subject: %s\n", emails[index-1].subject);
                    printf("Sender: %s\n", emails[index-1].sender);
                    printf("Body: %s\n", emails[index-1].body);
                }
            }
        }
        else if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid command. Type 'help' for a list of commands.\n");
        }
    }
    return 0;
}