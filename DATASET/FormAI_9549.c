//FormAI DATASET v1.0 Category: Digital Diary ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct Entry {
    char date[12];
    char time[10];
    char note[1000];
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry() {
    // Get date and time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(entries[num_entries].date, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    sprintf(entries[num_entries].time, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);

    // Get note from user
    printf("Enter your note (max 1000 characters):\n");
    fgets(entries[num_entries].note, sizeof(entries[num_entries].note), stdin);
    entries[num_entries].note[strcspn(entries[num_entries].note, "\n")] = 0; // Remove trailing newline if any

    num_entries++;
    printf("Entry added!\n");
}

void view_entries() {
    if (num_entries == 0) {
        printf("No entries found\n");
        return;
    }
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s:\n%s\n", entries[i].date, entries[i].time, entries[i].note);
    }
}

int main() {
    printf("Welcome to your digital diary!\n\n");
    while (1) {
        printf("\nChoose an option:\n1. Add an entry\n2. View entries\n3. Exit\n");
        char choice[10];
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = 0; // Remove trailing newline if any

        if (strcmp(choice, "1") == 0) {
            if (num_entries == MAX_ENTRIES) {
                printf("No more space for entries\n");
                continue;
            }
            add_entry();
        } else if (strcmp(choice, "2") == 0) {
            view_entries();
        } else if (strcmp(choice, "3") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}