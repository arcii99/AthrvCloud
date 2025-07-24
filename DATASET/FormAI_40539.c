//FormAI DATASET v1.0 Category: Digital Diary ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100  // maximum number of diary entries
#define MAX_LENGTH 1000  // maximum length of each diary entry

// structure to represent a single diary entry
typedef struct {
    char date[11];  // format: YYYY-MM-DD
    char entry[MAX_LENGTH];
} DiaryEntry;

// function to prompt the user for a menu option
char get_menu_option() {
    char option;
    printf("\nDigital Diary\n");
    printf("==============\n");
    printf("1. View Entries\n");
    printf("2. Add Entry\n");
    printf("3. Search Entries\n");
    printf("4. Delete Entry\n");
    printf("5. Quit\n");
    printf("Enter an option (1-5): ");
    scanf(" %c", &option);
    return option;
}

// function to read the diary entries from a file
int read_entries(DiaryEntry *entries, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }
    int i = 0;
    while (i < MAX_ENTRIES && fscanf(file, "%10s %[^\n]", entries[i].date, entries[i].entry) == 2) {
        i++;
    }
    fclose(file);
    return i;
}

// function to write the diary entries to a file
void write_entries(DiaryEntry *entries, int num_entries, char *filename) {
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < num_entries; i++) {
        fprintf(file, "%s %s\n", entries[i].date, entries[i].entry);
    }
    fclose(file);
}

// function to print a single diary entry
void print_entry(DiaryEntry *entry) {
    printf("Date: %s\n", entry->date);
    printf("%s\n", entry->entry);
}

// function to print all diary entries
void print_entries(DiaryEntry *entries, int num_entries) {
    printf("\nDigital Diary Entries\n");
    printf("======================\n");
    if (num_entries == 0) {
        printf("No entries found.\n");
    }
    else {
        for (int i = 0; i < num_entries; i++) {
            printf("%d. ", i+1);
            print_entry(&entries[i]);
            printf("\n");
        }
    }
}

// function to add a new diary entry
void add_entry(DiaryEntry *entries, int *num_entries) {
    if (*num_entries >= MAX_ENTRIES) {
        printf("Maximum number of entries reached.\n");
        return;
    }
    char date[11];
    printf("Enter the date (YYYY-MM-DD): ");
    scanf(" %10s", date);
    // validate date format
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {
            if (date[i] != '-') {
                printf("Invalid date format.\n");
                return;
            }
        }
        else {
            if (!isdigit(date[i])) {
                printf("Invalid date format.\n");
                return;
            }
        }
    }
    char entry[MAX_LENGTH];
    printf("Enter your diary entry:\n");
    fflush(stdin);
    fgets(entry, MAX_LENGTH, stdin);
    // remove leading/trailing whitespace
    int len = strlen(entry);
    while (len > 0 && isspace(entry[len-1])) {
        entry[len-1] = '\0';
        len--;
    }
    int i = *num_entries;
    strcpy(entries[i].date, date);
    strcpy(entries[i].entry, entry);
    *num_entries += 1;
}

// function to search for diary entries containing a certain keyword
void search_entries(DiaryEntry *entries, int num_entries) {
    char keyword[MAX_LENGTH];
    printf("Enter a keyword to search for: ");
    fflush(stdin);
    fgets(keyword, MAX_LENGTH, stdin);
    // remove leading/trailing whitespace
    int len = strlen(keyword);
    while (len > 0 && isspace(keyword[len-1])) {
        keyword[len-1] = '\0';
        len--;
    }
    printf("\nSearch Results\n");
    printf("==============\n");
    int num_results = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].entry, keyword) != NULL) {
            printf("%d. ", i+1);
            print_entry(&entries[i]);
            printf("\n");
            num_results++;
        }
    }
    if (num_results == 0) {
        printf("No results found.\n");
    }
}

// function to delete a diary entry
void delete_entry(DiaryEntry *entries, int *num_entries) {
    int index;
    printf("Enter the index of the entry to delete: ");
    scanf(" %d", &index);
    if (index < 1 || index > *num_entries) {
        printf("Invalid index.\n");
        return;
    }
    index--;
    for (int i = index; i < *num_entries-1; i++) {
        entries[i] = entries[i+1];
    }
    *num_entries -= 1;
}

// main function
int main() {
    DiaryEntry entries[MAX_ENTRIES];
    int num_entries = read_entries(entries, "diary.txt");
    char option;
    do {
        option = get_menu_option();
        switch (option) {
            case '1':
                print_entries(entries, num_entries);
                break;
            case '2':
                add_entry(entries, &num_entries);
                write_entries(entries, num_entries, "diary.txt");
                break;
            case '3':
                search_entries(entries, num_entries);
                break;
            case '4':
                delete_entry(entries, &num_entries);
                write_entries(entries, num_entries, "diary.txt");
                break;
            case '5':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (option != '5');
    return 0;
}