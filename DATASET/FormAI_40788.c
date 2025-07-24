//FormAI DATASET v1.0 Category: Email Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_SENDER_LENGTH 50
#define MAX_BODY_LENGTH 500

typedef struct Email {
    char subject[MAX_SUBJECT_LENGTH];
    char sender[MAX_SENDER_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

Email emails[MAX_EMAILS];
int numEmails = 0;

void addEmail(char *subject, char *sender, char *body) {
    if (numEmails >= MAX_EMAILS) {
        printf("Maximum number of emails reached!\n");
        return;
    }
    
    strncpy(emails[numEmails].subject, subject, MAX_SUBJECT_LENGTH-1);
    strncpy(emails[numEmails].sender, sender, MAX_SENDER_LENGTH-1);
    strncpy(emails[numEmails].body, body, MAX_BODY_LENGTH-1);
    
    numEmails++;
}

void listEmails() {
    for (int i = 0; i < numEmails; i++) {
        printf("Email #%d\n", i+1);
        printf("Subject: %s\n", emails[i].subject);
        printf("Sender: %s\n", emails[i].sender);
        printf("Body: %s\n", emails[i].body);
        printf("\n");
    }
}

int main() {
    char input[100];
    char subject[MAX_SUBJECT_LENGTH];
    char sender[MAX_SENDER_LENGTH];
    char body[MAX_BODY_LENGTH];
    
    while (1) {
        printf("Enter a command (add, list, quit): ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0;
        
        if (strcmp(input, "add") == 0) {
            printf("Enter the subject: ");
            fgets(subject, MAX_SUBJECT_LENGTH, stdin);
            subject[strcspn(subject, "\n")] = 0;
            printf("Enter the sender: ");
            fgets(sender, MAX_SENDER_LENGTH, stdin);
            sender[strcspn(sender, "\n")] = 0;
            printf("Enter the body: ");
            fgets(body, MAX_BODY_LENGTH, stdin);
            body[strcspn(body, "\n")] = 0;
            
            addEmail(subject, sender, body);
            printf("Email added!\n");
        }
        else if (strcmp(input, "list") == 0) {
            listEmails();
        }
        else if (strcmp(input, "quit") == 0) {
            printf("Exiting program...\n");
            break;
        }
        else {
            printf("Invalid command. Please try again.\n");
        }
    }
    
    return 0;
}