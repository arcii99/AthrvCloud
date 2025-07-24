//FormAI DATASET v1.0 Category: Email Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EMAIL_LENGTH 1000
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct email {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

bool send_email(Email *email) {
    // Code to send email goes here
    printf("\nEmail sent from %s to %s with subject %s\n", email->from, email->to, email->subject);
    return true; // Return true if email was successfully sent
}

int main() {
    Email email;
    strcpy(email.from, "sender@example.com");
    strcpy(email.to, "recipient@example.com");
    strcpy(email.subject, "This is the subject");
    strcpy(email.body, "Hello,\n\nHow are you?\n\nRegards,\nSender");

    if (send_email(&email)) {
        printf("Email sent successfully\n");
    } else {
        printf("Failed to send email\n");
    }

    return 0;
}