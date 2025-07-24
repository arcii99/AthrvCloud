//FormAI DATASET v1.0 Category: Phone Book ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15
#define MAX_ENTRIES 100

typedef struct phonebook_entry {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} entry_t;

entry_t phonebook[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    if (num_entries == MAX_ENTRIES) {
        printf("Error: Maximum phonebook entries reached\n");
        return;
    }

    entry_t new_entry;
    printf("Enter name: ");
    fgets(new_entry.name, MAX_NAME_LENGTH, stdin);

    printf("Enter number: ");
    fgets(new_entry.number, MAX_NUMBER_LENGTH, stdin);

    // Remove any newline characters from the input
    new_entry.name[strcspn(new_entry.name, "\n")] = '\0';
    new_entry.number[strcspn(new_entry.number, "\n")] = '\0';

    phonebook[num_entries] = new_entry;
    num_entries++;
    printf("Entry added successfully\n");
}

void search_entries() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(search_name, MAX_NAME_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = '\0';

    int num_matches = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(search_name, phonebook[i].name) == 0) {
            printf("%s: %s\n", phonebook[i].name, phonebook[i].number);
            num_matches++;
        }
    }

    if (num_matches == 0) {
        printf("No entries found\n");
    }
}

void print_phonebook() {
    if (num_entries == 0) {
        printf("Phonebook is empty\n");
        return;
    }

    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s\n", phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    char input[10];
    while (1) {
        printf("Enter command (add, search, print, quit): ");
        fgets(input, 10, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "add") == 0) {
            add_entry();
        }
        else if (strcmp(input, "search") == 0) {
            search_entries();
        }
        else if (strcmp(input, "print") == 0) {
            print_phonebook();
        }
        else if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            return 0;
        }
        else {
            printf("Invalid command\n");
        }
    }
}