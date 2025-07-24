//FormAI DATASET v1.0 Category: Log analysis ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_LINE_LENGTH 1000

struct Entry {
    char* text;
    int count;
};

int count_entries(FILE* file, struct Entry entries[]) {
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        // Trim newline character from the end of the line
        line[strcspn(line, "\n")] = 0;

        int i;
        for (i = 0; i < MAX_ENTRIES && entries[i].text != NULL; i++) {
            if (strcmp(line, entries[i].text) == 0) {
                entries[i].count++;
                break;
            }
        }

        if (entries[i].text == NULL) {
            entries[i].text = strdup(line);
            entries[i].count = 1;
        }
    }

    return MAX_ENTRIES;
}

void print_max_entries(struct Entry entries[], int length) {
    int max_count = 0;
    int i;

    for (i = 0; i < length; i++) {
        if (entries[i].text == NULL) {
            break;
        }

        if (entries[i].count > max_count) {
            max_count = entries[i].count;
        }
    }

    printf("Most common entries:\n");

    for (i = 0; i < length; i++) {
        if (entries[i].text == NULL) {
            break;
        }

        if (entries[i].count == max_count) {
            printf("%s (%d occurrences)\n", entries[i].text, entries[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s FILENAME\n", argv[0]);
        exit(1);
    }

    FILE* file;

    if ((file = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        exit(1);
    }

    struct Entry entries[MAX_ENTRIES] = {0};

    count_entries(file, entries);
    print_max_entries(entries, MAX_ENTRIES);

    fclose(file);

    return 0;
}