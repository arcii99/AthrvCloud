//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_LENGTH 100

int main() {
    int choice, numEmails = 0;
    char command[MAX_LENGTH];
    char emails[MAX_EMAILS][MAX_LENGTH];

    printf("Welcome to the Mailing List Manager\n\n");

    do {
        printf("Enter a command (ADD, LIST, QUIT): ");
        scanf("%s", command);

        if(strcmp(command, "ADD") == 0) {
            if(numEmails == MAX_EMAILS) {
                printf("Mailing list is full. Cannot add any more emails.\n");
            } else {
                printf("Enter email address: ");
                scanf("%s", emails[numEmails]);
                printf("Email added to mailing list.\n");
                numEmails++;
            }
        } else if(strcmp(command, "LIST") == 0) {
            printf("Mailing list:\n");
            for(int i = 0; i < numEmails; i++) {
                printf("%d: %s\n", i + 1, emails[i]);
            }
        } else if(strcmp(command, "QUIT") == 0) {
            printf("Goodbye.\n");
            return 0;
        } else {
            printf("Invalid command.\n");
        }

    } while(1);

    return 0;
}