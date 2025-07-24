//FormAI DATASET v1.0 Category: Digital Diary ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

struct DiaryEntry {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
};

struct Diary {
    struct DiaryEntry entries[MAX_ENTRIES];
    int entry_count;
};

void print_menu() {
    printf("1. Add new entry\n");
    printf("2. View all entries\n");
    printf("3. Search for entry\n");
    printf("4. Exit\n");
}

void add_entry(struct Diary *diary) {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];

    printf("Enter date (DD/MM/YYYY): ");
    scanf("%s", date);
    printf("Enter diary entry (max length %d characters): ", MAX_ENTRY_LENGTH);
    scanf(" %[^\n]s", entry);

    strcpy(diary->entries[diary->entry_count].date, date);
    strcpy(diary->entries[diary->entry_count].entry, entry);
    diary->entry_count++;

    printf("Entry added successfully!\n");
}

void view_entries(struct Diary diary) {
    if (diary.entry_count == 0) {
        printf("No entries found!\n");
        return;
    }

    for (int i = 0; i < diary.entry_count; i++) {
        printf("=====================================\n");
        printf("Date: %s\n", diary.entries[i].date);
        printf("Entry:\n%s\n", diary.entries[i].entry);
    }
}

void search_entry(struct Diary diary) {
    char search_term[MAX_ENTRY_LENGTH];
    bool found = false;

    printf("Enter search term: ");
    scanf(" %[^\n]s", search_term);

    for (int i = 0; i < diary.entry_count; i++) {
        if (strstr(diary.entries[i].entry, search_term) != NULL) {
            printf("=====================================\n");
            printf("Date: %s\n", diary.entries[i].date);
            printf("Entry:\n%s\n", diary.entries[i].entry);
            found = true;
        }
    }

    if (!found) {
        printf("No entries found matching the search term!\n");
    }
}

int main() {
    struct Diary diary;
    diary.entry_count = 0;

    int choice;
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(&diary);
                break;
            case 2:
                view_entries(diary);
                break;
            case 3:
                search_entry(diary);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}