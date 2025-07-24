//FormAI DATASET v1.0 Category: Email Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_SENDER_LENGTH 50
#define MAX_RECIPIENT_LENGTH 50
#define MAX_BODY_LENGTH 500

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char sender[MAX_SENDER_LENGTH];
    char recipient[MAX_RECIPIENT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

int main() {
    // create new Email object
    Email new_email;

    // get subject from user
    printf("Enter subject: ");
    fgets(new_email.subject, MAX_SUBJECT_LENGTH, stdin);

    // get sender from user
    printf("Enter sender: ");
    fgets(new_email.sender, MAX_SENDER_LENGTH, stdin);

    // get recipient from user
    printf("Enter recipient: ");
    fgets(new_email.recipient, MAX_RECIPIENT_LENGTH, stdin);

    // get body from user
    printf("Enter body: ");
    fgets(new_email.body, MAX_BODY_LENGTH, stdin);

    // print out email details
    printf("Subject: %s", new_email.subject);
    printf("Sender: %s", new_email.sender);
    printf("Recipient: %s", new_email.recipient);
    printf("Body: %s", new_email.body);

    return 0;
}