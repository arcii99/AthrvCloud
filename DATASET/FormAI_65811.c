//FormAI DATASET v1.0 Category: Mailing list manager ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

struct email {
    char address[100];
};

struct mailing_list {
    char name[100];
    struct email emails[MAX_EMAILS];
    int num_emails;
};

void print_menu() {
    printf("1. Add mailing list\n");
    printf("2. Add email to mailing list\n");
    printf("3. Remove email from mailing list\n");
    printf("4. Print mailing list\n");
    printf("5. Exit\n");
}

int main() {
    struct mailing_list lists[10];
    int num_lists = 0;
    int choice, list_choice;
    char email_address[100];

    printf("Welcome to the mailing list manager!\n");

    while (1) {
        print_menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name of mailing list: ");
                scanf("%s", lists[num_lists].name);
                printf("Mailing list added successfully!\n");
                num_lists++;
                break;
            case 2:
                printf("Enter the number of the mailing list to add email to: ");
                scanf("%d", &list_choice);
                printf("Enter email address: ");
                scanf("%s", email_address);
                if (lists[list_choice-1].num_emails < MAX_EMAILS) {
                    strcpy(lists[list_choice-1].emails[lists[list_choice-1].num_emails].address, email_address);
                    lists[list_choice-1].num_emails++;
                    printf("Email added successfully!\n");
                } else {
                    printf("Mailing list is full!\n");
                }
                break;
            case 3:
                printf("Enter the number of the mailing list to remove email from: ");
                scanf("%d", &list_choice);
                printf("Enter email address to remove: ");
                scanf("%s", email_address);
                for (int i = 0; i < lists[list_choice-1].num_emails; i++) {
                    if (strcmp(lists[list_choice-1].emails[i].address, email_address) == 0) {
                        for (int j = i; j < lists[list_choice-1].num_emails - 1; j++) {
                            strcpy(lists[list_choice-1].emails[j].address, lists[list_choice-1].emails[j+1].address);
                        }
                        lists[list_choice-1].num_emails--;
                        printf("Email removed successfully!\n");
                        break;
                    }
                }
                break;
            case 4:
                printf("Mailing Lists:\n");
                for (int i = 0; i < num_lists; i++) {
                    printf(" %d. %s:\n", i+1, lists[i].name);
                    for (int j = 0; j < lists[i].num_emails; j++) {
                        printf("  %s\n", lists[i].emails[j].address);
                    }
                }
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }

        printf("\n");
    }

    return 0;
}