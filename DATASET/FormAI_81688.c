//FormAI DATASET v1.0 Category: Email Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_SIZE 100
#define MAX_BODY_SIZE 1000

typedef struct {
    char username[20];
    char password[20];
} Account;

typedef struct {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_SIZE];
    char body[MAX_BODY_SIZE];
} Email;

int main() {
    Account account;
    printf("Email Client Login\n");
    printf("Enter username: ");
    scanf("%s", account.username);
    printf("Enter password: ");
    scanf("%s", account.password);

    // Authenticate with email server here

    Email email;
    printf("Compose Email\n");
    printf("To: ");
    scanf("%s", email.recipient);
    printf("Subject: ");
    scanf("%s", email.subject);
    printf("Body: ");
    scanf("%s", email.body);

    // Send email here

    printf("Email sent successfully!\n");

    return 0;
}