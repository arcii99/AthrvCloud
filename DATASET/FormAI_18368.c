//FormAI DATASET v1.0 Category: Phone Book ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[20];
};

int main() {
    int count = 0;
    struct Contact phoneBook[100];
    char input[10];

    while (1) {
        printf("\n\nRetro Phone Book\n");
        printf("================\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contacts\n");
        printf("4. Quit\n\n");

        printf("Enter your choice: ");
        fgets(input, sizeof input, stdin);

        if (strcmp(input, "1\n") == 0) {
            printf("\nEnter the name: ");
            fgets(phoneBook[count].name, sizeof phoneBook[count].name, stdin);
            
            printf("Enter the phone number: ");
            fgets(phoneBook[count].phone, sizeof phoneBook[count].phone, stdin);

            printf("\nContact added successfully!\n");
            count++;
        }
        else if (strcmp(input, "2\n") == 0) {
            printf("\n\nContacts\n");
            printf("================\n");

            if (count == 0)
                printf("No contacts to display.\n");
            else {
                for (int i = 0; i < count; i++)
                    printf("%-20s\t%-20s\n", phoneBook[i].name, phoneBook[i].phone);
            }
        }
        else if (strcmp(input, "3\n") == 0) {
            char search[50];
            int found = 0;

            printf("\nEnter the name to search: ");
            fgets(search, sizeof search, stdin);

            for (int i = 0; i < count; i++) {
                if (strcmp(phoneBook[i].name, search) == 0) {
                    printf("\n%s\t%s\n", phoneBook[i].name, phoneBook[i].phone);
                    found = 1;
                }
            }

            if (!found)
                printf("\nContact not found.\n");
        }
        else if (strcmp(input, "4\n") == 0) {
            printf("\nGoodbye!\n");
            exit(0);
        }
        else {
            printf("\nInvalid choice. Try again.\n");
        }
    }
    return 0;
}