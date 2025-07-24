//FormAI DATASET v1.0 Category: Email Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LEN 50
#define MAX_BODY_LEN 500
#define MAX_PLAYER_NAME_LEN 20

typedef struct {
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
    char sender[MAX_PLAYER_NAME_LEN];
    char receiver[MAX_PLAYER_NAME_LEN];
} Email;

typedef struct {
    Email emails[MAX_EMAILS];
    int num_emails;
} EmailDatabase;

void print_email(Email *email) {
    printf("From: %s\nTo: %s\nSubject: %s\nBody: %s\n", email->sender, email->receiver, email->subject, email->body);
}

void print_inbox(EmailDatabase *db, char *player_name) {
    printf("Inbox for %s:\n", player_name);
    for (int i = 0; i < db->num_emails; i++) {
        if (strcmp(db->emails[i].receiver, player_name) == 0) {
            print_email(&db->emails[i]);
        }
    }
}

void print_sent(EmailDatabase *db, char *player_name) {
    printf("Sent emails for %s:\n", player_name);
    for (int i = 0; i < db->num_emails; i++) {
        if (strcmp(db->emails[i].sender, player_name) == 0) {
            print_email(&db->emails[i]);
        }
    }
}

void send_email(EmailDatabase *db, char *sender, char *receiver, char *subject, char *body) {
    if (db->num_emails < MAX_EMAILS) {
        Email *email = &db->emails[db->num_emails];
        db->num_emails++;
        strcpy(email->sender, sender);
        strcpy(email->receiver, receiver);
        strcpy(email->subject, subject);
        strcpy(email->body, body);
        printf("Sent email from %s to %s with subject '%s'\n", sender, receiver, subject);
    } else {
        printf("Email database is full!\n");
    }
}

int main() {
    EmailDatabase db;
    db.num_emails = 0;

    printf("Welcome to the multiplayer email client!\n");

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Check inbox\n");
        printf("2. Check sent emails\n");
        printf("3. Send email\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            char player_name[MAX_PLAYER_NAME_LEN];
            printf("Whose inbox would you like to check?\n");
            scanf("%s", player_name);
            print_inbox(&db, player_name);
        } else if (choice == 2) {
            char player_name[MAX_PLAYER_NAME_LEN];
            printf("Whose sent emails would you like to check?\n");
            scanf("%s", player_name);
            print_sent(&db, player_name);
        } else if (choice == 3) {
            char sender[MAX_PLAYER_NAME_LEN];
            printf("Who is sending the email?\n");
            scanf("%s", sender);
            char receiver[MAX_PLAYER_NAME_LEN];
            printf("Who is receiving the email?\n");
            scanf("%s", receiver);
            char subject[MAX_SUBJECT_LEN];
            printf("What is the subject of the email?\n");
            scanf("%s", subject);
            char body[MAX_BODY_LEN];
            printf("What is the body of the email?\n");
            scanf("%s", body);
            send_email(&db, sender, receiver, subject, body);
        } else if (choice == 4) {
            printf("Goodbye!\n");
            return 0;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}