//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 50
#define MAX_SUBJECT_LENGTH 100
#define MAX_MESSAGE_LENGTH 500
#define MAX_CHOICE_LENGTH 1

typedef struct Email {
    char name[MAX_NAME_LENGTH];
    char address[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} Email;

int main() {
    Email emails[MAX_EMAILS];
    int emailCount = 0;
    char choice[MAX_CHOICE_LENGTH];
    int i;

    while(1) {
        printf("Enter A to enter a new email, D to delete an email, L to list all emails, or Q to quit: ");
        fgets(choice, MAX_CHOICE_LENGTH, stdin);

        switch(choice[0]) {
            case 'A': 
            case 'a':
                if(emailCount < MAX_EMAILS) {
                    printf("Enter name: ");
                    fgets(emails[emailCount].name, MAX_NAME_LENGTH, stdin);
                    printf("Enter address: ");
                    fgets(emails[emailCount].address, MAX_EMAIL_LENGTH, stdin);
                    printf("Enter subject: ");
                    fgets(emails[emailCount].subject, MAX_SUBJECT_LENGTH, stdin);
                    printf("Enter message: ");
                    fgets(emails[emailCount].message, MAX_MESSAGE_LENGTH, stdin);
                    emailCount++;
                    printf("Email added.\n");
                } else {
                    printf("Maximum emails reached.\n");
                }
                break;

            case 'D':
            case 'd':
                if(emailCount > 0) {
                    printf("Enter email index to delete: ");
                    scanf("%d", &i);
                    getchar(); // consume newline character
                    if(i >= 0 && i < emailCount) {
                        printf("Deleting email at index %d.\n", i);
                        for(int j = i; j < emailCount - 1; j++) {
                            emails[j] = emails[j + 1];
                        }
                        emailCount--;
                    } else {
                        printf("Invalid input.\n");
                    }
                } else {
                    printf("No emails to delete.\n");
                }
                break;

            case 'L':
            case 'l':
                printf("Email List:\n");
                for(i = 0; i < emailCount; i++) {
                    printf("%d. %s <%s> - %s - %s\n", i, emails[i].name, emails[i].address, emails[i].subject, emails[i].message);
                }
                break;

            case 'Q':
            case 'q':
                 printf("Exiting.\n");
                 exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
}