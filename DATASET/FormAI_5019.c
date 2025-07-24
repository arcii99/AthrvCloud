//FormAI DATASET v1.0 Category: Digital Diary ; Style: scientific
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 100

struct DiaryEntry {
    int year;
    int month;
    int day;
    char body[1000];
};

struct Diary {
    int num_entries;
    struct DiaryEntry entries[MAX_ENTRIES];
};

void addEntry(struct Diary *diary, struct DiaryEntry entry) {
    if (diary->num_entries < MAX_ENTRIES) {
        diary->entries[diary->num_entries] = entry;
        diary->num_entries++;
    }
}

void printEntry(struct DiaryEntry entry) {
    printf("%d-%02d-%02d\n", entry.year, entry.month, entry.day);
    printf("%s\n", entry.body);
    printf("\n");
}

void printDiary(struct Diary diary) {
    for (int i = 0; i < diary.num_entries; i++) {
        printEntry(diary.entries[i]);
    }
}

int main() {

    struct Diary diary = {0};
    struct DiaryEntry entry;

    printf("Welcome to your digital diary!\n\n");

    char input[10];

    do {
        printf("Enter 'a' to add an entry, 'p' to print your diary, or 'q' to quit: ");
        fgets(input, 10, stdin);

        if (strcmp(input, "a\n") == 0) {
            printf("Enter the date in format \"yyyy-mm-dd\": ");
            scanf("%d-%d-%d", &entry.year, &entry.month, &entry.day);
            printf("Enter your entry:\n");
            fgets(entry.body, 1000, stdin); // consume the newline character left in the input buffer
            fgets(entry.body, 1000, stdin);
            addEntry(&diary, entry);
            printf("Entry added!\n\n");
        } else if (strcmp(input, "p\n") == 0) {
            printf("\nYour diary entries:\n\n");
            printDiary(diary);
        }

    } while (strcmp(input, "q\n") != 0);

    printf("\nGoodbye, thank you for using your digital diary!");

    return 0;
}