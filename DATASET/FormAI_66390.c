//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 100
#define MAX_ROWS 1000
#define MAX_FIELD_SIZE 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    FILE *csv_file = fopen(filename, "r");
    if (csv_file == NULL) {
        fprintf(stderr, "Error: Unable to open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_COLS * MAX_FIELD_SIZE];
    char *fields[MAX_COLS];
    char *field;
    int rows = 0;
    int cols = 0;

    while (fgets(line, sizeof(line), csv_file) != NULL) {
        if (rows >= MAX_ROWS) {
            fprintf(stderr, "Error: Maximum number of rows exceeded\n");
            exit(EXIT_FAILURE);
        }
        cols = 0;
        field = strtok(line, ",");
        while (field) {
            if (cols >= MAX_COLS) {
                fprintf(stderr, "Error: Maximum number of columns exceeded\n");
                exit(EXIT_FAILURE);
            }
            if (strlen(field) >= MAX_FIELD_SIZE) {
                fprintf(stderr, "Error: Maximum field size exceeded\n");
                exit(EXIT_FAILURE);
            }
            fields[cols++] = strdup(field);
            field = strtok(NULL, ",");
        }
        rows++;
    }

    fclose(csv_file);

    printf("Read %d rows and %d columns from file '%s':\n", rows, cols, filename);
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            printf("%s ", fields[(row * cols) + col]);
        }
        printf("\n");
    }

    for (int i = 0; i < cols; i++) {
        free(fields[i]);
    }

    exit(EXIT_SUCCESS);
}