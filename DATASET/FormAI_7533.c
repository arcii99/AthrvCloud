//FormAI DATASET v1.0 Category: Password management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char website[MAX_SIZE];
    char username[MAX_SIZE];
    char password[MAX_SIZE];
} PasswordEntry;

void add_entry(PasswordEntry* p_entry, int* p_count) {
    if (*p_count >= MAX_SIZE) {
        printf("Error: Password manager is full\n");
        return;
    }

    printf("Enter website: ");
    scanf("%s", p_entry[*p_count].website);

    printf("Enter username: ");
    scanf("%s", p_entry[*p_count].username);

    printf("Enter password: ");
    scanf("%s", p_entry[*p_count].password);

    printf("Password added successfully\n");
    (*p_count)++;
}

void view_entries(PasswordEntry* p_entry, int count) {
    if (count == 0) {
        printf("Password manager is currently empty\n");
        return;
    }

    printf("%-20s %-20s %-20s\n", "Website", "Username", "Password");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-20s %-20s %-20s\n", p_entry[i].website, p_entry[i].username, p_entry[i].password);
    }
}

void search_entries(PasswordEntry* p_entry, int count, char* search_term) {
    int results_found = 0;

    for (int i = 0; i < count; i++) {
        if (strstr(p_entry[i].website, search_term) || strstr(p_entry[i].username, search_term)) {
            printf("%-20s %-20s %-20s\n", "Website", "Username", "Password");
            printf("-------------------------------------------------------\n");
            printf("%-20s %-20s %-20s\n", p_entry[i].website, p_entry[i].username, p_entry[i].password);
            results_found = 1;
        }
    }

    if (!results_found) {
        printf("No results found for search term '%s'\n", search_term);
    }
}

void delete_entry(PasswordEntry* p_entry, int* p_count, char* website) {
    int entry_found = 0;

    for (int i = 0; i < *p_count; i++) {
        if (strcmp(p_entry[i].website, website) == 0) {
            entry_found = 1;

            printf("Are you sure you want to delete the following entry?\n");
            printf("%-20s %-20s %-20s\n", "Website", "Username", "Password");
            printf("-------------------------------------------------------\n");
            printf("%-20s %-20s %-20s\n", p_entry[i].website, p_entry[i].username, p_entry[i].password);

            char confirm[MAX_SIZE];
            printf("Type 'yes' to confirm deletion: ");
            scanf("%s", confirm);

            if (strcmp(confirm, "yes") == 0) {
                memmove(&p_entry[i], &p_entry[i+1], (*p_count - i - 1) * sizeof(PasswordEntry));
                (*p_count)--;
                printf("Entry deleted successfully\n");
            } else {
                printf("Deletion cancelled\n");
            }

            break;
        }
    }

    if (!entry_found) {
        printf("No entry found for website '%s'\n", website);
    }
}

int main(void) {
    PasswordEntry password_manager[MAX_SIZE];
    int password_count = 0;

    while (1) {
        char choice;
        printf("\nEnter choice:\n"
               "1. Add password entry\n"
               "2. View password entries\n"
               "3. Search for password entry\n"
               "4. Delete password entry\n"
               "5. Exit\n"
               "Choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                add_entry(password_manager, &password_count);
                break;
            case '2':
                view_entries(password_manager, password_count);
                break;
            case '3':
                char search_term[MAX_SIZE];
                printf("Enter search term: ");
                scanf("%s", search_term);
                search_entries(password_manager, password_count, search_term);
                break;
            case '4':
                char website[MAX_SIZE];
                printf("Enter website to delete: ");
                scanf("%s", website);
                delete_entry(password_manager, &password_count, website);
                break;
            case '5':
                printf("Goodbye\n");
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    }

    return 0;
}