//FormAI DATASET v1.0 Category: Email Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUF_SIZE 1024
#define MAX_EMAILS 100

typedef struct {
    char sender[MAX_BUF_SIZE];
    char recipient[MAX_BUF_SIZE];
    char subject[MAX_BUF_SIZE];
    char body[MAX_BUF_SIZE];
} Email;

int main(void) {
    Email emails[MAX_EMAILS];
    int count = 0;
    int choice = 0;

    while (1) {
        printf("Email Client:\n");
        printf("1. Compose email\n");
        printf("2. View emails\n");
        printf("3. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
            printf("Invalid choice. Please try again.\n");
            while (getchar() != '\n')
                ; // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                if (count == MAX_EMAILS) {
                    printf("You have reached the maximum number of emails.\n");
                    break;
                }

                printf("Sender: ");
                fgets(emails[count].sender, MAX_BUF_SIZE, stdin); // read whole line
                emails[count].sender[strcspn(emails[count].sender, "\n")] = '\0'; // remove newline character

                printf("Recipient: ");
                fgets(emails[count].recipient, MAX_BUF_SIZE, stdin);
                emails[count].recipient[strcspn(emails[count].recipient, "\n")] = '\0';

                printf("Subject: ");
                fgets(emails[count].subject, MAX_BUF_SIZE, stdin);
                emails[count].subject[strcspn(emails[count].subject, "\n")] = '\0';

                printf("Body: ");
                fgets(emails[count].body, MAX_BUF_SIZE, stdin);
                emails[count].body[strcspn(emails[count].body, "\n")] = '\0';

                count++;
                printf("Email sent!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("You have no emails.\n");
                    break;
                }

                printf("Your emails:\n");
                for (int i = 0; i < count; i++) {
                    printf("Email #%d:\n", i + 1);
                    printf("From: %s\n", emails[i].sender);
                    printf("To: %s\n", emails[i].recipient);
                    printf("Subject: %s\n", emails[i].subject);
                    printf("Body: %s\n", emails[i].body);
                }
                break;

            case 3:
                printf("Goodbye!\n");
                exit(0);
        }
    }

    return 0;
}