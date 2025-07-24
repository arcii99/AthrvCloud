//FormAI DATASET v1.0 Category: Digital Diary ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Declare a structure to store diary entries
struct diary {
    char date[11];
    char text[201];
};

// Declare function to add new diary entry
void add_entry(struct diary diaries[], int *num_entries) {
    char c;
    int i = 0, j = 0;
    
    printf("Enter today's date (MM/DD/YYYY): ");
    fgets(diaries[*num_entries].date, 11, stdin);
    while ((c = getchar()) != '\n' && c != EOF); // clear input buffer
    
    printf("Enter your diary entry (max 200 characters):\n");
    fgets(diaries[*num_entries].text, 201, stdin);
    while ((c = getchar()) != '\n' && c != EOF); // clear input buffer
    
    (*num_entries)++;
}

// Declare function to display all diary entries
void view_entries(struct diary diaries[], int num_entries) {
    if (num_entries == 0) {
        printf("No entries to display.\n");
    } else {
        printf("DIARY ENTRIES:\n");
        printf("----------------\n");
        for (int i = 0; i < num_entries; i++) {
            printf("%s\n%s\n\n", diaries[i].date, diaries[i].text);
        }
    }
}

int main() {
    struct diary diaries[365]; // maximum of 365 entries
    int num_entries = 0;
    char choice;

    printf("****************************************\n");
    printf("*    WELCOME TO YOUR DIGITAL DIARY     *\n");
    printf("****************************************\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add new diary entry\n");
        printf("2. View all diary entries\n");
        printf("3. Exit\n\n");
        printf("Enter your choice (1-3): ");
        
        choice = getchar();
        while ((getchar()) != '\n'); // clear input buffer

        switch (choice) {
            case '1':
                add_entry(diaries, &num_entries);
                break;
            case '2':
                view_entries(diaries, num_entries);
                break;
            case '3':
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}