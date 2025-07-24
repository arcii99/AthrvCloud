//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Surprise! Let's build a CSV Reader!\n");

    FILE *file;
    file = fopen("data.csv", "r");

    if (file == NULL) {
        printf("Oops, we couldn't find the CSV file. Check the file path and try again.\n");
        exit(1);
    }

    printf("CSV file found. Let's start reading...\n");

    char line[100];
    int row_count = 0;
    int field_count = 0;

    while (fgets(line, 100, file)) {
        row_count++;

        if (row_count == 1) {
            printf("Reading header...\n");
            continue;
        }

        printf("Reading data row %d...\n", row_count - 1);

        char *field = strtok(line, ",");

        while (field) {
            field_count++;
            printf("Field %d: %s\n", field_count, field);
            field = strtok(NULL, ",");
        }
    }

    printf("CSV file successfully read, with a total of %d rows and %d fields.\n", row_count - 1, field_count);

    fclose(file);

    return 0;
}