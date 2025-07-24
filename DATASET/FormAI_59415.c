//FormAI DATASET v1.0 Category: Email Client ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Email {
    char from[50];
    char to[50];
    char subject[100];
    char message[500];
};

int main() {

    struct Email email;

    printf("Enter sender email address: ");
    fgets(email.from, 50, stdin);

    printf("Enter recipient email address: ");
    fgets(email.to, 50, stdin);

    printf("Enter email subject: ");
    fgets(email.subject, 100, stdin);

    printf("Enter message body: ");
    fgets(email.message, 500, stdin);

    // Code to send email...

    printf("\nEmail Sent!\n");
    printf("From: %s\n", email.from);
    printf("To: %s\n", email.to);
    printf("Subject: %s\n", email.subject);
    printf("Message: %s\n", email.message);

    return 0;
}