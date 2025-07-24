//FormAI DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 50
#define MAX_SUBJECT_LEN 50
#define MAX_BODY_LEN 1000

typedef struct Email {
    char sender[MAX_SUBJECT_LEN];
    char recipient[MAX_SUBJECT_LEN];
    char subject[MAX_SUBJECT_LEN];
    char body[MAX_BODY_LEN];
} Email;

int main() {
    int num_emails = 0;
    Email emails[MAX_EMAILS];
    char input[50];

    while (1) {
        printf("Email Client\n");
        printf("1. Compose email\n");
        printf("2. View emails\n");
        printf("3. Exit\n");

        fgets(input, 50, stdin);

        switch (atoi(input)) {
            case 1:
                if (num_emails < MAX_EMAILS) {
                    Email new_email;
                    printf("Sender: ");
                    fgets(new_email.sender, MAX_SUBJECT_LEN, stdin);
                    printf("Recipient: ");
                    fgets(new_email.recipient, MAX_SUBJECT_LEN, stdin);
                    printf("Subject: ");
                    fgets(new_email.subject, MAX_SUBJECT_LEN, stdin);
                    printf("Body: ");
                    fgets(new_email.body, MAX_BODY_LEN, stdin);
                    emails[num_emails] = new_email;
                    num_emails++;
                }
                else {
                    printf("Inbox is full\n");
                }
                break;

            case 2:
                for (int i = 0; i < num_emails; i++) {
                    printf("Email %d\n", i+1);
                    printf("Sender: %s", emails[i].sender);
                    printf("Recipient: %s", emails[i].recipient);
                    printf("Subject: %s", emails[i].subject);
                    printf("Body: %s", emails[i].body);
                }
                break;

            case 3:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid input\n");
        }
    }
}