//FormAI DATASET v1.0 Category: Digital Diary ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure for diary entry */
struct diaryEntry {
    char date[11];
    char time[6];
    char title[100];
    char description[500];
};

/* Function to add a new diary entry */
void addEntry(struct diaryEntry *entry, int n) {
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%10s", entry[n].date);
    printf("Enter time (hh:mm): ");
    scanf("%5s", entry[n].time);
    printf("Enter title: ");
    scanf(" %[^\n]", entry[n].title);
    printf("Enter description: ");
    scanf(" %[^\n]", entry[n].description);
}

/* Function to search for diary entries by date */
void searchEntry(struct diaryEntry *entry, int n) {
    char date[11];
    printf("Enter date to search (dd/mm/yyyy): ");
    scanf("%10s", date);
    for (int i = 0; i < n; i++) {
        if (strcmp(entry[i].date, date) == 0) {
            printf("Date: %s\nTime: %s\nTitle: %s\nDescription: %s\n", 
                entry[i].date, entry[i].time, entry[i].title, entry[i].description);
        }
    }
}

/* Function to display all diary entries */
void displayEntries(struct diaryEntry *entry, int n) {
    if (n == 0) {
        printf("No diary entries to display.\n");
    }
    else {
        printf("All diary entries:\n");
        for (int i = 0; i < n; i++) {
            printf("Date: %s\nTime: %s\nTitle: %s\nDescription: %s\n", 
                entry[i].date, entry[i].time, entry[i].title, entry[i].description);
        }
    }
}

/* Main function */
int main() {
    int choice, numEntries = 0;
    struct diaryEntry entry[100];
    do {
        printf("\nDigital Diary Menu:\n");
        printf("1. Add a new entry\n");
        printf("2. Search for entries by date\n");
        printf("3. Display all entries\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry(entry, numEntries);
                numEntries++;
                break;
            case 2:
                searchEntry(entry, numEntries);
                break;
            case 3:
                displayEntries(entry, numEntries);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}