//FormAI DATASET v1.0 Category: Email Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Email {
    char sender[50];
    char recipient[50];
    char subject[100];
    char message[1000];
};

void sendEmail(struct Email email) {
    printf("Sending email... \n");
    printf("From: %s\n", email.sender);
    printf("To: %s\n", email.recipient);
    printf("Subject: %s\n", email.subject);
    printf("Message: %s\n", email.message);
}

int main() {

    struct Email email;

    printf("Enter sender's email address: ");
    scanf("%s", email.sender);

    printf("Enter recipient's email address: ");
    scanf("%s", email.recipient);

    printf("Enter email subject: ");
    scanf("%s", email.subject);

    printf("Enter email message: ");
    scanf("%s", email.message);

    sendEmail(email);

    return 0;
}