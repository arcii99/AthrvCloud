//FormAI DATASET v1.0 Category: Email Client ; Style: active
#include <stdio.h>
#include <string.h>

#define MAX_STR_SIZE 1000
#define MAX_MAIL_SUBJECT_SIZE 100
#define MAX_MAIL_BODY_SIZE 500

// define structure of email 
struct email {
    char sender[MAX_STR_SIZE];
    char recipient[MAX_STR_SIZE];
    char subject[MAX_MAIL_SUBJECT_SIZE];
    char body[MAX_MAIL_BODY_SIZE];
};

// function declarations
void send_email(struct email mail);

// main function
int main() {
    struct email new_mail;

    // get input from user
    printf("Enter sender's email address:\n");
    fgets(new_mail.sender, MAX_STR_SIZE, stdin);

    printf("Enter recipient's email address:\n");
    fgets(new_mail.recipient, MAX_STR_SIZE, stdin);

    printf("Enter email subject:\n");
    fgets(new_mail.subject, MAX_MAIL_SUBJECT_SIZE, stdin);

    printf("Enter mail body:\n");
    fgets(new_mail.body, MAX_MAIL_BODY_SIZE, stdin);

    // send email
    send_email(new_mail);

    return 0;
}

// implementation of send_email function
void send_email(struct email mail) {
    printf("\nEmail sent successfully!\nFrom: %sTo: %sSubject: %s\n\n%s", mail.sender, mail.recipient, mail.subject, mail.body);
}