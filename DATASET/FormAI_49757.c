//FormAI DATASET v1.0 Category: Email Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BODY_SIZE 1000
#define MAX_SUBJECT_SIZE 50
#define MAX_EMAIL_SIZE 200

struct email {
    char subject[MAX_SUBJECT_SIZE];
    char body[MAX_BODY_SIZE];
    char receiver[MAX_EMAIL_SIZE];
};

typedef struct email Email;

void send_email(Email *email) {
    // Code to send email using SMTP protocol
    printf("Email sent successfully to %s\n", email->receiver);
}

int main() {
    Email email;
    memset(&email, 0, sizeof(email));
    printf("Enter receiver email address: ");
    scanf("%s", email.receiver);
    printf("Enter email subject: ");
    scanf(" %[^\n]s", email.subject);
    printf("Enter email body: ");
    scanf(" %[^\n]s", email.body);
    send_email(&email);
    printf("Press any key to exit...");
    getchar();
    return 0;
}