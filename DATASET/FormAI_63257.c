//FormAI DATASET v1.0 Category: Email Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_EMAILS 10

struct email {
    char sender[MAX_INPUT_LENGTH];
    char recipient[MAX_INPUT_LENGTH];
    char subject[MAX_INPUT_LENGTH];
    char body[MAX_INPUT_LENGTH];
};

struct email mailbox[MAX_EMAILS];

void print_emails() {
    int i;
    for(i=0; i<MAX_EMAILS; i++) {
        if(mailbox[i].sender[0] != '\0') {
            printf("Email %d:\nSender: %s\nRecipient: %s\nSubject: %s\nBody: %s\n", i+1, mailbox[i].sender, mailbox[i].recipient, mailbox[i].subject, mailbox[i].body);
        }
    }
}

void send_email() {
    struct email new_email;
    printf("Enter sender email address: ");
    fgets(new_email.sender, MAX_INPUT_LENGTH, stdin);
    printf("Enter recipient email address: ");
    fgets(new_email.recipient, MAX_INPUT_LENGTH, stdin);
    printf("Enter email subject: ");
    fgets(new_email.subject, MAX_INPUT_LENGTH, stdin);
    printf("Enter email body: ");
    fgets(new_email.body, MAX_INPUT_LENGTH, stdin);
    int i;
    for(i=0; i<MAX_EMAILS; i++) {
        if(mailbox[i].sender[0] == '\0') {
            mailbox[i] = new_email;
            printf("Email sent!\n");
            break;
        }
    }
    if(i == MAX_EMAILS) {
        printf("Mailbox is full! Please delete some emails and try again.\n");
    }
}

void delete_email() {
    int email_number;
    printf("Enter email number to delete: ");
    scanf("%d", &email_number);
    if(email_number < 1 || email_number > MAX_EMAILS || mailbox[email_number-1].sender[0] == '\0') {
        printf("Invalid email number!\n");
    }
    else {
        mailbox[email_number-1].sender[0] = '\0';
        mailbox[email_number-1].recipient[0] = '\0';
        mailbox[email_number-1].subject[0] = '\0';
        mailbox[email_number-1].body[0] = '\0';
        printf("Email deleted!\n");
    }
}

int main() {
    printf("Welcome to the Linux Email Client!\n");
    char command[MAX_INPUT_LENGTH];
    int quit = 0;
    while(!quit) {
        printf("\nEnter a command (send, delete, print, quit): ");
        fgets(command, MAX_INPUT_LENGTH, stdin);
        if(strcmp(command, "send\n") == 0) {
            send_email();
        }
        else if(strcmp(command, "delete\n") == 0) {
            delete_email();
        }
        else if(strcmp(command, "print\n") == 0) {
            print_emails();
        }
        else if(strcmp(command, "quit\n") == 0) {
            quit = 1;
        }
        else {
            printf("Invalid command!\n");
        }
    }
    return 0;
}