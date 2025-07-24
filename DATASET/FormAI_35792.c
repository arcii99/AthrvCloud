//FormAI DATASET v1.0 Category: Digital Diary ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 50

struct DiaryEntry {
    int day, month, year;
    char content[500];
};

struct Diary {
    struct DiaryEntry entries[MAX_ENTRIES];
    int num_entries;
};

int get_current_day() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    return tm->tm_mday;
}

int get_current_month() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    return tm->tm_mon + 1;
}

int get_current_year() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    return tm->tm_year + 1900;
}

void clear_screen() {
    system("clear");
}

void print_menu() {
    clear_screen();
    printf("##### Digital Diary #####\n");
    printf("1. Add Entry\n");
    printf("2. List Entries\n");
    printf("3. Search Entries\n");
    printf("4. Exit\n");
    printf("#########################\n");
}

void add_entry(struct Diary *diary) {
    clear_screen();
    printf("Enter content (up to 500 characters):\n");
    fgets(diary->entries[diary->num_entries].content, 500, stdin);
    diary->entries[diary->num_entries].day = get_current_day();
    diary->entries[diary->num_entries].month = get_current_month();
    diary->entries[diary->num_entries].year = get_current_year();
    diary->num_entries++;
    printf("Entry added successfully.\n");
}

void list_entries(struct Diary *diary) {
    clear_screen();
    printf("##### List of Entries #####\n");
    for (int i = 0; i < diary->num_entries; i++) {
        printf("Date: %d/%d/%d\n", diary->entries[i].day, diary->entries[i].month, diary->entries[i].year);
        printf("Content: %s\n", diary->entries[i].content);
        printf("------------------------\n");
    }
}

void search_entries(struct Diary *diary) {
    clear_screen();
    char query[500];
    printf("Enter search query (up to 500 characters):\n");
    fgets(query, 500, stdin);
    printf("##### Search Results #####\n");
    for (int i = 0; i < diary->num_entries; i++) {
        if (strstr(diary->entries[i].content, query) != NULL) {
            printf("Date: %d/%d/%d\n", diary->entries[i].day, diary->entries[i].month, diary->entries[i].year);
            printf("Content: %s\n", diary->entries[i].content);
            printf("------------------------\n");
        }
    }
}

int main() {
    int choice;
    struct Diary diary = {.num_entries = 0};
    do {
        print_menu();
        printf("Enter option: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                add_entry(&diary);
                break;
            case 2:
                list_entries(&diary);
                break;
            case 3:
                search_entries(&diary);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
        getchar();
    } while (choice != 4);
    return 0;
}