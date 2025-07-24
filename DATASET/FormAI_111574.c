//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Cryptic
#include <stdio.h>

#define MAX_EMAILS 100

char emails[MAX_EMAILS][80]; // array of emails
int num_emails = 0; // number of emails currently in the list

void add_email(char email[]) {
    if (num_emails < MAX_EMAILS) {
        strcpy(emails[num_emails], email);
        num_emails++;
    } else {
        printf("Sorry, the maximum number of emails has been reached.\n");
    }
}

void remove_email(char email[]) {
    int i, j;
    for (i = 0; i < num_emails; i++) {
        if (strcmp(emails[i], email) == 0) {
            // found matching email, shift all subsequent emails left to delete it
            for (j = i+1; j < num_emails; j++) {
                strcpy(emails[j-1], emails[j]);
            }
            num_emails--;
            return;
        }
    }
    printf("Sorry, that email was not found in the mailing list.\n");
}

void display_emails() {
    int i;
    for (i = 0; i < num_emails; i++) {
        printf("%s\n", emails[i]);
    }
}

int main() {
    char command[80], email[80];

    while (1) {
        printf("Enter a command ('add', 'remove', 'display', or 'quit'): ");
        fgets(command, sizeof(command), stdin);

        if (strcmp(command, "add\n") == 0) {
            printf("Enter email to add: ");
            fgets(email, sizeof(email), stdin);
            add_email(email);
        } else if (strcmp(command, "remove\n") == 0) {
            printf("Enter email to remove: ");
            fgets(email, sizeof(email), stdin);
            remove_email(email);
        } else if (strcmp(command, "display\n") == 0) {
            display_emails();
        } else if (strcmp(command, "quit\n") == 0) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Sorry, that command is not recognized.\n");
        }
    }

    return 0;
}