//FormAI DATASET v1.0 Category: Digital Diary ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct diary_date {
    int day;
    int month;
    int year;
};

struct diary_entry {
    struct diary_date date;
    char entry[1000];
};

void add_entry(struct diary_entry diary[], int *num_entries);
void print_entries(struct diary_entry diary[], int num_entries);
void search_entries(struct diary_entry diary[], int num_entries, struct diary_date search_date);

int main() {
    struct diary_entry *diary = malloc(sizeof(struct diary_entry));
    int num_entries = 0;
    int choice = 0;
    struct diary_date search_date;
    
    do {
        printf("\nDigital Diary\n");
        printf("1. Add entry\n");
        printf("2. Print all entries\n");
        printf("3. Search entries by date\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_entry(diary, &num_entries);
                break;
            case 2:
                print_entries(diary, num_entries);
                break;
            case 3:
                printf("\nEnter search date (DD MM YYYY): ");
                scanf("%d %d %d", &search_date.day, &search_date.month, &search_date.year);
                search_entries(diary, num_entries, search_date);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
        }
    } while (choice != 4);
    
    free(diary);
    
    return 0;
}

void add_entry(struct diary_entry diary[], int *num_entries) {
    printf("\nEnter the date for this entry (DD MM YYYY): ");
    scanf("%d %d %d", &diary[*num_entries].date.day, &diary[*num_entries].date.month, &diary[*num_entries].date.year);
    printf("\nEnter your diary entry (up to 900 characters):\n");
    scanf(" %[^\n]", diary[*num_entries].entry);
    (*num_entries)++;
}

void print_entries(struct diary_entry diary[], int num_entries) {
    if (num_entries == 0) {
        printf("\nNo entries yet.\n");
    } else {
        for (int i = 0; i < num_entries; i++) {
            printf("\nEntry %d (%d/%d/%d):\n", i + 1, diary[i].date.day, diary[i].date.month, diary[i].date.year);
            printf("%s\n", diary[i].entry);
        }
    }
}

void search_entries(struct diary_entry diary[], int num_entries, struct diary_date search_date) {
    int found = 0;
    for (int i = 0; i < num_entries; i++) {
        if (diary[i].date.day == search_date.day && diary[i].date.month == search_date.month && diary[i].date.year == search_date.year) {
            printf("\nEntry %d (%d/%d/%d):\n", i + 1, diary[i].date.day, diary[i].date.month, diary[i].date.year);
            printf("%s\n", diary[i].entry);
            found = 1;
        }
    }
    if (!found) {
        printf("\nNo entries found for that date.\n");
    }
}