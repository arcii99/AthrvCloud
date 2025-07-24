//FormAI DATASET v1.0 Category: Email Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct email {
    char sender[50];
    char receiver[50];
    char subject[50];
    char body[500];
} Email;

void send_email(Email* email) {
    printf("Sending email...\n");
    printf("From: %s\n", email->sender);
    printf("To: %s\n", email->receiver);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);
    printf("Email sent successfully!\n");
}

void read_email(Email* email) {
    printf("Reading email...\n");
    printf("From: %s\n", email->sender);
    printf("To: %s\n", email->receiver);
    printf("Subject: %s\n", email->subject);
    printf("Body: %s\n", email->body);
    printf("Email read successfully!\n");
}

int main() {
    Email my_email;

    strcpy(my_email.sender, "john.doe@company.com");
    strcpy(my_email.receiver, "jane.doe@company.com");
    strcpy(my_email.subject, "Meeting Reminder");
    strcpy(my_email.body, "Just a friendly reminder that we have a meeting tomorrow at 2pm in Conference Room A.");

    send_email(&my_email);

    Email received_email;

    strcpy(received_email.sender, "jane.doe@company.com");
    strcpy(received_email.receiver, "john.doe@company.com");
    strcpy(received_email.subject, "Re: Meeting Reminder");
    strcpy(received_email.body, "Thanks for the reminder! See you tomorrow at 2pm.");

    read_email(&received_email);

    return 0;
}