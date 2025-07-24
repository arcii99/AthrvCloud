//FormAI DATASET v1.0 Category: Digital Diary ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

struct Entry {
    char date[11];
    char text[1000];
};

struct Diary {
    struct Entry entries[MAX_ENTRIES];
    int num_entries;
};

void add_entry(struct Diary *diary) {
    if (diary->num_entries >= MAX_ENTRIES) {
        printf("Diary is full. Cannot add more entries.\n");
        return;
    }

    char date[11];
    char text[1000];

    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%s", date);
    printf("Enter the text: ");
    scanf(" %[^\n]s", text);

    strcpy(diary->entries[diary->num_entries].date, date);
    strcpy(diary->entries[diary->num_entries].text, text);

    diary->num_entries++;
}

void list_entries(struct Diary diary) {
    if (diary.num_entries == 0) {
        printf("Diary is empty.\n");
        return;
    }

    printf("Date\t\tText\n");

    for (int i = 0; i < diary.num_entries; i++) {
        printf("%s\t%s\n", diary.entries[i].date, diary.entries[i].text);
    }
}

int main() {
    struct Diary diary = {0};
    int choice;

    do {
        printf("1. Add Entry\n");
        printf("2. List Entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(&diary);
                break;
            case 2:
                list_entries(diary);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}