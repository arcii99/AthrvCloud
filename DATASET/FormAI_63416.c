//FormAI DATASET v1.0 Category: Email Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_EMAILS 5
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 500

typedef struct {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    time_t timestamp;
    int unread;
} Email;

Email inbox[MAX_EMAILS];
int num_emails = 0;

void send_email(char *sender, char *recipient, char *subject, char *body) {
    if (num_emails >= MAX_EMAILS) {
        printf("Inbox full\n");
        return;
    }

    Email new_email;
    strcpy(new_email.sender, sender);
    strcpy(new_email.recipient, recipient);
    strcpy(new_email.subject, subject);
    strcpy(new_email.body, body);
    new_email.timestamp = time(NULL);
    new_email.unread = 1;

    inbox[num_emails] = new_email;
    num_emails++;

    printf("Email sent!\n");
}

void view_inbox() {
    printf("%d unread emails\n\n", get_num_unread());
    for (int i = num_emails - 1; i >= 0; i--) {
        printf("From: %s\n", inbox[i].sender);
        printf("Subject: %s\n", inbox[i].subject);
        printf("Timestamp: %s", ctime(&inbox[i].timestamp));
        printf("%s\n", inbox[i].body);
        inbox[i].unread = 0;
        sleep(1);
    }
}

int get_num_unread() {
    int count = 0;
    for (int i = 0; i < num_emails; i++) {
        if (inbox[i].unread == 1) {
            count++;
        }
    }
    return count;
}

int main() {
    // Send 3 emails to the inbox
    send_email("alice@example.com", "bob@example.com", "Meeting", "Hey Bob, let's meet at 2pm tomorrow.");
    send_email("bob@example.com", "alice@example.com", "Re: Meeting", "Sure, let's meet at the coffee shop on 5th street.");
    send_email("charlie@example.com", "alice@example.com", "Project update", "Here's the latest project update. Let me know if you have any questions.");

    // View the inbox
    view_inbox();

    // Send a new email
    send_email("bob@example.com", "alice@example.com", "Re: Meeting", "Actually, can we meet at 3pm instead?");

    // View the inbox again
    view_inbox();

    return 0;
}