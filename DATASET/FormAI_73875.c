//FormAI DATASET v1.0 Category: Digital Diary ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 50
#define MAX_CHARS 200

struct diary_entry {
    char title[MAX_CHARS];
    char content[MAX_CHARS];
    char date[MAX_CHARS];
};

int num_entries = 0;
struct diary_entry entries[MAX_ENTRIES];

void add_entry() {
    if (num_entries == MAX_ENTRIES) {
        printf("Sorry, the diary is full.\n");
        return;
    }
    struct diary_entry new_entry;
    printf("Enter the title of the new entry: ");
    fgets(new_entry.title, MAX_CHARS, stdin);
    printf("Enter the date of the new entry (format: yyyy/mm/dd): ");
    fgets(new_entry.date, MAX_CHARS, stdin);
    printf("Enter the content of the new entry: ");
    fgets(new_entry.content, MAX_CHARS, stdin);
    entries[num_entries] = new_entry;
    num_entries++;
    printf("Entry added successfully.\n");
}

void list_entries() {
    for (int i = 0; i < num_entries; i++) {
        printf("Entry %d\n", i + 1);
        printf("Title: %s", entries[i].title);
        printf("Date: %s", entries[i].date);
        printf("Content: %s", entries[i].content);
    }
}

void search_entries() {
    char search_term[MAX_CHARS];
    printf("Enter search term: ");
    fgets(search_term, MAX_CHARS, stdin);
    printf("Matching entries:\n");
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].title, search_term) || strstr(entries[i].content, search_term)) {
            printf("Entry %d\n", i + 1);
            printf("Title: %s", entries[i].title);
            printf("Date: %s", entries[i].date);
            printf("Content: %s", entries[i].content);
        }
    }
}

void save_entries(char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Sorry, unable to save diary.\n");
        return;
    }
    for (int i = 0; i < num_entries; i++) {
        fprintf(fp, "%s%s%s", entries[i].title, entries[i].date, entries[i].content);
    }
    fclose(fp);
    printf("Diary saved successfully.\n");
}

void load_entries(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Sorry, unable to load diary.\n");
        return;
    }
    struct diary_entry temp;
    while (fscanf(fp, "%s%s%s", temp.title, temp.date, temp.content) == 3) {
        entries[num_entries] = temp;
        num_entries++;
    }
    fclose(fp);
    printf("Diary loaded successfully.\n");
}

int main() {
    char command[MAX_CHARS];
    char filename[MAX_CHARS];
    printf("Welcome to your digital diary!\n");
    while (1) {
        printf("Enter a command (add, list, search, save, load, exit): ");
        fgets(command, MAX_CHARS, stdin);
        command[strcspn(command, "\n")] = 0; // remove trailing newline
        if (strcmp(command, "add") == 0) {
            add_entry();
        } else if (strcmp(command, "list") == 0) {
            list_entries();
        } else if (strcmp(command, "search") == 0) {
            search_entries();
        } else if (strcmp(command, "save") == 0) {
            printf("Enter filename: ");
            fgets(filename, MAX_CHARS, stdin);
            filename[strcspn(filename, "\n")] = 0; // remove trailing newline
            save_entries(filename);
        } else if (strcmp(command, "load") == 0) {
            printf("Enter filename: ");
            fgets(filename, MAX_CHARS, stdin);
            filename[strcspn(filename, "\n")] = 0; // remove trailing newline
            load_entries(filename);
        } else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}