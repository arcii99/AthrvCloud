//FormAI DATASET v1.0 Category: Digital Diary ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char date[11];
    char entry[100];
} diary_entry;

diary_entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char date[11];
    strftime(date, sizeof(date), "%m/%d/%Y", tm);
    printf("Enter your diary entry:\n");
    fgets(entries[num_entries].entry, sizeof(entries[num_entries].entry), stdin);
    strncpy(entries[num_entries].date, date, sizeof(entries[num_entries].date));
    num_entries++;
}

void display_entries() {
    if (num_entries == 0) {
        printf("No entries to display.\n");
        return;
    }
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %s", entries[i].date, entries[i].entry);
    }
}

int main() {
    printf("Welcome to your Digital Diary!\n");
    while (1) {
        printf("What would you like to do? (add/display/quit)\n");
        char input[10];
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "add\n") == 0) {
            add_entry();
        } else if (strcmp(input, "display\n") == 0) {
            display_entries();
        } else if (strcmp(input, "quit\n") == 0) {
            printf("Goodbye!\n");
            return 0;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
}