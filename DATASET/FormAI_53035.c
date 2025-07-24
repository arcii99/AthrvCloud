//FormAI DATASET v1.0 Category: Email Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 500

struct Email {
    char sender[50];
    char recipient[50];
    char subject[100];
    char message[MAX_MESSAGE_LENGTH];
};

void send_email(struct Email email) {
    printf("\n\nEmail sent successfully!");
    printf("\nSender: %s", email.sender);
    printf("\nRecipient: %s", email.recipient);
    printf("\nSubject: %s", email.subject);
    printf("\nMessage: %s", email.message);
}

int main() {
    printf("Welcome to Genius Email Client!\n\n");
    
    struct Email email;
    
    printf("Please enter your email address: ");
    scanf("%s", email.sender);
    
    printf("\n\nPlease enter recipient's email address: ");
    scanf("%s", email.recipient);
    
    printf("\n\nPlease enter the subject of the email: ");
    scanf("%s", email.subject);
    
    printf("\n\nPlease enter the message (maximum 500 characters): ");
    getchar(); // clear input buffer
    fgets(email.message, MAX_MESSAGE_LENGTH, stdin);
    
    // remove trailing newline character from message string
    email.message[strcspn(email.message, "\n")] = '\0';
    
    // send email
    send_email(email);
    
    return 0;
}