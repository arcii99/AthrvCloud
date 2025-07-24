//FormAI DATASET v1.0 Category: Digital Diary ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000

struct DiaryEntry {
    char text[1000];
    time_t timestamp;
};

struct Diary {
    struct DiaryEntry entries[MAX_ENTRIES];
    int count;
};

void print_menu() {
    printf("1. Write a new entry\n");
    printf("2. View all entries\n");
    printf("3. View entries for a specific date\n");
    printf("4. Exit\n");
}

void write_entry(struct Diary* diary) {
    if (diary->count == MAX_ENTRIES) {
        printf("Diary is full, cannot add new entry.\n");
        return;
    }
    printf("Enter your entry:\n");
    fgets(diary->entries[diary->count].text, 1000, stdin);
    diary->entries[diary->count].timestamp = time(NULL);
    diary->count++;
}

void view_entries(struct Diary* diary) {
    if (diary->count == 0) {
        printf("No entries in diary.\n");
        return;
    }
    for (int i = 0; i < diary->count; i++) {
        char* timestamp_str = ctime(&diary->entries[i].timestamp);
        timestamp_str[strlen(timestamp_str)-1] = '\0';
        printf("%s: %s\n", timestamp_str, diary->entries[i].text);
    }
}

void view_entries_for_date(struct Diary* diary) {
    printf("Enter date (MM/DD/YYYY):\n");
    char date_str[11];
    fgets(date_str, 11, stdin);
    struct tm date = {};
    strptime(date_str, "%m/%d/%Y", &date);
    for (int i = 0; i < diary->count; i++) {
        struct tm entry_date = *localtime(&diary->entries[i].timestamp);
        if (entry_date.tm_year == date.tm_year &&
            entry_date.tm_mon == date.tm_mon &&
            entry_date.tm_mday == date.tm_mday) {
            char* timestamp_str = ctime(&diary->entries[i].timestamp);
            timestamp_str[strlen(timestamp_str)-1] = '\0';
            printf("%s: %s\n", timestamp_str, diary->entries[i].text);
        }
    }
}

int main() {
    struct Diary diary = {};
    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        getchar(); // consume newline left by scanf
        switch (choice) {
            case 1:
                write_entry(&diary);
                break;
            case 2:
                view_entries(&diary);
                break;
            case 3:
                view_entries_for_date(&diary);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }
        printf("\n");
    } while (choice != 4);
    return 0;
}