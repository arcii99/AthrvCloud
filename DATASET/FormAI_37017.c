//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 10

/**
 * Struct to hold a CSV line's data.
 */
typedef struct CSVRow {
    char columns[MAX_COLUMNS][MAX_LINE_SIZE];
} CSVRow;

/**
 * Parse a CSV line into a CSVRow struct.
 * @param row CSVRow to fill with data.
 * @param line Line to parse.
 * @return 0 on success, -1 on failure.
 */
int parse_csv_line(CSVRow* row, char* line) {
    char* token = strtok(line, ",");
    int i = 0;
    while (token != NULL && i < MAX_COLUMNS) {
        strcpy(row->columns[i], token);
        token = strtok(NULL, ",");
        i++;
    }
    if (i != MAX_COLUMNS) {
        return -1;
    }
    return 0;
}

/**
 * Read a CSV file and print its contents.
 * @param filename Filename of CSV file to read.
 * @return 0 on success, -1 on failure.
 */
int read_csv_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    char line[MAX_LINE_SIZE];
    CSVRow row;
    while (fgets(line, MAX_LINE_SIZE, file)) {
        if (parse_csv_line(&row, line) == 0) {
            for (int i = 0; i < MAX_COLUMNS; i++) {
                printf("%s ", row.columns[i]);
            }
            printf("\n");
        }
    }

    fclose(file);
    return 0;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return -1;
    }

    if (read_csv_file(argv[1]) == -1) {
        printf("Failed to read CSV file.\n");
        return -1;
    }

    return 0;
}