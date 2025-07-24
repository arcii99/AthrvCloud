//FormAI DATASET v1.0 Category: Email Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 100
#define MAX_EMAIL_SIZE 100
#define MAX_SUBJECT_SIZE 100
#define MAX_BODY_SIZE 1000

typedef struct email {
    char sender[MAX_EMAIL_SIZE];
    char recipient[MAX_EMAIL_SIZE];
    char subject[MAX_SUBJECT_SIZE];
    char body[MAX_BODY_SIZE];
} Email;

int main() {
    char recipient[MAX_EMAIL_SIZE];
    char subject[MAX_SUBJECT_SIZE];
    char body[MAX_BODY_SIZE];

    printf("Welcome to Unique Email Client!\n");

    printf("Please enter the recipient's email address: ");
    scanf("%s", recipient);

    printf("Please enter the subject of your email: ");
    scanf("%s", subject);

    printf("Please enter the body of your email: ");
    scanf("%s", body);

    Email new_email;

    strcpy(new_email.recipient, recipient);
    strcpy(new_email.subject, subject);
    strcpy(new_email.body, body);
    strcpy(new_email.sender, "unique_email_client@domain.com");

    printf("\nSending Email...\n");

    // Code to send email goes here

    printf("Email sent successfully!\n");

    return 0;
}