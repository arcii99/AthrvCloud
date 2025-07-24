//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 128
#define MAX_FIELDS 16

int parse_line(char *line, char *fields[], int max_fields) {
    int field_count = 0;
    char *field = strtok(line, ",");
    while (field && field_count < max_fields) {
        fields[field_count++] = field;
        field = strtok(NULL, ",");
    }
    return field_count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s file.csv\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char *fields[MAX_FIELDS];
    int line_count = 0;
    int field_count = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        line_count++;
        field_count = parse_line(line, fields, MAX_FIELDS);
        if (field_count == 0) {
            printf("Warning: empty line found at line %d\n", line_count);
        } else {
            printf("Line %d: %d fields found\n", line_count, field_count);
            for (int i = 0; i < field_count; i++) {
                printf("Field %d: %s\n", i + 1, fields[i]);
            }
        }
    }

    fclose(file);
    return 0;
}