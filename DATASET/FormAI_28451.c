//FormAI DATASET v1.0 Category: Email Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 500

typedef struct {
    char from[50];
    char to[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

void send_email(Email email) {
    printf("Sending email...\n");
    printf("From: %s\n", email.from);
    printf("To: %s\n", email.to);
    printf("Subject: %s\n", email.subject);
    printf("Body: %s\n", email.body);
    printf("Email sent successfully.\n");
}

int main() {
    // Example email
    Email email;
    strcpy(email.from, "john@example.com");
    strcpy(email.to, "jane@example.com");
    strcpy(email.subject, "Greetings!");
    strcpy(email.body, "Hi Jane, how are you?");

    // Verify email fields
    if (strlen(email.from) == 0 || strlen(email.to) == 0 || strlen(email.subject) == 0 || strlen(email.body) == 0) {
        printf("Error: One or more email fields are empty.\n");
        return 1;
    }

    // Send email
    send_email(email);

    return 0;
}