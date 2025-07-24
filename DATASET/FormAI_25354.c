//FormAI DATASET v1.0 Category: Email Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 1000

// Email struct
typedef struct {
    char sender[MAX_EMAIL_LENGTH];
    char recipient[MAX_EMAIL_LENGTH];
    char subject[MAX_EMAIL_LENGTH];
    char body[MAX_EMAIL_LENGTH];
    time_t timestamp;
} Email;

// Email client struct
typedef struct {
    Email inbox[MAX_EMAILS];
    int num_emails;
} EmailClient;

// Print email information
void print_email(Email email) {
    printf("==============================\n");
    printf("Sender: %s\n", email.sender);
    printf("Recipient: %s\n", email.recipient);
    printf("Subject: %s\n", email.subject);
    printf("Body:\n%s\n", email.body);
    printf("Timestamp: %s\n", ctime(&email.timestamp));
    printf("==============================\n");
}

int main() {
    EmailClient client;
    client.num_emails = 0;
    
    // Receive email
    Email email1;
    strcpy(email1.sender, "alice@gmail.com");
    strcpy(email1.recipient, "bob@gmail.com");
    strcpy(email1.subject, "Hello");
    strcpy(email1.body, "Hi Bob, just wanted to say hello!");
    email1.timestamp = time(NULL);
    client.inbox[client.num_emails++] = email1;
    
    // Send email
    Email email2;
    strcpy(email2.sender, "bob@gmail.com");
    strcpy(email2.recipient, "alice@gmail.com");
    strcpy(email2.subject, "Re: Hello");
    strcpy(email2.body, "Hi Alice, nice to hear from you!");
    email2.timestamp = time(NULL);
    printf("Sending email...\n");
    print_email(email2);
    
    return 0;
}