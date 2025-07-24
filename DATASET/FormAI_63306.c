//FormAI DATASET v1.0 Category: Email Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000
#define MAX_EMAILS 100

struct email {
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
    char sender[MAX_SUBJECT_LENGTH];
    char receiver[MAX_SUBJECT_LENGTH];
};

void display_emails(struct email *emails, int num_emails) {
    for(int i = 0; i < num_emails; i++) {
        printf("Email #%d\n", i + 1);
        printf("Subject: %s\n", emails[i].subject);
        printf("From: %s\n", emails[i].sender);
        printf("To: %s\n", emails[i].receiver);
        printf("Body: %s\n", emails[i].body);
        printf("---------------\n");
    }
}

int main() {
    struct email inbox[MAX_EMAILS];
    int num_emails = 0;
    char input[100];

    while(1) {
        printf("Please choose an option:\n");
        printf("1. Send email\n");
        printf("2. View inbox\n");
        printf("3. Quit\n");

        fgets(input, 100, stdin);

        if(strcmp(input, "1\n") == 0) {
            struct email new_email;
            printf("Enter subject: ");
            fgets(new_email.subject, MAX_SUBJECT_LENGTH, stdin);
            printf("Enter sender: ");
            fgets(new_email.sender, MAX_SUBJECT_LENGTH, stdin);
            printf("Enter receiver: ");
            fgets(new_email.receiver, MAX_SUBJECT_LENGTH, stdin);
            printf("Enter body: ");
            fgets(new_email.body, MAX_BODY_LENGTH, stdin);
            inbox[num_emails] = new_email;
            num_emails++;
        } else if(strcmp(input, "2\n") == 0) {
            if(num_emails > 0) {
                display_emails(inbox, num_emails);
            } else {
                printf("No emails in inbox.\n");
            }
        } else if(strcmp(input, "3\n") == 0) {
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid input, try again.\n");
        }
    }

    return 0;
}