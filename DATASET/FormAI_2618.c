//FormAI DATASET v1.0 Category: Digital Diary ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    int day;
    int month;
    int year;
    char entry[200];
} DiaryEntry;

int num_entries = 0;
DiaryEntry entries[MAX_ENTRIES];

int main(void) {

    int choice = 0;

    while (choice != 4) {
        printf("Welcome to your Digital Diary!\n");
        printf("1) Add a new entry\n");
        printf("2) Read an entry\n");
        printf("3) List all entries\n");
        printf("4) Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                read_entry();
                break;
            case 3:
                list_entries();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Please enter a number between 1 and 4.\n");
                break;
        }
    }

    return 0;
}

void add_entry() {

    if (num_entries >= MAX_ENTRIES) {
        printf("Maximum number of entries reached.\n");
        return;
    }

    DiaryEntry new_entry;
    printf("Please enter the date in the format DD/MM/YYYY: ");
    scanf("%d/%d/%d", &new_entry.day, &new_entry.month, &new_entry.year);
    printf("Please enter your entry (200 characters maximum):\n");
    getchar(); // clear input buffer
    fgets(new_entry.entry, 200, stdin);

    entries[num_entries] = new_entry;
    num_entries++;

    printf("Entry added successfully!\n\n");
}

void read_entry() {

    int day, month, year;
    printf("Please enter the date of the entry you want to read in the format DD/MM/YYYY: ");
    scanf("%d/%d/%d", &day, &month, &year);

    printf("\n");

    int found_entry = 0;
    for (int i = 0; i < num_entries; i++) {
        if (day == entries[i].day && month == entries[i].month && year == entries[i].year) {
            printf("%d/%d/%d: %s\n", entries[i].day, entries[i].month, entries[i].year, entries[i].entry);
            found_entry = 1;
            break; // no need to keep looking
        }
    }

    if (!found_entry) {
        printf("Entry not found for that date.\n");
    }

    printf("\n");
}

void list_entries() {

    if (num_entries == 0) {
        printf("No entries found.\n\n");
        return;
    }

    printf("Date       | Entry\n");
    printf("-------------------------\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%02d/%02d/%04d | %s\n", entries[i].day, entries[i].month, entries[i].year, entries[i].entry);
    }

    printf("\n");
}