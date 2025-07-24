//FormAI DATASET v1.0 Category: Email Client ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_INPUT_SIZE 200

void send_email(char subject[], char recipient[], char body[]) {
    // Code to send email.
    printf("Email sent to %s with subject \"%s\" and body \"%s\"\n", recipient, subject, body);
}

int main() {
    char subject[MAX_INPUT_SIZE];
    char recipient[MAX_INPUT_SIZE];
    char body[MAX_INPUT_SIZE];

    printf("Welcome to C Email Client!\n");
    printf("Please enter the subject of your email:\n");
    fgets(subject, MAX_INPUT_SIZE, stdin);

    printf("Please enter the recipient's email address:\n");
    fgets(recipient, MAX_INPUT_SIZE, stdin);

    printf("Please enter the body of your email:\n");
    fgets(body, MAX_INPUT_SIZE, stdin);

    // Strip new line character from input
    subject[strcspn(subject, "\n")] = 0;
    recipient[strcspn(recipient, "\n")] = 0;
    body[strcspn(body, "\n")] = 0;

    printf("\nSending email...\n");
    send_email(subject, recipient, body);

    return 0;
}