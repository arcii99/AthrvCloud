//FormAI DATASET v1.0 Category: Digital Diary ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Entry {
    char title[50];
    char date[12];
    char text[500];
};

void menu() {
    printf("\nDigital Diary Menu:\n");
    printf("--------------------\n");
    printf("1. Create new entry\n");
    printf("2. Delete an entry\n");
    printf("3. Modify an entry\n");
    printf("4. List all entries\n");
    printf("5. Exit\n");
}

void createEntry(struct Entry *entry, int *count) {
    printf("Enter title: ");
    scanf("%49s", entry[*count].title);
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%11s", entry[*count].date);
    printf("Enter text (500 character limit):\n");
    scanf("%499s", entry[*count].text);
    *count += 1;
    printf("Entry created successfully!\n");
}

void deleteEntry(struct Entry *entry, int *count) {
    if (*count == 0) {
        printf("No entries available to delete.\n");   
    }
    else {
        int index = -1;
        char title[50];
        printf("Enter title of entry to delete: ");
        scanf("%49s", title);
        for (int i = 0; i < *count; i++) {
            if (strcmp(entry[i].title, title) == 0) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            printf("Entry not found.\n");
        }
        else {
            for (int i = index; i < (*count)-1; i++) {
                entry[i] = entry[i+1];
            }
            *count -= 1;
            printf("Entry deleted successfully!\n");
        }
    }
}

void modifyEntry(struct Entry *entry, int count) {
    if (count == 0) {
        printf("No entries available to modify.\n");   
    }
    else {
        char title[50];
        printf("Enter title of entry to modify: ");
        scanf("%49s", title);
        for (int i = 0; i < count; i++) {
            if (strcmp(entry[i].title, title) == 0) {
                printf("Enter new date (MM/DD/YYYY): ");
                scanf("%11s", entry[i].date);
                printf("Enter new text (500 character limit):\n");
                scanf("%499s", entry[i].text);
                printf("Entry modified successfully!\n");
                break;
            }
            if (i == count-1) {
                printf("Entry not found.\n");
            }
        }
    }
}

void listEntries(struct Entry *entry, int count) {
    printf("Entry count: %d\n", count);
    printf("Title\t\t\t\tDate\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-30s\t%s\n", entry[i].title, entry[i].date);
    }
}

int main() {
    struct Entry entries[100];
    int count = 0;
    int choice = 0;
    while (choice != 5) {
        menu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createEntry(entries, &count);
                break;
            case 2:
                deleteEntry(entries, &count);
                break;
            case 3:
                modifyEntry(entries, count);
                break;
            case 4:
                listEntries(entries, count);
                break;
            case 5:
                printf("Thank you! Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}