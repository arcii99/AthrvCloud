//FormAI DATASET v1.0 Category: Password management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 25 // Maximum password length
#define MAX_ENTRY_LENGTH 100 // Maximum length of password entry

// Structure for storing password entries
typedef struct entry {
    char site[MAX_ENTRY_LENGTH];
    char username[MAX_ENTRY_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} entry_t;

// Function for adding new password entry
void add_entry(entry_t *entries, int *num_entries)
{
    entry_t new_entry;

    printf("Enter site name: ");
    fgets(new_entry.site, MAX_ENTRY_LENGTH, stdin);
    printf("Enter username: ");
    fgets(new_entry.username, MAX_ENTRY_LENGTH, stdin);
    printf("Enter password: ");
    fgets(new_entry.password, MAX_PASSWORD_LENGTH, stdin);

    // Remove newline characters from input
    new_entry.site[strcspn(new_entry.site, "\n")] = '\0';
    new_entry.username[strcspn(new_entry.username, "\n")] = '\0';
    new_entry.password[strcspn(new_entry.password, "\n")] = '\0';

    entries[*num_entries] = new_entry; // Add new entry to array of entries
    (*num_entries)++; // Increment number of entries
    printf("Password entry added successfully.\n");
}

// Function for searching for password entry by site name
void search_entry(entry_t *entries, int num_entries)
{
    char search_site[MAX_ENTRY_LENGTH];
    printf("Enter site name to search for: ");
    fgets(search_site, MAX_ENTRY_LENGTH, stdin);
    search_site[strcspn(search_site, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].site, search_site) == 0) {
            printf("Site: %s\n", entries[i].site);
            printf("Username: %s\n", entries[i].username);
            printf("Password: %s\n", entries[i].password);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No password entry found for site '%s'.\n", search_site);
    }
}

// Main function
int main()
{
    entry_t entries[1000]; // Array of password entries
    int num_entries = 0; // Number of password entries
    char choice;

    printf("Password Management System\n");
    printf("==========================\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add new entry\n");
        printf("2. Search for entry\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        choice = getchar();

        switch (choice) {
            case '1':
                getchar(); // Remove newline character from input buffer
                add_entry(entries, &num_entries);
                break;
            case '2':
                getchar(); // Remove newline character from input buffer
                search_entry(entries, num_entries);
                break;
            case '3':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                getchar(); // Remove newline character from input buffer
                break;
        }
    }

    return 0;
}