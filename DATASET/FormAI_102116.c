//FormAI DATASET v1.0 Category: Digital Diary ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct entry {
    char date[20];
    char note[1000];
};

int main() {
    printf("Brave Digital Diary\n");
    printf("-------------------\n\n");

    int num_entries, option;

    printf("How many entries would you like to make? ");
    scanf("%d", &num_entries);

    struct entry *entries = malloc(num_entries * sizeof(struct entry));

    for (int i = 0; i < num_entries; i++) {
        printf("\nEnter the date of entry %d (DD/MM/YYYY): ", i+1);
        scanf("%s", entries[i].date);

        printf("Enter your note for the day: ");
        scanf(" %[^\n]", entries[i].note);
    }

    printf("\nSelect an option:\n");
    printf("1. Print all entries\n");
    printf("2. Search for an entry\n");
    printf("3. Remove an entry\n");
    printf("4. Exit\n");

    while (1) {
        printf("\nEnter option number: ");
        scanf("%d", &option);

        if (option == 1) {
            printf("\nAll entries:\n");
            for (int i = 0; i < num_entries; i++) {
                printf("\nDate: %s\n", entries[i].date);
                printf("Note: %s\n", entries[i].note);
            }
        }
        else if (option == 2) {
            char search_date[20];
            int found = 0;

            printf("\nEnter the date to search for (DD/MM/YYYY): ");
            scanf("%s", search_date);

            for (int i = 0; i < num_entries; i++) {
                if (strcmp(entries[i].date, search_date) == 0) {
                    printf("\nEntry found:\n");
                    printf("Date: %s\n", entries[i].date);
                    printf("Note: %s\n", entries[i].note);
                    found = 1;
                }
            }

            if (!found) {
                printf("\nEntry not found.\n");
            }
        }
        else if (option == 3) {
            char remove_date[20];
            int found = 0;

            printf("\nEnter the date to remove (DD/MM/YYYY): ");
            scanf("%s", remove_date);

            struct entry *new_entries = malloc((num_entries-1) * sizeof(struct entry));
            
            int j = 0;
            for (int i = 0; i < num_entries; i++) {
                if (strcmp(entries[i].date, remove_date) != 0) {
                    new_entries[j++] = entries[i];
                }
                else {
                    found = 1;
                } 
            }

            if (found) {
                printf("\nEntry removed.\n");
                num_entries--;
                entries = new_entries;
            }
            else {
                printf("\nEntry not found.\n");
            }
        }
        else if (option == 4) {
            printf("\nExiting...");
            break;
        }
        else {
            printf("\nInvalid option number. Please try again.\n");
        }
    }

    return 0;
}