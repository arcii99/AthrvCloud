//FormAI DATASET v1.0 Category: Email Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EMAILS 50
#define MAX_SUBJECT 100
#define MAX_MESSAGE 1000

struct Email {
    char subject[MAX_SUBJECT];
    char message[MAX_MESSAGE];
    char sender[MAX_SUBJECT];
    char recipient[MAX_SUBJECT];
};

struct Inbox {
    struct Email inbox[MAX_EMAILS];
    int num_emails;
};

void view_inbox(struct Inbox *inbox) {
    printf("INBOX\n");
    printf("------------------------------\n");
    for(int i=0; i<inbox->num_emails; i++) {
        printf("From: %s\n", inbox->inbox[i].sender);
        printf("Subject: %s\n", inbox->inbox[i].subject);
        printf("%s\n", inbox->inbox[i].message);
        printf("------------------------------\n");
    }
}

void compose_email(struct Inbox *inbox) {
    printf("Enter recipient: ");
    scanf("%s", inbox->inbox[inbox->num_emails].recipient);
    printf("Enter subject: ");
    scanf("%s", inbox->inbox[inbox->num_emails].subject);
    printf("Enter message (1000 character limit): ");
    getchar();
    fgets(inbox->inbox[inbox->num_emails].message, MAX_MESSAGE, stdin);
    strcpy(inbox->inbox[inbox->num_emails].sender, "me");
    inbox->num_emails++;
    printf("Email sent!\n");
}

int main() {
    struct Inbox inbox;
    inbox.num_emails = 0;

    int input;
    do {
        printf("1 - View inbox\n2 - Compose email\n3 - Quit\n");
        scanf("%d", &input);

        switch(input) {
            case 1:
                view_inbox(&inbox);
                break;
            case 2:
                compose_email(&inbox);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    } while(input != 3);

    return 0;
}