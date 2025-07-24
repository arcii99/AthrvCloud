//FormAI DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char sender[100];
    char recipient[100];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} email;

typedef struct {
    email emails[MAX_EMAILS];
    int count;
} email_database;

void print_menu() {
    printf("1. Compose Email\n");
    printf("2. View Inbox\n");
    printf("3. View Sent Emails\n");
    printf("4. Exit\n");
}

void compose_email(email_database* db) {
    email new_email;
    printf("Enter Sender Name:\n");
    fgets(new_email.sender, 100, stdin);
    printf("Enter Recipient Name:\n");
    fgets(new_email.recipient, 100, stdin);
    printf("Enter Subject Line (max 100 characters):\n");
    fgets(new_email.subject, MAX_SUBJECT_LENGTH, stdin);
    printf("Enter Email Message (max 1000 characters):\n");
    fgets(new_email.message, MAX_MESSAGE_LENGTH, stdin);
    db->emails[db->count] = new_email;
    db->count++;
    printf("Email sent successfully.\n");
}

void view_inbox(email_database* db) {
    int i;
    printf("Inbox:\n");
    for (i = 0; i < db->count; i++) {
        if (strcmp(db->emails[i].recipient, "you") == 0) {
            printf("From: %sSubject: %s\n", db->emails[i].sender, db->emails[i].subject);
            printf("%s\n", db->emails[i].message);
        }
    }
}

void view_sent_emails(email_database* db) {
    int i;
    printf("Sent Emails:\n");
    for (i = 0; i < db->count; i++) {
        if (strcmp(db->emails[i].sender, "you") == 0) {
            printf("To: %sSubject: %s\n", db->emails[i].recipient, db->emails[i].subject);
            printf("%s\n", db->emails[i].message);
        }
    }
}

int main() {
    email_database db;
    db.count = 0;
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                compose_email(&db);
                break;
            case 2:
                view_inbox(&db);
                break;
            case 3:
                view_sent_emails(&db);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}