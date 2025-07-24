//FormAI DATASET v1.0 Category: Email Client ; Style: romantic
#include <stdio.h>
#include <string.h>

typedef struct {
    char to[50];
    char from[50];
    char subject[100];
    char message[500];
} Email;

void send_email(Email email) {
    printf("To: %s\n", email.to);
    printf("From: %s\n", email.from);
    printf("Subject: %s\n\n", email.subject);

    printf("Dear %s,\n\n", email.to);
    printf("%s\n\n", email.message);
    printf("Love,\nYour Secret Admirer\n");
}

int main() {
    Email email;

    printf("Enter the recipient's email address: ");
    scanf("%s", email.to);

    printf("Enter your email address: ");
    scanf("%s", email.from);

    printf("Enter the subject of the email: ");
    scanf("%s", email.subject);

    printf("Enter your romantic message: ");
    scanf("%s", email.message);

    send_email(email);

    return 0;
}