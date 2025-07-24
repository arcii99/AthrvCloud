//FormAI DATASET v1.0 Category: Digital Diary ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

struct diary_entry {
    char date[20];
    char content[1000];
};

struct diary {
    int entry_count;
    struct diary_entry entries[MAX_ENTRIES];
};

void create_entry(struct diary *d) {
    char date[20];
    time_t now = time(NULL);
    strftime(date, 20, "%d/%m/%Y - %H:%M:%S", localtime(&now));
    printf("\nEnter your thoughts:\n");
    fgets(d->entries[d->entry_count].content, 1000, stdin);
    strcpy(d->entries[d->entry_count].date, date);
    printf("\nEntry saved!\n");
    d->entry_count++;
}

void view_entries(struct diary d) {
    if (d.entry_count == 0) {
        printf("\nNo entries yet!\n");
        return;
    }
    printf("\n");
    for (int i = 0; i < d.entry_count; i++) {
        printf("%d.\n", i+1);
        printf("Date: %s\n", d.entries[i].date);
        printf("Entry: %s\n", d.entries[i].content);
        printf("--------------------\n");
    }
}

int main() {
    struct diary d;
    d.entry_count = 0;
    int choice = 0;
    do {
        printf("\nEnter your choice:\n");
        printf("1. Add entry\n");
        printf("2. View entries\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                create_entry(&d);
                break;
            case 2:
                view_entries(d);
                break;
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nPlease enter a valid choice!\n");
                break;
        }
    } while (choice != 3);
    return 0;
}