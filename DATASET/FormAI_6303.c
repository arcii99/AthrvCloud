//FormAI DATASET v1.0 Category: Digital Diary ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENTRIES 100
#define ENTRY_LENGTH 500

struct Entry {
    time_t timestamp;
    char text[ENTRY_LENGTH];
};

int main() {
    FILE *file;
    struct Entry entries[MAX_ENTRIES];

    int num_entries = 0;

    // Open the file for reading or create it if it doesn't exist
    file = fopen("digital_diary.txt", "a+");

    if (file == NULL) {
        printf("Error: Unable to open file\n");
        return 1;
    }

    // Read all the entries from the file
    while (num_entries < MAX_ENTRIES && fgets(entries[num_entries].text, ENTRY_LENGTH, file) != NULL) {
        // Remove trailing newline character
        entries[num_entries].text[strcspn(entries[num_entries].text, "\n")] = '\0';
        num_entries++;
    }

    printf("Welcome to your digital diary!\n");

    char choice;
    do {
        printf("Enter 'a' to add an entry or 'q' to quit: ");
        scanf(" %c", &choice);

        if (choice == 'a') {
            // Add a new entry
            printf("Enter your entry (maximum %d characters): ", ENTRY_LENGTH);
            scanf(" %[^\n]s", entries[num_entries].text);
            entries[num_entries].timestamp = time(NULL);
            num_entries++;

            // Write all entries to the file
            fclose(file);
            file = fopen("digital_diary.txt", "w");

            if (file == NULL) {
                printf("Error: Unable to open file\n");
                return 1;
            }

            for (int i = 0; i < num_entries; i++) {
                fprintf(file, "%ld|%s\n", (long) entries[i].timestamp, entries[i].text);
            }

            fclose(file);
        }
    } while (choice != 'q');

    printf("Goodbye!\n");

    return 0;
}