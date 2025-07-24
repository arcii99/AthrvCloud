//FormAI DATASET v1.0 Category: Digital Diary ; Style: introspective
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100

// Define a struct for a Diary Entry
typedef struct {
    char date[11];
    char time[6];
    char note[1000];
} DiaryEntry;

// Define a struct for the Digital Diary
typedef struct {
    int num_entries;
    DiaryEntry entries[MAX_ENTRIES];
} DigitalDiary;

// Function to add Diary Entry to Digital Diary
void addEntry(DigitalDiary* diary) {
    DiaryEntry new_entry;
    printf("Enter the date (DD/MM/YYYY): ");
    scanf("%s", new_entry.date);
    printf("Enter the time (HH:MM): ");
    scanf("%s", new_entry.time);
    printf("Enter the note: ");
    getchar();
    fgets(new_entry.note, 1000, stdin);
    strcpy(diary->entries[diary->num_entries].date, new_entry.date);
    strcpy(diary->entries[diary->num_entries].time, new_entry.time);
    strcpy(diary->entries[diary->num_entries].note, new_entry.note);
    diary->num_entries++;
    printf("Entry added successfully!\n");
}

// Function to display all Diary Entries in Digital Diary
void displayEntries(DigitalDiary diary) {
    printf("\n--- Diary Entries ---\n");
    for(int i=0; i<diary.num_entries; i++) {
        printf("Date: %s\n", diary.entries[i].date);
        printf("Time: %s\n", diary.entries[i].time);
        printf("Note: %s\n", diary.entries[i].note);
        printf("---------------------\n");
    }
}

// Function to display a specific Diary Entry in Digital Diary
void displayEntry(DigitalDiary diary) {
    char search[11];
    printf("Enter the date of the entry to display (DD/MM/YYYY): ");
    scanf("%s", search);
    for(int i=0; i<diary.num_entries; i++) {
        if(strcmp(search, diary.entries[i].date) == 0) {
            printf("\n--- Diary Entry ---\n");
            printf("Date: %s\n", diary.entries[i].date);
            printf("Time: %s\n", diary.entries[i].time);
            printf("Note: %s\n", diary.entries[i].note);
            printf("--------------------\n");
            return;
        }
    }
    printf("Entry not found!\n");
}

// Main function
int main() {
    DigitalDiary diary;
    diary.num_entries = 0;
    int choice = 0;
    while(choice != 4) {
        printf("\n--- Digital Diary ---\n");
        printf("1. Add Entry\n");
        printf("2. Display All Entries\n");
        printf("3. Display Entry\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addEntry(&diary);
                break;
            case 2:
                displayEntries(diary);
                break;
            case 3:
                displayEntry(diary);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}