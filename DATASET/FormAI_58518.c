//FormAI DATASET v1.0 Category: Email Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_SIZE 1024
#define MAX_USERNAME_SIZE 20
#define MAX_PASSWORD_SIZE 20

typedef struct Email {
    char sender[MAX_USERNAME_SIZE];
    char receiver[MAX_USERNAME_SIZE];
    char subject[MAX_EMAIL_SIZE];
    char body[MAX_EMAIL_SIZE];
} Email;

int emailCount = 0;
Email emailList[MAX_EMAIL_SIZE];

void printMenu() {
    printf("1. Compose Email\n");
    printf("2. View Inbox\n");
    printf("3. Exit\n");
}

void composeEmail() {
    Email newEmail;
    printf("Enter sender username (max. %d characters): ", MAX_USERNAME_SIZE);
    fgets(newEmail.sender, MAX_USERNAME_SIZE, stdin);
    newEmail.sender[strcspn(newEmail.sender, "\n")] = '\0';
    printf("Enter receiver username (max. %d characters): ", MAX_USERNAME_SIZE);
    fgets(newEmail.receiver, MAX_USERNAME_SIZE, stdin);
    newEmail.receiver[strcspn(newEmail.receiver, "\n")] = '\0';
    printf("Enter email subject (max. %d characters): ", MAX_EMAIL_SIZE);
    fgets(newEmail.subject, MAX_EMAIL_SIZE, stdin);
    newEmail.subject[strcspn(newEmail.subject, "\n")] = '\0';
    printf("Enter email body (max. %d characters): ", MAX_EMAIL_SIZE);
    fgets(newEmail.body, MAX_EMAIL_SIZE, stdin);
    newEmail.body[strcspn(newEmail.body, "\n")] = '\0';
    emailList[emailCount++] = newEmail;
    printf("Email sent successfully!\n");
}

void viewInbox() {
    int i;
    for (i = 0; i < emailCount; i++) {
        printf("Email #%d:\n", i + 1);
        printf("From: %s\n", emailList[i].sender);
        printf("To: %s\n", emailList[i].receiver);
        printf("Subject: %s\n", emailList[i].subject);
        printf("Body: %s\n", emailList[i].body);
    }
}

int main() {
    int choice;
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline from input buffer
        switch (choice) {
            case 1:
                composeEmail();
                break;
            case 2:
                viewInbox();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again!\n");
                break;
        }
    } while (choice != 3);
    return 0;
}