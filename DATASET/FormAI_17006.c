//FormAI DATASET v1.0 Category: Email Client ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

struct Email {
    char sender[MAX_EMAILS];
    char receiver[MAX_EMAILS];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
};

int main() {
    int numEmails = 0;
    struct Email emailList[MAX_EMAILS];

    while (true) {
        char choice[10];
        printf("What would you like to do?\n");
        printf("1. Compose an email\n");
        printf("2. View inbox\n");
        printf("3. Exit\n");
        fgets(choice, sizeof(choice), stdin);

        if (strcmp(choice, "1\n") == 0) {
            struct Email newEmail;

            printf("Enter sender email address: ");
            fgets(newEmail.sender, sizeof(newEmail.sender), stdin);
            newEmail.sender[strcspn(newEmail.sender, "\n")] = 0;

            printf("Enter receiver email address: ");
            fgets(newEmail.receiver, sizeof(newEmail.receiver), stdin);
            newEmail.receiver[strcspn(newEmail.receiver, "\n")] = 0;

            printf("Enter email subject: ");
            fgets(newEmail.subject, sizeof(newEmail.subject), stdin);
            newEmail.subject[strcspn(newEmail.subject, "\n")] = 0;

            printf("Enter email body: ");
            fgets(newEmail.body, sizeof(newEmail.body), stdin);
            newEmail.body[strcspn(newEmail.body, "\n")] = 0;

            emailList[numEmails] = newEmail;
            numEmails++;
        }
        else if (strcmp(choice, "2\n") == 0) {
            if (numEmails == 0) {
                printf("You have no emails.\n");
            }
            else {
                printf("Your inbox:\n");

                for (int i = 0; i < numEmails; i++) {
                    printf("From: %s\n", emailList[i].sender);
                    printf("To: %s\n", emailList[i].receiver);
                    printf("Subject: %s\n", emailList[i].subject);
                    printf("Body: %s\n", emailList[i].body);
                    printf("\n");
                }
            }
        }
        else if (strcmp(choice, "3\n") == 0) {
            printf("Exiting email client...\n");
            exit(EXIT_SUCCESS);
        }
        else {
            printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}