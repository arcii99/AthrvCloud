//FormAI DATASET v1.0 Category: Mailing list manager ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define BUFFER_SIZE 100

typedef struct {
    char name[BUFFER_SIZE];
    char email[BUFFER_SIZE];
} Contact;

Contact emailList[MAX_EMAILS];
int emailCount = 0;

// Add a new email to the list
void addEmail() {
    char name[BUFFER_SIZE];
    char email[BUFFER_SIZE];

    printf("Enter name: ");
    fgets(name, BUFFER_SIZE, stdin);

    printf("Enter email: ");
    fgets(email, BUFFER_SIZE, stdin);

    // Strip newline character
    name[strcspn(name, "\n")] = '\0';
    email[strcspn(email, "\n")] = '\0';

    // Add contact to list
    strcpy(emailList[emailCount].name, name);
    strcpy(emailList[emailCount].email, email);
    emailCount++;
}

// Print all emails in the list
void printEmails() {
    printf("Emails:\n");
    for (int i = 0; i < emailCount; i++) {
        printf("%s - %s\n", emailList[i].name, emailList[i].email);
    }
}

int main() {
    char choice[BUFFER_SIZE];
    while (1) {
        printf("\nCommands:\n");
        printf("a - Add email\n");
        printf("p - Print emails\n");
        printf("q - Quit\n");

        printf("Enter choice: ");
        fgets(choice, BUFFER_SIZE, stdin);
        choice[strcspn(choice, "\n")] = '\0';

        if (strcmp(choice, "a") == 0) {
            addEmail();
        } else if (strcmp(choice, "p") == 0) {
            printEmails();
        } else if (strcmp(choice, "q") == 0) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}