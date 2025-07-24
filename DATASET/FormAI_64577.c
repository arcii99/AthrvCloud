//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: csvreader file.csv\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        printf("Failed to open file '%s'\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // Parse CSV line into fields
        char* field = strtok(line, ",");
        while (field) {
            // Do something with the field
            printf("%s\n", field);

            field = strtok(NULL, ",");
        }
    }

    fclose(file);
    return 0;
}