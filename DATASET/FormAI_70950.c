//FormAI DATASET v1.0 Category: Email Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EMAIL_SIZE 100

typedef struct email {
    char* from;
    char* to;
    char* subject;
    char* body;
} Email;

void send_email(Email* email) {
    printf("Sending Email...\n");
    printf("From: %s\n", email->from);
    printf("To: %s\n", email->to);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n\n", email->body);
    printf("Email Sent Successfully!\n");
}

int main() {
    Email* new_email = malloc(sizeof(Email));
    new_email->from = malloc(sizeof(char) * MAX_EMAIL_SIZE);
    new_email->to = malloc(sizeof(char) * MAX_EMAIL_SIZE);
    new_email->subject = malloc(sizeof(char) * MAX_EMAIL_SIZE);
    new_email->body = malloc(sizeof(char) * MAX_EMAIL_SIZE);

    printf("========== NEW EMAIL ==========\n");
    printf("From: ");
    fgets(new_email->from, MAX_EMAIL_SIZE, stdin);
    printf("To: ");
    fgets(new_email->to, MAX_EMAIL_SIZE, stdin);
    printf("Subject: ");
    fgets(new_email->subject, MAX_EMAIL_SIZE, stdin);
    printf("Body: ");
    fgets(new_email->body, MAX_EMAIL_SIZE, stdin);

    send_email(new_email);

    free(new_email->from);
    free(new_email->to);
    free(new_email->subject);
    free(new_email->body);
    free(new_email);

    return 0;
}