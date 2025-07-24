//FormAI DATASET v1.0 Category: Digital Diary ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ENTRIES 1000
#define MAX_NAME_LEN 20
#define MAX_LINE_LEN 200

typedef struct {
    char name[MAX_NAME_LEN];
    char entry[MAX_LINE_LEN];
} DiaryEntry;

int main()
{
    DiaryEntry diary[MAX_ENTRIES];
    int entryCount = 0;
    int running = 1;

    printf("Welcome to the Multiplayer Digital Diary!\n");

    while (running) {
        printf("\nEnter an option:\n1. Add an entry\n2. View all entries\n3. Exit\n");
        int choice = getchar();

        switch (choice) {
            case '1':   // Add an entry
                if (entryCount >= MAX_ENTRIES) {
                    printf("\nSorry, the diary is full!\n");
                    break;
                }

                printf("\nEnter your name: ");
                fgets(diary[entryCount].name, MAX_NAME_LEN, stdin);
                diary[entryCount].name[strcspn(diary[entryCount].name, "\n")] = '\0';  // Remove trailing newline character

                printf("Enter your entry: ");
                fgets(diary[entryCount].entry, MAX_LINE_LEN, stdin);
                diary[entryCount].entry[strcspn(diary[entryCount].entry, "\n")] = '\0';  // Remove trailing newline character

                entryCount++;
                printf("\nEntry added successfully!\n");
                break;

            case '2':   // View all entries
                if (entryCount == 0) {
                    printf("\nSorry, there are no entries to be viewed!\n");
                } else {
                    printf("\nAll Entries:\n");
                    for (int i = 0; i < entryCount; i++) {
                        printf("%s: %s\n", diary[i].name, diary[i].entry);
                    }
                }
                break;

            case '3':   // Exit
                running = 0;
                printf("\nExiting the diary...\n");
                break;

            default:    // Invalid input
                printf("\nInvalid input, please try again.\n");
                break;
        }
        getchar();  // Clear the input buffer
    }

    return 0;
}