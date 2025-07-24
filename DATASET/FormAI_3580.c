//FormAI DATASET v1.0 Category: Digital Diary ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

struct DiaryEntry {
    char date[11];
    char time[6];
    char title[30];
    char body[1000];
};

void display_menu() {
    printf("\nDIGITAL DIARY MENU\n"
        "1. Create a new entry\n"
        "2. Edit an existing entry\n"
        "3. Delete an existing entry\n"
        "4. Display all entries\n"
        "5. Search for entries by keyword\n"
        "6. Exit program\n");
}

int get_choice() {
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void create_entry(struct DiaryEntry* entry) {
    printf("\nEnter the date (MM/DD/YYYY): ");
    scanf("%s", entry->date);
    printf("Enter the time (HH:MM): ");
    scanf("%s", entry->time);
    printf("Enter the title: ");
    scanf(" %[^\n]s", entry->title);
    printf("Enter the body text: ");
    scanf(" %[^\n]s", entry->body);
}

void edit_entry(struct DiaryEntry* entry) {
    int field_num;
    printf("\nWhich field would you like to edit?\n"
        "1. Date (MM/DD/YYYY)\n"
        "2. Time (HH:MM)\n"
        "3. Title\n"
        "4. Body\n"
        "Enter your choice: ");
    scanf("%d", &field_num);
    switch (field_num) {
        case 1:
            printf("Enter the new date: ");
            scanf("%s", entry->date);
            break;
        case 2:
            printf("Enter the new time: ");
            scanf("%s", entry->time);
            break;
        case 3:
            printf("Enter the new title: ");
            scanf(" %[^\n]s", entry->title);
            break;
        case 4:
            printf("Enter the new body text: ");
            scanf(" %[^\n]s", entry->body);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

void delete_entry(struct DiaryEntry* entries) {
    char title[30];
    int i, found = 0;
    printf("\nWhich entry would you like to delete?\n"
        "Enter the title: ");
    scanf(" %[^\n]s", title);
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (strcmp(title, entries[i].title) == 0) {
            found = 1;
            entries[i] = entries[MAX_ENTRIES - 1];
            memset(&entries[MAX_ENTRIES - 1], 0, sizeof(struct DiaryEntry));
            printf("Entry deleted.\n");
            break;
        }
    }
    if (!found) {
        printf("Entry not found.\n");
    }
}

void display_all_entries(struct DiaryEntry* entries) {
    int i, count = 0;
    printf("\nALL DIARY ENTRIES\n");
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (strlen(entries[i].title) > 0) {
            printf("\n%d.\nDate: %s\nTime: %s\nTitle: %s\nBody: %s\n",
                ++count, entries[i].date, entries[i].time, entries[i].title, entries[i].body);
        }
    }
}

void search_entries_by_keyword(struct DiaryEntry* entries) {
    char keyword[30];
    int i, count = 0;
    printf("\nEnter the keyword to search for: ");
    scanf(" %[^\n]s", keyword);
    printf("\nENRIES FOUND FOR KEYWORD '%s'\n", keyword);
    for (i = 0; i < MAX_ENTRIES; i++) {
        if (strstr(entries[i].title, keyword) || strstr(entries[i].body, keyword)) {
            printf("\n%d.\nDate: %s\nTime: %s\nTitle: %s\nBody: %s\n",
                ++count, entries[i].date, entries[i].time, entries[i].title, entries[i].body);
        }
    }
    if (count == 0) {
        printf("No entries found for keyword '%s'\n", keyword);
    }
}

int main() {
    struct DiaryEntry entries[MAX_ENTRIES];
    int choice, i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        memset(&entries[i], 0, sizeof(struct DiaryEntry));
    }
    while (1) {
        display_menu();
        choice = get_choice();
        switch (choice) {
            case 1:
                for (i = 0; i < MAX_ENTRIES; i++) {
                    if (strlen(entries[i].title) == 0) {
                        create_entry(&entries[i]);
                        break;
                    }
                }
                if (i == MAX_ENTRIES) {
                    printf("Maximum number of entries reached.\n");
                }
                break;
            case 2:
                edit_entry(entries);
                break;
            case 3:
                delete_entry(entries);
                break;
            case 4:
                display_all_entries(entries);
                break;
            case 5:
                search_entries_by_keyword(entries);
                break;
            case 6:
                printf("\nThank you for using Digital Diary!\n\n");
                return 0;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }
    return 0;
}