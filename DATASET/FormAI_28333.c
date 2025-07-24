//FormAI DATASET v1.0 Category: Phone Book ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

struct Contact {
    char name[MAX_SIZE];
    char phone_number[MAX_SIZE];
};

int main(){
    struct Contact phone_book[MAX_SIZE];
    int num_entries = 0, option;
    FILE *fptr;

    // Attempt to open file for reading
    fptr = fopen("phonebook.txt", "r");

    // If file exists
    if (fptr != NULL) {
        // read entries from file
        while (fscanf(fptr, "%s %s", phone_book[num_entries].name, phone_book[num_entries].phone_number) == 2) {
            num_entries++;
        }
        fclose(fptr);
    }

    printf("Phone Book\n");
    while (1) {
        // Display menu options
        printf("\n1. Add contact\n");
        printf("2. Display all contacts\n");
        printf("3. Search for contact\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                // Add contact details
                printf("Enter name: ");
                scanf("%s", phone_book[num_entries].name);
                printf("Enter phone number: ");
                scanf("%s", phone_book[num_entries].phone_number);
                num_entries++;
                break;
            case 2:
                // Display all contacts
                printf("\nNumber of Entries: %d\n", num_entries);
                for (int i = 0; i < num_entries; i++) {
                    printf("%d. %s %s\n", i+1, phone_book[i].name, phone_book[i].phone_number);
                }
                break;
            case 3:
                // Search for contact
                char query_name[MAX_SIZE];
                printf("Enter name to search: ");
                scanf("%s", query_name);
                for (int i = 0; i < num_entries; i++) {
                    if (strcmp(query_name, phone_book[i].name) == 0) {
                        printf("%s %s\n", phone_book[i].name, phone_book[i].phone_number);
                    }
                }
                break;
            case 4:
                // Save entries to file and exit
                fptr = fopen("phonebook.txt", "w");
                for (int i = 0; i < num_entries; i++) {
                    fprintf(fptr, "%s %s\n", phone_book[i].name, phone_book[i].phone_number);
                }
                fclose(fptr);
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option. Please enter again.\n");
        }
    }
    return 0;
}