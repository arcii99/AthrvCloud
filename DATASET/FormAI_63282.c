//FormAI DATASET v1.0 Category: Email Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BODY_LENGTH 500
#define MAX_SUBJECT_LENGTH 50

typedef struct {
    char from[50];
    char to[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

int main() {
    char fromAddress[50];
    char toAddress[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];

    printf("Enter your email address (From): ");
    scanf("%s", fromAddress);

    printf("Enter recipient email address (To): ");
    scanf("%s", toAddress);

    printf("Enter subject (max length 50): ");
    scanf("%s", subject);

    printf("Enter email body (max length 500): ");
    scanf(" %[^\n]s", body);

    Email email;
    strcpy(email.from, fromAddress);
    strcpy(email.to, toAddress);
    strcpy(email.subject, subject);
    strcpy(email.body, body);

    // Sending Email
    printf("Sending email...\n");
    printf("From: %s\nTo: %s\nSubject: %s\nBody: %s\n", email.from, email.to, email.subject, email.body);
    printf("Email Sent!\n");

    return 0;
}