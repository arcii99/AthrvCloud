//FormAI DATASET v1.0 Category: Email Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_SIZE 1024
#define MAX_SUBJECT_SIZE 256

/* Function to validate email address */
int is_valid_email(char* email) {
    int dot_count = 0;
    int at_count = 0;
    int i;
    int length = strlen(email);
    for (i=0; i<length; i++) {
        if (!isalnum(email[i])) {
            if (email[i] == '.') {
                dot_count++;
            }
            else if (email[i] == '@') {
                at_count++;
            }
            else {
                return 0;  // Invalid character found
            }
        }
    }
    if (dot_count < 1 || at_count != 1) {
        return 0;  // Invalid email format
    }
    return 1;  // Valid email format
}

/* Function to send email */
void send_email(char* email, char* subject, char* message) {
    if (!is_valid_email(email)) {
        printf("Invalid email address\n");
        return;
    }
    printf("Sending email to %s with subject '%s'\n", email, subject);
    printf("Message: %s\n", message);
    // Code to actually send email would go here
}

/* Main function */
int main(void) {
    char email[MAX_EMAIL_SIZE];
    char subject[MAX_SUBJECT_SIZE];
    char message[MAX_EMAIL_SIZE];
    int i;

    /* Get recipient's email address */
    printf("Enter recipient's email address: ");
    fgets(email, MAX_EMAIL_SIZE, stdin);
    // Remove trailing newline from input
    for (i=0; i<MAX_EMAIL_SIZE; i++) {
        if (email[i] == '\n') {
            email[i] = '\0';
            break;
        }
    }

    /* Get email subject */
    printf("Enter email subject: ");
    fgets(subject, MAX_SUBJECT_SIZE, stdin);
    // Remove trailing newline from input
    for (i=0; i<MAX_SUBJECT_SIZE; i++) {
        if (subject[i] == '\n') {
            subject[i] = '\0';
            break;
        }
    }

    /* Get email message */
    printf("Enter email message: ");
    fgets(message, MAX_EMAIL_SIZE, stdin);

    /* Send email */
    send_email(email, subject, message);

    return 0;
}