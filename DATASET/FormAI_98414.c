//FormAI DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct email {
    char from[100];
    char to[100];
    char subject[100];
    char body[1000];
    char date[100];
} Email;

Email *inbox[100];
Email *sent[100];
int inbox_count = 0;
int sent_count = 0;

void send_email(char *to, char *subject, char *body) {
    Email *e = (Email *)malloc(sizeof(Email));
    strcpy(e->from, "me@mail.com");
    strcpy(e->to, to);
    strcpy(e->subject, subject);
    strcpy(e->body, body);
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strcpy(e->date, asctime(timeinfo));
    sent[sent_count++] = e;
}

void view_inbox() {
    if (inbox_count == 0) {
        printf("No emails in inbox\n");
        return;
    }
    for (int i = 0; i < inbox_count; i++) {
        printf("From: %s\n", inbox[i]->from);
        printf("Subject: %s\n", inbox[i]->subject);
        printf("Date: %s\n", inbox[i]->date);
        printf("Body: %s\n", inbox[i]->body);
    }
}

void view_sent() {
    if (sent_count == 0) {
        printf("No emails sent\n");
        return;
    }
    for (int i = 0; i < sent_count; i++) {
        printf("To: %s\n", sent[i]->to);
        printf("Subject: %s\n", sent[i]->subject);
        printf("Date: %s\n", sent[i]->date);
        printf("Body: %s\n", sent[i]->body);
    }
}

void main() {
    printf("Welcome to the Email Client\n");
    while (1) {
        printf("Enter 1 to send email, 2 to view inbox, 3 to view sent emails, 4 to exit\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            char to[100], subject[100], body[1000];
            printf("Enter recipient email: ");
            scanf("%s", to);
            printf("Enter email subject: ");
            scanf("%s", subject);
            printf("Enter email body: ");
            scanf("%s", body);
            send_email(to, subject, body);
            printf("Email sent successfully!\n");
        } else if (choice == 2) {
            view_inbox();
        } else if (choice == 3) {
            view_sent();
        } else if (choice == 4) {
            exit(0);
        }
        printf("\n");
    }
}