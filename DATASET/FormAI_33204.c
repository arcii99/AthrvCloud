//FormAI DATASET v1.0 Category: Email Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_MESSAGES 100
#define MAX_MESSAGE_LENGTH 1000

struct message {
    char sender[50];
    char receiver[50];
    char subject[100];
    char body[MAX_MESSAGE_LENGTH];
};

struct mailbox {
    char email[50];
    struct message messages[MAX_MESSAGES];
    int num_messages;
};

void add_message(struct mailbox* box, struct message m) {
    if (box->num_messages == MAX_MESSAGES) {
        printf("Mailbox full\n");
        return;
    }

    box->messages[box->num_messages++] = m;
}

void remove_message(struct mailbox* box, int index) {
    if (index >= box->num_messages) {
        printf("Invalid message index\n");
        return;
    }

    for (int i = index; i < box->num_messages - 1; i++) {
        box->messages[i] = box->messages[i + 1];
    }

    box->num_messages--;
}

int main() {
    struct mailbox inbox = {"johndoe@gmail.com", {}, 0};
    int choice;

    while (1) {
        printf("\nEnter 1 to compose a message, 2 to view messages, 3 to delete a message, 4 to exit:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct message m;
                printf("\nEnter sender email:\n");
                scanf("%s", m.sender);
                printf("\nEnter recipient email:\n");
                scanf("%s", m.receiver);
                printf("\nEnter message subject:\n");
                scanf("%s", m.subject);
                printf("\nEnter message body (max %d characters):\n", MAX_MESSAGE_LENGTH);
                scanf("\n");
                fgets(m.body, MAX_MESSAGE_LENGTH, stdin);
                add_message(&inbox, m);
                break;
            }
            case 2: {
                printf("\nInbox for %s:\n", inbox.email);
                for (int i = 0; i < inbox.num_messages; i++) {
                    printf("\nMessage %d:\n", i + 1);
                    printf("From: %s\n", inbox.messages[i].sender);
                    printf("To: %s\n", inbox.messages[i].receiver);
                    printf("Subject: %s\n", inbox.messages[i].subject);
                    printf("Body: %s\n", inbox.messages[i].body);
                }
                break;
            }
            case 3: {
                int index;
                printf("\nEnter index of message to delete:\n");
                scanf("%d", &index);
                remove_message(&inbox, index - 1);
                break;
            }
            case 4: {
                printf("Exiting client.\n");
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    }
    return 0;
}