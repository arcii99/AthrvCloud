//FormAI DATASET v1.0 Category: Email Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LEN 100
#define MAX_BODY_LEN 1000
#define MAX_EMAILS 1000

struct email {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
};

struct inbox {
    struct email emails[MAX_EMAILS];
    int count;
};

void viewInbox(struct inbox inbox) {
    printf("\nYour Inbox:\n\n");
    for (int i = 0; i < inbox.count; i++) {
        struct email email = inbox.emails[i];
        printf("From: %s\nTo: %s\nSubject: %s\n%s\n\n", email.sender, email.recipient, email.subject, email.body);
    }
}

void viewEmail(struct email email) {
    printf("\nFrom: %s\nTo: %s\nSubject: %s\n%s\n\n", email.sender, email.recipient, email.subject, email.body);
}

void sendEmail(struct inbox *inbox, struct email email) {
    if (inbox->count < MAX_EMAILS) {
        inbox->emails[inbox->count] = email;
        inbox->count++;
        printf("\nEmail sent!\n");
    } else {
        printf("\nError: Inbox is full!\n");
    }
}

int main() {
    struct inbox inbox;
    inbox.count = 0;

    while (1) {
        printf("\nWelcome to Happy Mail! What would you like to do?\n");
        printf("1. View Inbox\n");
        printf("2. Read Email\n");
        printf("3. Send Email\n");
        printf("4. Quit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            viewInbox(inbox);
        } else if (choice == 2) {
            if (inbox.count == 0) {
                printf("\nInbox is empty!\n");
            } else {
                printf("\nEnter email number: ");
                int emailNum;
                scanf("%d", &emailNum);
                if (emailNum <= 0 || emailNum > inbox.count) {
                    printf("\nError: Invalid email number!\n");
                } else {
                    viewEmail(inbox.emails[emailNum-1]);
                }
            }
        } else if (choice == 3) {
            struct email newEmail;
            printf("\nEnter recipient: ");
            scanf("%s", newEmail.recipient);
            printf("\nEnter subject: ");
            getchar();
            fgets(newEmail.subject, MAX_SUBJECT_LEN, stdin);
            printf("\nEnter body: ");
            fgets(newEmail.body, MAX_BODY_LEN, stdin);
            strcpy(newEmail.sender, "happy_mail@happy.com");
            sendEmail(&inbox, newEmail);
        } else if (choice == 4) {
            printf("\nThank you for using Happy Mail! Goodbye!\n");
            break;
        } else {
            printf("\nInvalid choice!\n");
        }
    }

    return 0;
}