//FormAI DATASET v1.0 Category: Email Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

// email structure
struct Email {
    char to[MAX_LEN];
    char from[MAX_LEN];
    char subject[MAX_LEN];
    char body[MAX_LEN];
};

// function to send email
void send_email(struct Email *email) {
    // logic to send the email
    printf("Email sent: \nTo: %s\nFrom: %s\nSubject: %s\nBody: %s\n", email->to, email->from, email->subject, email->body);
}

int main() {
    printf("Welcome to C Email Client\n");
    
    // create email
    struct Email email;
    printf("\nEnter recipient email address: ");
    fgets(email.to, MAX_LEN, stdin);
    email.to[strcspn(email.to, "\n")] = 0; // remove newline character

    printf("\nEnter your email address: ");
    fgets(email.from, MAX_LEN, stdin);
    email.from[strcspn(email.from, "\n")] = 0; // remove newline character

    printf("\nEnter email subject: ");
    fgets(email.subject, MAX_LEN, stdin);
    email.subject[strcspn(email.subject, "\n")] = 0; // remove newline character

    printf("\nEnter email body: ");
    fgets(email.body, MAX_LEN, stdin);
    email.body[strcspn(email.body, "\n")] = 0; // remove newline character

    // send email
    send_email(&email);

    return 0;
}