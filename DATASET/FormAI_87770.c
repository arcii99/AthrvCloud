//FormAI DATASET v1.0 Category: Digital Diary ; Style: random
#include <stdio.h>
#include <time.h>
#include <string.h>

struct diary {
    char date[20];
    char content[200];
};

int main() {
    struct diary entries[365];
    time_t currentTime;
    struct tm *localTime;
    char date[20];
    int i = 0;

    // Get current date
    time(&currentTime);
    localTime = localtime(&currentTime);
    strftime(date, sizeof(date), "%Y/%m/%d", localTime);

    // Initialize empty diary
    for (i = 0; i < 365; i++) {
        strcpy(entries[i].date, "");
        strcpy(entries[i].content, "");
    }

    // Main loop to interact with user
    while (1) {
        char option;
        printf("\nWelcome to your digital diary! Today is %s\n", date);
        printf("Enter an option:\n");
        printf("1 - Add a new entry\n");
        printf("2 - View all entries\n");
        printf("3 - Search for entries by date\n");
        printf("4 - Exit\n");
        scanf(" %c", &option);

        if (option == '1') {
            // Add a new entry
            char content[200];
            printf("Enter your thoughts for today: ");
            scanf(" %[^\n]s", content);
            strcpy(entries[i].date, date);
            strcpy(entries[i].content, content);
            i++;
            printf("Entry added.\n");
        } else if (option == '2') {
            // View all entries
            if (i == 0) {
                printf("No entries yet.\n");
            } else {
                printf("All entries:\n");
                for (int j = 0; j < i; j++) {
                    printf("Date: %s\n", entries[j].date);
                    printf("Content: %s\n", entries[j].content);
                }
            }
        } else if (option == '3') {
            // Search for entries by date
            char searchDate[20];
            printf("Enter the date you want to search for (YYYY/MM/DD): ");
            scanf(" %s", searchDate);
            int foundEntries = 0;
            for (int j = 0; j < i; j++) {
                if (strcmp(entries[j].date, searchDate) == 0) {
                    foundEntries++;
                    printf("Date: %s\n", entries[j].date);
                    printf("Content: %s\n", entries[j].content);
                }
            }
            if (foundEntries == 0) {
                printf("No entries found for that date.\n");
            }
        } else if (option == '4') {
            // Exit program
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}