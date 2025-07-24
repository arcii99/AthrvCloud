//FormAI DATASET v1.0 Category: Email Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#define MAX_SUBJECT_LENGTH 100
#define MAX_BODY_LENGTH 1000

typedef struct {
    char recipient[30];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

int main() {
    Email email;
    char choice;

    do {
        printf("Enter recipient email address: ");
        scanf("%s", email.recipient);

        printf("Enter subject of email: ");
        while (getchar() != '\n');
        fgets(email.subject, MAX_SUBJECT_LENGTH, stdin);
        email.subject[strcspn(email.subject, "\n")] = '\0';
        
        printf("Enter body of email: ");
        fgets(email.body, MAX_BODY_LENGTH, stdin);
        email.body[strcspn(email.body, "\n")] = '\0';

        // Send email code would be here

        printf("\nEmail Sent to %s with subject '%s'", email.recipient, email.subject); 
        printf(" and body:\n%s\n\n", email.body);

        // Ask for another email
        printf("Do you want to send another email? (y/n): ");
        scanf(" %c", &choice);
    } while (tolower(choice) == 'y');

    return 0;
}