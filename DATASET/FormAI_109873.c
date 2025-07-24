//FormAI DATASET v1.0 Category: Digital Diary ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char date[20];
    char entry[2000];
} Diary;

void add_entry(Diary *diary) {
    char date[20];
    char entry[2000];
    printf("Enter today's date (DD-MM-YYYY): ");
    scanf("%s", date);
    strcpy(diary->date, date);
    printf("Enter your today's entry: ");
    getchar(); // Removing the newline character from the buffer
    fgets(entry, sizeof(entry), stdin);
    strcpy(diary->entry, entry);
    printf("Entry added successfully!\n");
}

void view_entry(Diary diary) {
    printf("Date: %s\n", diary.date);
    printf("Entry: %s\n", diary.entry);
}

int main() {
    Diary diary;
    int choice;

    while (1) {
        printf("\nWelcome to your Digital Diary!\n");
        printf("1. Add a new entry\n2. View previous entry\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_entry(&diary);
                break;
            case 2:
                view_entry(diary);
                break;
            case 3:
                printf("Goodbye!");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}