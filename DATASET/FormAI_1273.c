//FormAI DATASET v1.0 Category: Email Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct email {
    char sender[50];
    char recipient[50];
    char subject[100];
    char content[500];
} email_t;

void send_email(email_t email) {
    // implementation for sending email
    printf("Email sent from %s to %s with subject '%s'\n", email.sender, email.recipient, email.subject);
}

int main() {
    email_t email;
    printf("Enter sender email address: ");
    scanf("%s", email.sender);
    printf("Enter recipient email address: ");
    scanf("%s", email.recipient);
    printf("Enter email subject: ");
    fflush(stdin);
    fgets(email.subject, 100, stdin);
    printf("Enter email content: ");
    fflush(stdin);
    fgets(email.content, 500, stdin);
    send_email(email);
    return 0;
}