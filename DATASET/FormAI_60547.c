//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 10

int main() {
    FILE* file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char fields[MAX_FIELDS][MAX_FIELD_LENGTH];
    int num_fields;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        num_fields = 0;

        char* field = strtok(line, ",");
        while (field != NULL && num_fields < MAX_FIELDS) {
            strncpy(fields[num_fields], field, MAX_FIELD_LENGTH);
            num_fields++;
            field = strtok(NULL, ",");
        }

        printf("Found %d fields:\n", num_fields);
        for (int i = 0; i < num_fields; i++) {
            printf("Field %d: \"%s\"\n", i, fields[i]);
        }
    }

    fclose(file);
    return 0;
}