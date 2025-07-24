//FormAI DATASET v1.0 Category: Email Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

// Email data structure
typedef struct Email {
    char from[50];
    char to[50];
    char subject[100];
    char body[500];
} Email;

// Function to print menu
void displayMenu() {
    printf("1. Send email\n");
    printf("2. Inbox\n");
    printf("3. Exit\n");
}

int main() {
    Email inbox[MAX_EMAILS];
    int arr_size = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Create new email
                Email new_email;
                printf("From: ");
                scanf("%s", new_email.from);
                printf("To: ");
                scanf("%s", new_email.to);
                printf("Subject: ");
                scanf("%s", new_email.subject);
                printf("Body: ");
                scanf("%s", new_email.body);

                // Add new email to inbox
                inbox[arr_size] = new_email;
                arr_size++;

                printf("Email sent!\n");
                break;
            case 2:
                // Print inbox
                printf("---INBOX---\n");
                for (int i = 0; i < arr_size; i++) {
                    printf("From: %s\n", inbox[i].from);
                    printf("To: %s\n", inbox[i].to);
                    printf("Subject: %s\n", inbox[i].subject);
                    printf("Body: %s\n\n", inbox[i].body);
                }
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}