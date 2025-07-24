//FormAI DATASET v1.0 Category: Email Client ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX_SUBJECT_LENGTH 50
#define MAX_MESSAGE_LENGTH 500

typedef struct Mail {
    char from[50];
    char to[50];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} Mail;

int main() {
    Mail email;

    printf("Welcome to our Email Client!\n");
    printf("Please enter your email address: ");
    fgets(email.from, 50, stdin);
    strtok(email.from, "\n"); // remove the newline character

    printf("Please enter the recipient's email address: ");
    fgets(email.to, 50, stdin);
    strtok(email.to, "\n");

    printf("Please enter the email subject (max 50 characters): ");
    fgets(email.subject, MAX_SUBJECT_LENGTH, stdin);
    strtok(email.subject, "\n");

    printf("Please enter your message (max 500 characters):\n");
    fgets(email.message, MAX_MESSAGE_LENGTH, stdin);
    strtok(email.message, "\n");

    printf("\n\nEmail Preview:\n");
    printf("From: %s\nTo: %s\nSubject: %s\n\n", email.from, email.to, email.subject);
    printf("%s\n", email.message);

    // Code to send the email would go here!

    printf("Email sent successfully!\n");

    return 0;
}