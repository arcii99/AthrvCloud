//FormAI DATASET v1.0 Category: Email Client ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// define structure for email
struct Email {
    char to[50];
    char from[50];
    char subject[100];
    char message[500];
    time_t sent_at;
};

// function to send email
void send_email(struct Email *email) {
    // code to send email goes here
    printf("Message sent from %s to %s at %s", email->from, email->to, ctime(&(email->sent_at)));
}

int main() {
    struct Email em;
    printf("Enter recipient's email ID: ");
    scanf("%s", em.to);
    printf("Enter your email ID: ");
    scanf("%s", em.from);
    printf("Enter email subject: ");
    scanf("%s", em.subject);
    printf("Enter message: ");
    scanf("%s", em.message);
    em.sent_at = time(NULL);
    send_email(&em);
    return 0;
}