//FormAI DATASET v1.0 Category: Email Client ; Style: scalable
/* A simple email client in C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 256
#define MAX_SUBJECT_LENGTH 128
#define MAX_BODY_LENGTH 1024

typedef struct {
    char from[MAX_EMAIL_LENGTH];
    char to[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

void send_email(Email *mail) {
    // Code to send email via SMTP server
    printf("Email sent!\n");
}

int main() {
    Email *mail = malloc(sizeof(Email));

    // Get user input for email fields
    printf("Enter your email address: ");
    fgets(mail->from, MAX_EMAIL_LENGTH, stdin);
    mail->from[strcspn(mail->from, "\n")] = 0;

    printf("Enter recipient's email address: ");
    fgets(mail->to, MAX_EMAIL_LENGTH, stdin);
    mail->to[strcspn(mail->to, "\n")] = 0;

    printf("Enter email subject: ");
    fgets(mail->subject, MAX_SUBJECT_LENGTH, stdin);
    mail->subject[strcspn(mail->subject, "\n")] = 0;

    printf("Enter email body: ");
    fgets(mail->body, MAX_BODY_LENGTH, stdin);
    mail->body[strcspn(mail->body, "\n")] = 0;

    // Send email
    send_email(mail);
    free(mail);
    
    return 0;
}