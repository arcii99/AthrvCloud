//FormAI DATASET v1.0 Category: Email Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_SIZE 100
#define MAX_BODY_SIZE 1000

typedef struct Email {
    char subject[MAX_SUBJECT_SIZE];
    char body[MAX_BODY_SIZE];
} Email;

void send_email(Email *email, char *recipient) {
    printf("Sending email to %s\n", recipient);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);
}

int main() {
    char recipient[30];
    Email email;

    printf("Enter email recipient: ");
    scanf("%s", recipient);
    printf("Enter email subject: ");
    getchar(); // Clear input buffer before reading fgets
    fgets(email.subject, MAX_SUBJECT_SIZE, stdin);
    printf("Enter email body: ");
    fgets(email.body, MAX_BODY_SIZE, stdin);

    // Remove newline character from email subject and body
    email.subject[strcspn(email.subject, "\n")] = '\0';
    email.body[strcspn(email.body, "\n")] = '\0';

    send_email(&email, recipient);

    return 0;
}