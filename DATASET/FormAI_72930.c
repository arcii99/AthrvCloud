//FormAI DATASET v1.0 Category: Mailing list manager ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

typedef struct {
    char first_name[50];
    char last_name[50];
    char email[100];
} contact;

int main() {
    int num_contacts = 0;
    contact contacts[MAX_EMAILS];
    char input[50];
    int choice;

    printf("Welcome to the Mailing List Manager!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add a contact\n");
        printf("2. Remove a contact\n");
        printf("3. View all contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        fgets(input, 50, stdin);
        choice = atoi(input);

        switch (choice) {
            case 1:
                if (num_contacts == MAX_EMAILS) {
                    printf("Error: Mailing list is full! Can't add any more contacts.\n");
                    break;
                }
                printf("Enter first name: ");
                fgets(contacts[num_contacts].first_name, 50, stdin);
                printf("Enter last name: ");
                fgets(contacts[num_contacts].last_name, 50, stdin);
                printf("Enter email address: ");
                fgets(contacts[num_contacts].email, 100, stdin);
                printf("Contact added successfully!\n");
                num_contacts++;
                break;
            case 2:
                if (num_contacts == 0) {
                    printf("Error: Mailing list is empty! Can't remove any contacts.\n");
                    break;
                }
                printf("Enter email address of contact to remove: ");
                fgets(input, 100, stdin);
                for (int i = 0; i < num_contacts; i++) {
                    if (strcmp(contacts[i].email, input) == 0) {
                        for (int j = i; j < num_contacts - 1; j++) {
                            contacts[j] = contacts[j + 1];
                        }
                        num_contacts--;
                        printf("Contact removed successfully!\n");
                        break;
                    }
                }
                break;
            case 3:
                if (num_contacts == 0) {
                    printf("Mailing list is empty!\n");
                    break;
                }
                printf("All contacts:\n");
                for (int i = 0; i < num_contacts; i++) {
                    printf("%s %s: %s\n", contacts[i].first_name, contacts[i].last_name, contacts[i].email);
                }
                break;
            case 4:
                printf("Exiting mailing list manager...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}