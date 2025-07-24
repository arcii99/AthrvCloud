//FormAI DATASET v1.0 Category: Email Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct email {
    char to[50];
    char cc[50];
    char subject[100];
    char body[500];
} Email;

typedef struct node {
    Email data;
    struct node *next;
} Node;

Node *inboxHead = NULL;
Node *sentHead = NULL;

void printEmail(Email email) {
    printf("To: %s\n", email.to);
    printf("Cc: %s\n", email.cc);
    printf("Subject: %s\n", email.subject);
    printf("Body: %s\n", email.body);
    printf("\n");
}

void addEmail(Node **head, Email email) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = email;
    newNode->next = *head;
    *head = newNode;
}

void displayEmails(Node *head) {
    if (!head) {
        printf("No emails to display\n");
        return;
    }

    Node *current = head;
    while (current) {
        printEmail(current->data);
        current = current->next;
    }
}

void deleteEmail(Node **head, char *subject) {
    if (!(*head)) {
        printf("No emails to delete\n");
        return;
    }

    Node *current = *head;
    Node *prev = NULL;

    while (current) {
        if (strcmp(current->data.subject, subject) == 0) {
            if (!prev) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            printf("Email deleted successfully\n");
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Email with subject '%s' not found\n", subject);
}

void composeEmail() {
    Email email;

    printf("Enter To address: ");
    scanf("%s", email.to);

    printf("Enter Cc address: ");
    scanf("%s", email.cc);

    printf("Enter subject: ");
    scanf("%s", email.subject);

    printf("Enter body: ");
    getchar();
    fgets(email.body, sizeof(email.body), stdin);

    addEmail(&sentHead, email);
    printf("Email sent successfully\n");
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Compose Email\n");
    printf("2. View Inbox\n");
    printf("3. View Sent Emails\n");
    printf("4. Delete Email\n");
    printf("5. Exit\n");
}

int main() {
    int option;

    do {
        displayMenu();
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                composeEmail();
                break;

            case 2:
                printf("\nInbox:\n");
                displayEmails(inboxHead);
                break;

            case 3:
                printf("\nSent Emails:\n");
                displayEmails(sentHead);
                break;

            case 4:
                char subject[100];
                printf("Enter subject to delete: ");
                scanf("%s", subject);
                deleteEmail(&inboxHead, subject);
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid option\n");
        }
    } while (option != 5);

    return 0;
}