//FormAI DATASET v1.0 Category: Digital Diary ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ENTRIES 100

struct DiaryEntry {
    char title[50];
    char date[15];
    char content[500];
};

struct Diary {
    int num_entries;
    struct DiaryEntry entry_list[MAX_ENTRIES];
};

int main() {
    struct Diary my_diary;
    my_diary.num_entries = 0;
    int choice;
    do {
        printf("\n\nDigital Diary\n");
        printf("=============================\n");
        printf("1. Add new entry\n");
        printf("2. View all entries\n");
        printf("3. Search for an entry\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (my_diary.num_entries == MAX_ENTRIES) {
                    printf("Diary full, cannot add any more entries\n");
                    break;
                }
                printf("\nEnter the title: ");
                fflush(stdin);
                gets(my_diary.entry_list[my_diary.num_entries].title);
                printf("Enter the date (dd-mm-yyyy): ");
                fflush(stdin);
                gets(my_diary.entry_list[my_diary.num_entries].date);
                printf("Enter the content: ");
                fflush(stdin);
                gets(my_diary.entry_list[my_diary.num_entries].content);
                my_diary.num_entries++;
                printf("Entry added successfully\n");
                break;
            case 2:
                if (my_diary.num_entries == 0) {
                    printf("No entries in diary\n");
                    break;
                }
                printf("\n%-3s %-20s %-15s %s\n", "SR", "Title", "Date", "Content");
                printf("===========================================================\n");
                for (int i = 0; i < my_diary.num_entries; i++) {
                    printf("%-3d %-20s %-15s %s\n", i + 1, my_diary.entry_list[i].title,
                           my_diary.entry_list[i].date, my_diary.entry_list[i].content);
                }
                break;
            case 3:
                if (my_diary.num_entries == 0) {
                    printf("No entries in diary\n");
                    break;
                }
                printf("\nEnter the title to search for: ");
                char search_title[50];
                fflush(stdin);
                gets(search_title);
                int found = 0;
                for (int i = 0; i < my_diary.num_entries; i++) {
                    if (strcmp(search_title, my_diary.entry_list[i].title) == 0) {
                        printf("\n%-3s %-20s %-15s %s\n", "SR", "Title", "Date", "Content");
                        printf("===========================================================\n");
                        printf("%-3d %-20s %-15s %s\n", i + 1, my_diary.entry_list[i].title,
                               my_diary.entry_list[i].date, my_diary.entry_list[i].content);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("No entry found with title '%s'\n", search_title);
                }
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);

    return 0;
}