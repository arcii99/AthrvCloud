//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_EMAILS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Contact;

int main() {
    Contact contacts[MAX_EMAILS];
    int numContacts = 0;

    while (1) {
        printf("Enter 'add' to add a contact or 'list' to list all contacts: ");
        char input[10];
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            if (numContacts == MAX_EMAILS) {
                printf("Error: maximum number of contacts reached\n");
                continue;
            }

            printf("Enter name: ");
            scanf("%s", contacts[numContacts].name);

            printf("Enter email: ");
            scanf("%s", contacts[numContacts].email);

            numContacts++;
        } else if (strcmp(input, "list") == 0) {
            printf("Contacts:\n");

            for (int i = 0; i < numContacts; i++) {
                printf("%s: %s\n", contacts[i].name, contacts[i].email);
            }
        } else {
            printf("Error: invalid command\n");
        }
    }

    return 0;
}