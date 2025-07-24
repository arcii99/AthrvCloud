//FormAI DATASET v1.0 Category: Email Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 500

typedef struct email {
    char recipient[50];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} Email;

void send_email(Email *email) {
    printf("To: %s\n", email->recipient);
    printf("Subject: %s\n", email->subject);
    printf("Message: %s\n", email->message);
}

int main() {
    Email email;
    char recipient[50], subject[MAX_SUBJECT_LENGTH], message[MAX_MESSAGE_LENGTH];

    printf("Enter recipient: ");
    scanf("%s", recipient);
    printf("Enter subject: ");
    scanf(" %[^\n]s", subject);
    printf("Enter message: ");
    scanf(" %[^\n]s", message);

    strcpy(email.recipient, recipient);
    strcpy(email.subject, subject);
    strcpy(email.message, message);

    send_email(&email);

    return 0;
}