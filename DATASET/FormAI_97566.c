//FormAI DATASET v1.0 Category: Email Client ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LEN 50
#define MAX_BODY_LEN 1000

struct Email {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
};

struct Email emails[MAX_EMAILS];
int num_emails = 0;

void send_email(char *sender, char *recipient, char *subject, char *body) {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Maximum number of emails reached.\n");
        return;
    }

    struct Email new_email;
    strcpy(new_email.sender, sender);
    strcpy(new_email.recipient, recipient);
    strcpy(new_email.subject, subject);
    strcpy(new_email.body, body);

    emails[num_emails++] = new_email;

    printf("Email sent!\n");
}

void receive_emails(char *recipient) {
    int found_emails = 0;

    for (int i = 0; i < num_emails; i++) {
        if (strcmp(emails[i].recipient, recipient) == 0) {
            printf("Email %d:\n", i + 1);
            printf("Sender: %s\n", emails[i].sender);
            printf("Subject: %s\n", emails[i].subject);
            printf("Body: %s\n", emails[i].body);
            found_emails++;
        }
    }

    if (found_emails == 0) {
        printf("No emails found for %s.\n", recipient);
    }
}

int main() {
    send_email("example1@example.com", "example2@example.com", "Test Email 1", "This is a test email.");
    send_email("example2@example.com", "example1@example.com", "Test Email 2", "This is another test email.");

    receive_emails("example1@example.com");

    return 0;
}