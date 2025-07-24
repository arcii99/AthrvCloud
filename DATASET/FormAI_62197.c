//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_FIELD 100

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return EXIT_FAILURE;
    }

    char line[MAX_LINE];
    char field[MAX_FIELD];
    int field_count = 0;
    int line_count = 0;

    while (fgets(line, MAX_LINE, fp)) {
        // remove newline character
        line[strcspn(line, "\r\n")] = 0;
        
        int i = 0;
        int j = 0;
        field_count = 0;

        while (i < strlen(line)) {
            j = 0;
            memset(field, 0, MAX_FIELD);

            while (line[i] != ',' && i < strlen(line)) {
                field[j] = line[i];
                i++;
                j++;
            }

            field_count++;
            i++;

            printf("Field %d: %s\n", field_count, field);
        }

        line_count++;

        printf("Line %d: %s\n", line_count, line);
        printf("Field count: %d\n", field_count);
        printf("-------------------\n");
    }

    fclose(fp);

    return EXIT_SUCCESS;
}