//FormAI DATASET v1.0 Category: Digital Diary ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constant values for month and year
#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12

#define MIN_YEAR 1900
#define MAX_YEAR 2100

// Define structure for date
typedef struct date {
    int day;
    int month;
    int year;
} date_t;

// Define structure for diary entry
typedef struct diary_entry {
    date_t date;
    char message[1000];
} diary_entry_t;

// Define function to get a valid date
date_t get_date() {
    date_t date;
    int day, month, year;
    char input[1000];

    // Get day
    printf("Enter day: ");
    fgets(input, 1000, stdin);
    day = atoi(input);
    while (day < 1 || day > 31) {
        printf("Invalid input. Enter day (1-31): ");
        fgets(input, 1000, stdin);
        day = atoi(input);
    }
    date.day = day;

    // Get month
    printf("Enter month (1-12): ");
    fgets(input, 1000, stdin);
    month = atoi(input);
    while (month < 1 || month > 12) {
        printf("Invalid input. Enter month (1-12): ");
        fgets(input, 1000, stdin);
        month = atoi(input);
    }
    date.month = month;

    // Get year
    printf("Enter year (%d-%d): ", MIN_YEAR, MAX_YEAR);
    fgets(input, 1000, stdin);
    year = atoi(input);
    while (year < MIN_YEAR || year > MAX_YEAR) {
        printf("Invalid input. Enter year (%d-%d): ", MIN_YEAR, MAX_YEAR);
        fgets(input, 1000, stdin);
        year = atoi(input);
    }
    date.year = year;

    return date;
}

// Define function to add a diary entry
void add_entry(diary_entry_t *entries, int *num_entries) {
    diary_entry_t entry;
    char message[1000];

    // Get date
    entry.date = get_date();

    // Get message
    printf("Enter message for %02d/%02d/%d: ", entry.date.day, entry.date.month, entry.date.year);
    fgets(message, 1000, stdin);
    strncpy(entry.message, message, sizeof(entry.message));

    // Add entry to the diary
    entries[*num_entries] = entry;
    (*num_entries)++;
    printf("Diary entry added successfully!\n");
}

// Define function to remove a diary entry
void remove_entry(diary_entry_t *entries, int *num_entries) {
    date_t date;
    int i, index = -1;

    // Get date
    date = get_date();

    // Find entry with the given date
    for (i = 0; i < *num_entries; i++) {
        if (entries[i].date.day == date.day &&
            entries[i].date.month == date.month &&
            entries[i].date.year == date.year) {
            index = i;
            break;
        }
    }

    // Remove entry if found
    if (index != -1) {
        for (i = index; i < *num_entries - 1; i++) {
            entries[i] = entries[i + 1];
        }
        (*num_entries)--;
        printf("Diary entry removed successfully!\n");
    } else {
        printf("No diary entry found with the given date.\n");
    }
}

// Define function to show all diary entries
void show_entries(diary_entry_t *entries, int num_entries) {
    int i;

    if (num_entries == 0) {
        printf("No diary entries found.\n");
    } else {
        printf("Showing all diary entries:\n");
        printf("------------------------------\n");
        for (i = 0; i < num_entries; i++) {
            printf("%02d/%02d/%d: %s", entries[i].date.day, entries[i].date.month, entries[i].date.year, entries[i].message);
        }
    }
}

// Define main function
int main() {
    diary_entry_t entries[1000];
    int num_entries = 0;
    char input[1000];
    int choice;

    while (1) {
        // Show menu
        printf("\n");
        printf("Digital Diary\n");
        printf("================================\n");
        printf("1. Add diary entry\n");
        printf("2. Remove diary entry\n");
        printf("3. Show all diary entries\n");
        printf("4. Quit\n");
        printf("Enter your choice (1-4): ");

        // Get user choice
        fgets(input, 1000, stdin);
        choice = atoi(input);

        // Perform corresponding action
        switch (choice) {
        case 1:
            add_entry(entries, &num_entries);
            break;
        case 2:
            remove_entry(entries, &num_entries);
            break;
        case 3:
            show_entries(entries, num_entries);
            break;
        case 4:
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Invalid input. Please enter a number from 1 to 4.\n");
        }
    }

    return 0;
}