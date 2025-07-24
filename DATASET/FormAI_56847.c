//FormAI DATASET v1.0 Category: Digital Diary ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ENTRIES 10

struct diary_entry {
    char date[11];
    char title[25];
    char body[100];
};

void add_entry(struct diary_entry *entries, int *entry_count) {
    if (*entry_count >= MAX_ENTRIES) {
        printf("Diary is full, cannot add more entries.\n");
        return;
    }
    printf("Enter date (DD/MM/YYYY): ");
    scanf("%10s", entries[*entry_count].date);
    printf("Enter title (max 24 characters): ");
    scanf("%24s", entries[*entry_count].title);
    printf("Enter body (max 99 characters): ");
    scanf("%99s", entries[*entry_count].body);
    printf("Entry added successfully.\n");
    (*entry_count)++;
}

void list_entries(struct diary_entry *entries, int entry_count) {
    printf("\nDate       |Title                 |Entry\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < entry_count; i++) {
        printf("%-10s | %-20s | %s\n", entries[i].date, entries[i].title, entries[i].body);
    }
}

int main() {
    struct diary_entry entries[MAX_ENTRIES];
    int entry_count = 0;
    char menu_choice;
    
    printf("Welcome to your digital diary!\n");
    
    do {
        printf("\nMenu:\n");
        printf("1. Add entry\n");
        printf("2. List entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%1s", &menu_choice);
        switch (menu_choice) {
            case '1':
                add_entry(entries, &entry_count);
                break;
            case '2':
                list_entries(entries, entry_count);
                break;
            case '3':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (menu_choice != '3');
    
    return 0;
}