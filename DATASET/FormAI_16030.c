//FormAI DATASET v1.0 Category: Digital Diary ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100

// Each diary entry will contain a date and some text
struct DiaryEntry {
    time_t date;
    char text[1000];
};

// Diary object contains an array to store diary entries
struct Diary {
    struct DiaryEntry entries[MAX_ENTRIES];
    int num_entries;
};

// Function to add a new diary entry
int add_entry(struct Diary* diary, char* entry_text) {
    time_t t = time(NULL);
    if(diary->num_entries >= MAX_ENTRIES) {
        printf("Diary full, cannot add more entries.\n");
        return -1;
    }
    diary->entries[diary->num_entries].date = t;
    strcpy(diary->entries[diary->num_entries].text, entry_text);
    diary->num_entries++;
    printf("Entry added successfully.\n");
    return 0;
}

// Function to display all diary entries
void display_all_entries(struct Diary diary) {
    printf("DIARY ENTRIES:\n");
    for(int i=0; i<diary.num_entries; i++) {
        printf("%s\n", ctime(&(diary.entries[i].date)));
        printf("%s\n", diary.entries[i].text);
        printf("--------------------------------------------------\n");
    }
}

// Function to display all diary entries for a particular year
void display_entries_for_year(struct Diary diary, int year) {
    printf("DIARY ENTRIES FOR YEAR %d:\n", year);
    for(int i=0; i<diary.num_entries; i++) {
        struct tm* date = localtime(&(diary.entries[i].date));
        if(date->tm_year + 1900 == year) {
            printf("%s\n", ctime(&(diary.entries[i].date)));
            printf("%s\n", diary.entries[i].text);
            printf("--------------------------------------------------\n");
        }
    }
}

int main() {
    struct Diary diary;
    diary.num_entries = 0;
    int choice = 0;
    char entry_text[1000];
    int year;

    while(choice != 4) {
        printf("MENU:\n");
        printf("1. Add new diary entry\n");
        printf("2. Display all diary entries\n");
        printf("3. Display all diary entries for a particular year\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter diary entry: ");
                getchar();
                fgets(entry_text, 1000, stdin);
                add_entry(&diary, entry_text);
                break;
            case 2:
                display_all_entries(diary);
                break;
            case 3:
                printf("Enter year: ");
                scanf("%d", &year);
                display_entries_for_year(diary, year);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}