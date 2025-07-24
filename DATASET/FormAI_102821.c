//FormAI DATASET v1.0 Category: Mailing list manager ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct email {
    char address[50];
    struct email *next;
} Email;

Email *head = NULL;

void addEmail(char address[]) {
    Email *newEmail = (Email*) malloc(sizeof(Email));
    strcpy(newEmail->address, address);
    newEmail->next = NULL;

    if (head == NULL) { // If list is empty, set new email as head
        head = newEmail;
    } else { // Otherwise, add new email to end of list
        Email *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newEmail;
    }
}

void removeEmail(char address[]) {
    Email *current = head;
    Email *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->address, address) == 0) {
            if (prev == NULL) { // If email is head, set next email as head
                head = current->next;
            } else { // Otherwise, remove email from list
                prev->next = current->next;
            }
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

void printEmails() {
    Email *current = head;

    if (current == NULL) {
        printf("No emails in list\n");
    } else {
        printf("Emails in list:\n");
        while (current != NULL) {
            printf("%s\n", current->address);
            current = current->next;
        }
    }
}

int main() {
    char input[50];

    printf("Welcome to the mailing list manager!\n");

    while (1) { // Loop until user chooses to exit
        printf("\nEnter a command (add, remove, print, exit): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        if (strcmp(input, "add") == 0) {
            printf("Enter email address to add: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0; // Remove newline character
            addEmail(input);
            printf("Email address added to list\n");
        } else if (strcmp(input, "remove") == 0) {
            printf("Enter email address to remove: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0; // Remove newline character
            removeEmail(input);
            printf("Email address removed from list\n");
        } else if (strcmp(input, "print") == 0) {
            printEmails();
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    printf("Exiting mailing list manager\n");

    return 0;
}