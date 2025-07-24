//FormAI DATASET v1.0 Category: Digital Diary ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ENTRIES 1000

struct Entry {
    char timestamp[20];
    char title[100];
    char content[1000];
};

struct Diary {
    struct Entry entries[MAX_ENTRIES];
    int num_entries;
};

struct Diary my_diary;

void add_entry() {
    if (my_diary.num_entries >= MAX_ENTRIES) {
        printf("Diary is full!");
        return;
    }

    printf("Title: ");
    fgets(my_diary.entries[my_diary.num_entries].title, 100, stdin);
    strtok(my_diary.entries[my_diary.num_entries].title, "\n");

    printf("Content: ");
    fgets(my_diary.entries[my_diary.num_entries].content, 1000, stdin);
    strtok(my_diary.entries[my_diary.num_entries].content, "\n");

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(my_diary.entries[my_diary.num_entries].timestamp, sizeof(my_diary.entries[my_diary.num_entries].timestamp), "%d-%m-%Y %H:%M:%S", tm);

    printf("Entry added successfully!\n");

    my_diary.num_entries++;
}

void list_entries() {
    if (my_diary.num_entries == 0) {
        printf("Diary is empty!");
        return;
    }

    for (int i=0; i < my_diary.num_entries; i++) {
        printf("%s\n%s\n%s\n\n", my_diary.entries[i].timestamp, my_diary.entries[i].title, my_diary.entries[i].content);
    }
}

void clear_diary() {
    memset(&my_diary, 0, sizeof(my_diary));
    printf("Diary cleared!\n");
}

void print_menu() {
    printf("\nMenu:\n");
    printf("1. Add Entry\n");
    printf("2. List Entries\n");
    printf("3. Clear Diary\n");
    printf("4. Exit\n");
    printf("\n");
}

int main() {
    int choice;

    while (true) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add_entry();
                break;
            case 2:
                list_entries();
                break;
            case 3:
                clear_diary();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}