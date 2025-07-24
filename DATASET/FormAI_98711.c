//FormAI DATASET v1.0 Category: Email Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 10
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 500

struct Email {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
};

int main() {
    struct Email emails[MAX_EMAILS];
    int numEmails = 0;
    int userChoice = 0;
    char temp[100];

    printf("Welcome to my email client!\n");

    while (userChoice != 4) {
        printf("\nWhat do you want to do?\n");
        printf("1. View emails\n");
        printf("2. Compose email\n");
        printf("3. Delete email\n");
        printf("4. Exit\n");
        fgets(temp, 100, stdin);
        userChoice = atoi(temp);

        switch (userChoice) {
            case 1:
                printf("\nHere are your emails:\n");
                if (numEmails == 0) {
                    printf("You have no emails.\n");
                } else {
                    for (int i=0; i<numEmails; i++) {
                        printf("%d. %s - %s\n", i+1, emails[i].sender, emails[i].subject);
                    }
                    printf("\nEnter the number of an email to read it: ");
                    fgets(temp, 100, stdin);
                    int emailIndex = atoi(temp) - 1;

                    if (emailIndex >= 0 && emailIndex < numEmails) {
                        printf("\n----------------------------\n");
                        printf("From: %s\n", emails[emailIndex].sender);
                        printf("Subject: %s\n", emails[emailIndex].subject);
                        printf("Body: %s\n", emails[emailIndex].body);
                        printf("----------------------------\n");
                    } else {
                        printf("\nInvalid email number.\n");
                    }
                }
                break;
            case 2:
                if (numEmails == MAX_EMAILS) {
                    printf("\nYou cannot have more than %d emails.\n", MAX_EMAILS);
                } else {
                    struct Email newEmail;
                    printf("\nEnter recipient: ");
                    fgets(newEmail.recipient, 50, stdin);
                    printf("Enter subject: ");
                    fgets(newEmail.subject, MAX_SUBJECT_LENGTH, stdin);
                    printf("Enter body: ");
                    fgets(newEmail.body, MAX_BODY_LENGTH, stdin);

                    // Assume current user is sender
                    strcpy(newEmail.sender, "you");
                    emails[numEmails] = newEmail;
                    numEmails++;
                    printf("\nEmail sent!\n");
                }
                break;
            case 3:
                printf("\nWhich email do you want to delete? (Enter the number)\n");
                if (numEmails == 0) {
                    printf("You have no emails to delete.\n");
                } else {
                    for (int i=0; i<numEmails; i++) {
                        printf("%d. %s - %s\n", i+1, emails[i].sender, emails[i].subject);
                    }
                    int emailIndex = atoi(fgets(temp, 100, stdin)) - 1;
                    if (emailIndex >= 0 && emailIndex < numEmails) {
                        for (int i=emailIndex; i<numEmails-1; i++) {
                            emails[i] = emails[i+1];
                        }
                        numEmails--;
                        printf("\nEmail deleted.\n");
                    } else {
                        printf("\nInvalid email number.\n");
                    }
                }
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}