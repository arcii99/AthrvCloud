//FormAI DATASET v1.0 Category: Email Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* to;
    char* from;
    char* subject;
    char* body;
} Email;

void displayEmail(Email* email) {
    printf("To: %s\n", email->to);
    printf("From: %s\n", email->from);
    printf("Subject: %s\n", email->subject);
    printf("\n%s\n", email->body);
}

void sendEmail(char* to, char* from, char* subject, char* body) {
    Email* email = malloc(sizeof(Email));
    email->to = malloc(strlen(to) + 1);
    strcpy(email->to, to);
    email->from = malloc(strlen(from) + 1);
    strcpy(email->from, from);
    email->subject = malloc(strlen(subject) + 1);
    strcpy(email->subject, subject);
    email->body = malloc(strlen(body) + 1);
    strcpy(email->body, body);
    displayEmail(email);
}

int main() {
    char* to = "john@example.com";
    char* from = "jane@example.com";
    char* subject = "Test Email";
    char* body = "This is a test email sent from the C Email Client.";

    sendEmail(to, from, subject, body);

    return 0;
}