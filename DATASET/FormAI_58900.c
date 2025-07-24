//FormAI DATASET v1.0 Category: Email Client ; Style: multivariable
#include <stdio.h>

void send_email(char to[], char subject[], char body[])
{
    // Code to send email using SMTP protocol
    
    printf("Email sent to %s with subject %s\nBody: %s", to, subject, body);
}

int main()
{
    char recipient[50];
    char email_subject[100];
    char email_body[500];

    printf("Enter recipient email address: ");
    scanf("%s", recipient);
    getchar(); // To clear input buffer

    printf("Enter email subject: ");
    fgets(email_subject, 100, stdin);

    printf("Enter email body: ");
    fgets(email_body, 500, stdin);

    send_email(recipient, email_subject, email_body);

    return 0;
}