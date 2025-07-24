//FormAI DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_MESSAGE_LENGTH 100

// Define a struct to represent a diary entry
struct Entry {
    char date[20];    // date of entry
    char message[MAX_MESSAGE_LENGTH];   // diary message
};

// Define a struct to represent the diary
struct Diary {
    int num_entries;  // keep track of the number of entries
    struct Entry entries[MAX_ENTRIES];  // array of diary entries
} Diary;

// Function to add an entry to the diary
void add_entry(struct Diary *diary, char *date, char *message) {
    // Make sure there's room in the diary
    if (diary->num_entries >= MAX_ENTRIES) {
        printf("Diary is full!\n");
        return;
    }

    // Make sure the date isn't already taken
    for (int i = 0; i < diary->num_entries; i++) {
        if (strcmp(diary->entries[i].date, date) == 0) {
            printf("Entry for that date already exists!\n");
            return;
        }
    }

    // Add the entry to the diary
    strcpy(diary->entries[diary->num_entries].date, date);
    strcpy(diary->entries[diary->num_entries].message, message);
    diary->num_entries++;
}

// Function to print all entries in the diary
void print_entries(struct Diary *diary) {
    for (int i = 0; i < diary->num_entries; i++) {
        printf("%s: %s\n", diary->entries[i].date, diary->entries[i].message);
    }
}

int main() {
    struct Diary diary = {0};  // initialize diary with 0 entries

    // Add some entries to the diary
    add_entry(&diary, "2022-01-01", "Happy New Year!");
    add_entry(&diary, "2022-01-03", "Started working on my project.");
    add_entry(&diary, "2022-01-07", "Had a meeting with my supervisor.");

    // Print all entries from the diary
    print_entries(&diary);

    return 0;
}