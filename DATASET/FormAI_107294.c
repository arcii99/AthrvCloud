//FormAI DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ENTRIES 100

struct diary_entry_t {
    char date[11];
    char text[500];
};

int main(void) {
    struct diary_entry_t entries[MAX_ENTRIES] = {0};
    int num_entries = 0;

    printf("Welcome to your digital diary.\n");
    printf("You can add up to %d entries.\n", MAX_ENTRIES);

    while (1) {
        char choice;

        printf("\nWhat would you like to do?\n");
        printf("A - Add a new entry\n");
        printf("L - List all entries\n");
        printf("E - Exit\n");

        printf("Enter your choice: ");
        choice = getchar();
        getchar(); // to clear the input buffer

        if (choice == 'A' || choice == 'a') {
            printf("\nEnter the date of the entry (dd/mm/yyyy): ");
            fgets(entries[num_entries].date, 11, stdin);

            printf("Enter the text of the entry (up to 500 characters):\n");
            fgets(entries[num_entries].text, 500, stdin);

            num_entries++;

            printf("\nEntry added!\n");

        } else if (choice == 'L' || choice == 'l') {
            if (num_entries == 0) {
                printf("\nYou have no entries yet.\n");
            } else {
                printf("\nHere are all your entries:\n\n");
                for (int i = 0; i < num_entries; ++i) {
                    printf("%d. Date: %s", i+1, entries[i].date);
                    printf(" Text: %s\n", entries[i].text);
                }
            }

        } else if (choice == 'E' || choice == 'e') {
            printf("\nGoodbye!\n");
            break;

        } else {
            printf("\nInvalid choice. Please try again.\n");
        }

    }

    return 0;
}