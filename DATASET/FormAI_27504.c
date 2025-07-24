//FormAI DATASET v1.0 Category: Email Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 500

struct email {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
};

int main() {
    struct email new_email;
    char user_input[100];

    printf("Welcome to GratefulMail! Let's send an email.\n");

    printf("Please enter the email sender:");
    scanf("%s", new_email.sender);

    printf("Please enter the email recipient:");
    scanf("%s", new_email.recipient);

    printf("Please enter the email subject (max 100 chars):");
    scanf("%s", new_email.subject);

    printf("Please enter the email body (max 500 chars):");
    scanf("%s", new_email.body);

    printf("Do you want to send this email? (yes/no)");
    scanf("%s", user_input);

    if (strcmp(user_input, "yes") == 0) {
        printf("Sending email...\n");
        // Code to send email would go here
        printf("Email sent! Thank you for using GratefulMail.\n");
    } else {
        printf("Email not sent. Thank you for using GratefulMail.\n");
    }

    return 0;
}