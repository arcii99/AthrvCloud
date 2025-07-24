//FormAI DATASET v1.0 Category: Digital Diary ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRY_SIZE 256
#define MAX_ENTRIES 10

typedef struct Entry {
    time_t timestamp;
    char entry[MAX_ENTRY_SIZE];
} Entry;

int main() {
    Entry diary[MAX_ENTRIES];
    int num_entries = 0;

    while (1) {
        printf("Enter a new diary entry:\n");

        Entry new_entry;
        time(&new_entry.timestamp);
        fgets(new_entry.entry, MAX_ENTRY_SIZE, stdin);

        // Remove trailing newline character from fgets input
        int i = 0;
        while (new_entry.entry[i] != '\0') {
            if (new_entry.entry[i] == '\n') {
                new_entry.entry[i] = '\0';
                break;
            }
            i++;
        }

        diary[num_entries] = new_entry;
        num_entries++;

        if (num_entries >= MAX_ENTRIES) {
            printf("Diary is full. No more entries can be added.\n");
            break;
        }

        char user_input[32];
        printf("Enter 'q' to quit. Press any other key to add another entry.\n");
        fgets(user_input, sizeof(user_input), stdin);

        if (user_input[0] == 'q') {
            break;
        }
    }

    printf("\n\n=================================\n");
    printf("         My Digital Diary\n");
    printf("=================================\n\n");

    for (int i = 0; i < num_entries; i++) {
        printf("Entry %d:\n", i+1);
        printf("Date: %s", asctime(localtime(&diary[i].timestamp)));
        printf("%s\n\n", diary[i].entry);
    }

    return 0;
}