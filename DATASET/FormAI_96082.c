//FormAI DATASET v1.0 Category: Email Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char email[1000], subject[1000], message[1000];
    int choice;

    printf("Welcome to BraveMail - Your C Email Client\n\n");
    while (1) {
        printf("Please select an option:\n");
        printf("1. Compose an email\n");
        printf("2. View inbox\n");
        printf("3. Exit\n");
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Compose Email\n");
                printf("Please enter recipient's email address: ");
                scanf("%s", email);
                printf("Please enter subject: ");
                scanf("%s", subject);
                printf("Please enter message: ");
                scanf("%s", message);
                printf("\nEmail sent successfully!\n\n");
                break;
            case 2:
                printf("Inbox\n");
                printf("No new messages.\n\n");
                break;
            case 3:
                printf("Exiting BraveMail. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}