//FormAI DATASET v1.0 Category: Email Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 10
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char recipient_email[50];
    char sender_email[50];
} Email;

typedef struct {
    int num_emails;
    Email emails[MAX_EMAILS];
} Inbox;

void send_email(char *recipient_email, char *sender_email, char *subject, char *body, Inbox *inbox) {
    if (inbox->num_emails == MAX_EMAILS) {
        printf("Inbox is full. Email not sent.\n");
        return;
    }
    Email email;
    strcpy(email.recipient_email, recipient_email);
    strcpy(email.sender_email, sender_email);
    strcpy(email.subject, subject);
    strcpy(email.body, body);
    inbox->emails[inbox->num_emails++] = email;
    printf("Email sent to %s\n", recipient_email);
}

void list_emails(Inbox *inbox) {
    if (inbox->num_emails == 0) {
        printf("No emails in inbox.\n");
        return;
    }
    printf("Emails in inbox:\n");
    for (int i=0; i<inbox->num_emails; i++) {
        printf("From: %s\n", inbox->emails[i].sender_email);
        printf("To: %s\n", inbox->emails[i].recipient_email);
        printf("Subject: %s\n", inbox->emails[i].subject);
        printf("Body: %s\n", inbox->emails[i].body);
        printf("\n");
    }
}

int main() {
    Inbox inbox;
    inbox.num_emails = 0;

    send_email("recipient@example.com", "sender@example.com", "Hello world", "This is a test email", &inbox);
    send_email("recipient2@example.com", "sender@example.com", "Greetings", "Hope you're doing well", &inbox);
    list_emails(&inbox);

    return 0;
}