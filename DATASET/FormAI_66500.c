//FormAI DATASET v1.0 Category: Digital Diary ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_ENTRY_LENGTH 1000
#define MAX_ENTRIES 50

typedef struct {
    char date[11];
    char time[6];
    char title[50];
    char entry[MAX_ENTRY_LENGTH];
} DiaryEntry;

DiaryEntry diary[MAX_ENTRIES];
int num_entries = 0;

int main() {
    int choice;
    while(1) {
        printf("\n----DIGITAL DIARY----\n");
        printf("1. View Entries\n");
        printf("2. Add Entry\n");
        printf("3. Search Entries\n");
        printf("4. Delete Entry\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                viewEntries();
                break;
            case 2:
                addEntry();
                break;
            case 3:
                searchEntries();
                break;
            case 4:
                deleteEntry();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void viewEntries() {
    printf("\n%d ENTRIES FOUND:\n", num_entries);
    for(int i=0; i<num_entries; i++) {
        printf("\nENTRY %d:\n", i+1);
        printf("Date: %s\n", diary[i].date);
        printf("Time: %s\n", diary[i].time);
        printf("Title: %s\n", diary[i].title);
        printf("Entry:\n%s\n", diary[i].entry);
    }
}

void addEntry() {
    if(num_entries >= MAX_ENTRIES) {
        printf("Cannot add more entries. Diary is full.\n");
        return;
    }
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(diary[num_entries].date, sizeof(diary[num_entries].date), "%d-%m-%Y", t);
    strftime(diary[num_entries].time, sizeof(diary[num_entries].time), "%H:%M", t);
    printf("Enter title for the entry: ");
    getchar();
    fgets(diary[num_entries].title, sizeof(diary[num_entries].title), stdin);
    diary[num_entries].title[strlen(diary[num_entries].title)-1] = '\0';
    printf("Enter the entry:\n");
    fgets(diary[num_entries].entry, MAX_ENTRY_LENGTH, stdin);
    diary[num_entries].entry[strlen(diary[num_entries].entry)-1] = '\0';
    num_entries++;
    printf("Entry added successfully.\n");
}

void searchEntries() {
    char keyword[MAX_ENTRY_LENGTH];
    printf("Enter keyword to search for: ");
    getchar();
    fgets(keyword, MAX_ENTRY_LENGTH, stdin);
    keyword[strlen(keyword)-1] = '\0';
    int found = 0;
    for(int i=0; i<num_entries; i++) {
        if(strstr(diary[i].title, keyword) != NULL || strstr(diary[i].entry, keyword) != NULL) {
            printf("\nENTRY %d:\n", i+1);
            printf("Date: %s\n", diary[i].date);
            printf("Time: %s\n", diary[i].time);
            printf("Title: %s\n", diary[i].title);
            printf("Entry:\n%s\n", diary[i].entry);
            found = 1;
        }
    }
    if(!found) {
        printf("No entries found for keyword: %s\n", keyword);
    }
}

void deleteEntry() {
    int entry_num;
    printf("Enter entry number to delete: ");
    scanf("%d", &entry_num);
    if(entry_num <= 0 || entry_num > num_entries) {
        printf("Invalid entry number.\n");
        return;
    }
    entry_num--;
    for(int i=entry_num; i<num_entries-1; i++) {
        diary[i] = diary[i+1];
    }
    num_entries--;
    printf("Entry %d deleted successfully.\n", entry_num+1);
}