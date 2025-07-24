//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FIELDS 20
#define DELIMITER ","

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <csv_file_path>\n", argv[0]);
        return 1;
    }

    char *file_path = argv[1];
    FILE *file = fopen(file_path, "r");

    if (!file) {
        printf("Error: Cannot open file %s\n", file_path);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char *fields[MAX_FIELDS];

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        int field_count = 0;
        char *token = strtok(line, DELIMITER);

        while (token != NULL && field_count < MAX_FIELDS) {
            fields[field_count] = token;
            field_count++;
            token = strtok(NULL, DELIMITER);
        }

        for (int i = 0; i < field_count; i++) {
            printf("%s\t", fields[i]);
        }

        printf("\n");
    }

    fclose(file);
    return 0;
}