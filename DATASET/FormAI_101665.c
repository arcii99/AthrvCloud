//FormAI DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct password_entry {
    char website[50];
    char username[50];
    char password[50];
};

void add_entry(struct password_entry *entries, int *num_entries) {
    if (*num_entries == MAX_ENTRIES) {
        printf("Error: could not add entry - maximum number of entries reached (%d)\n", MAX_ENTRIES);
        return;
    }

    struct password_entry new_entry;
    printf("Enter website: ");
    fgets(new_entry.website, 50, stdin);
    printf("Enter username: ");
    fgets(new_entry.username, 50, stdin);
    printf("Enter password: ");
    fgets(new_entry.password, 50, stdin);
    entries[*num_entries] = new_entry;
    (*num_entries)++;
    printf("Entry added successfully.\n");
}

void print_entries(struct password_entry *entries, int num_entries) {
    printf("Website\t\tUsername\t\tPassword\n");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%s\t\t%s\t\t%s", entries[i].website, entries[i].username, entries[i].password);
    }
}

int main() {
    int num_entries = 0;
    struct password_entry entries[MAX_ENTRIES];
    char input[50];

    printf("Welcome to the password manager!\n");
    while (1) {
        printf("\n1. Add entry\n");
        printf("2. Print entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        fgets(input, 50, stdin);

        if (strcmp(input, "1\n") == 0) {
            add_entry(entries, &num_entries);
        } else if (strcmp(input, "2\n") == 0) {
            print_entries(entries, num_entries);
        } else if (strcmp(input, "3\n") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}