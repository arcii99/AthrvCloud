//FormAI DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Define maximum size of the diary
#define MAX_SIZE 1000

// Struct for a single diary entry
struct DiaryEntry {
    char date[20];
    char content[MAX_SIZE];
};

// Struct for the whole diary
struct Diary {
    int num_entries;
    struct DiaryEntry entries[MAX_SIZE];
};

// Prints the main menu
void print_menu() {
    printf("\n\nWelcome to Your Digital Diary\n\n");
    printf("1. Add new entry\n");
    printf("2. View all entries\n");
    printf("3. Search for an entry\n");
    printf("4. Delete an entry\n");
    printf("5. Exit\n");
}

// Gets the user's choice from the menu
int get_choice() {
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Adds a new diary entry
void add_entry(struct Diary* diary) {
    // Get the current date
    time_t current_time = time(NULL);
    struct tm* tm = localtime(&current_time);
    sprintf(diary->entries[diary->num_entries].date, "%02d/%02d/%04d", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);

    // Get the content from the user
    printf("\nEnter the content for your new entry:\n");
    getchar();
    fgets(diary->entries[diary->num_entries].content, MAX_SIZE, stdin);

    // Increment the number of entries in the diary
    diary->num_entries++;
    printf("\nYour entry has been added to the diary.\n");
}

// Prints all entries in the diary
void view_entries(struct Diary diary) {
    if (diary.num_entries == 0) {
        printf("\nThere are no entries in the diary.\n");
        return;
    }

    printf("\n\nAll Entries:\n");
    for (int i = 0; i < diary.num_entries; i++) {
        printf("\nDate: %s\n", diary.entries[i].date);
        printf("Content: %s\n", diary.entries[i].content);
    }
}

// Searches for an entry by keyword
void search_entries(struct Diary diary) {
    if (diary.num_entries == 0) {
        printf("\nThere are no entries in the diary.\n");
        return;
    }

    // Get the keyword from the user
    printf("\nEnter a keyword to search for: ");
    char keyword[MAX_SIZE];
    getchar();
    fgets(keyword, MAX_SIZE, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    // Search all entries for the keyword
    int found = 0;
    for (int i = 0; i < diary.num_entries; i++) {
        if (strstr(diary.entries[i].content, keyword) != NULL) {
            printf("\nDate: %s\n", diary.entries[i].date);
            printf("Content: %s\n", diary.entries[i].content);
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo entries were found with the keyword '%s'.\n", keyword);
    }
}

// Deletes an entry by date
void delete_entry(struct Diary* diary) {
    if (diary->num_entries == 0) {
        printf("\nThere are no entries in the diary.\n");
        return;
    }

    // Get the date from the user
    printf("\nEnter the date of the entry to delete (in the format dd/mm/yyyy): ");
    char date[20];
    scanf("%s", date);

    // Search for the entry with the given date
    int found = 0;
    for (int i = 0; i < diary->num_entries; i++) {
        if (strcmp(diary->entries[i].date, date) == 0) {
            // Shift all entries after this one back by one to overwrite it
            for (int j = i; j < diary->num_entries - 1; j++) {
                strcpy(diary->entries[j].date, diary->entries[j + 1].date);
                strcpy(diary->entries[j].content, diary->entries[j + 1].content);
            }
            diary->num_entries--;
            found = 1;
            printf("\nThe entry for %s has been deleted.\n", date);
            break;
        }
    }

    if (!found) {
        printf("\nNo entry was found with the date '%s'.\n", date);
    }
}

int main() {
    // Create an empty diary
    struct Diary diary;
    diary.num_entries = 0;

    while (1) {
        print_menu();
        int choice = get_choice();

        switch (choice) {
            case 1:
                add_entry(&diary);
                break;
            case 2:
                view_entries(diary);
                break;
            case 3:
                search_entries(diary);
                break;
            case 4:
                delete_entry(&diary);
                break;
            case 5:
                printf("\nThank you for using Your Digital Diary. Goodbye!\n\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}