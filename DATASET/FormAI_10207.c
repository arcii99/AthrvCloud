//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 50
#define MAX_ROW_LENGTH 1024

typedef struct {
    char row[MAX_ROW_LENGTH];
    char **columns;
} CSVRow;

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: csv_reader <filename>\n");
        return 1;
    }

    FILE *csv_file = fopen(argv[1], "r");
    if (!csv_file) {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    // Read header row and determine number of columns
    char header_row[MAX_ROW_LENGTH];
    fgets(header_row, MAX_ROW_LENGTH, csv_file);
    int num_columns = 0;
    char *token = strtok(header_row, ",");
    while (token) {
        num_columns++;
        token = strtok(NULL, ",");
    }
    rewind(csv_file);

    // Allocate memory for CSVRow array (one for each row in the CSV file)
    CSVRow *rows = (CSVRow *) malloc(sizeof(CSVRow));
    int num_rows = 0;

    // Parse CSV file line by line
    char row[MAX_ROW_LENGTH];
    while (fgets(row, MAX_ROW_LENGTH, csv_file)) {
        // Allocate memory for columns array
        char **columns = (char **) malloc(sizeof(char *) * MAX_COLUMNS);
        int num_columns_found = 0;
        char *column = strtok(row, ",");
        while (column) {
            char *column_copy = (char *) malloc(strlen(column) + 1);
            strcpy(column_copy, column);
            columns[num_columns_found++] = column_copy;
            column = strtok(NULL, ",");
        }

        // Check if number of columns found matches header row
        if (num_columns_found != num_columns) {
            printf("Error: row has %d columns but header row has %d columns\n", num_columns_found, num_columns);
            return 1;
        }

        // Add row to CSVRow array
        CSVRow current_row = { .row = row, .columns = columns };
        rows = (CSVRow *) realloc(rows, sizeof(CSVRow) * ++num_rows);
        rows[num_rows - 1] = current_row;
    }

    // Print out data for each row
    printf("Data:\n");
    for (int i = 0; i < num_rows; i++) {
        printf("Row %d:\n", i + 1);
        for (int j = 0; j < num_columns; j++) {
            printf("%s: %s\n", rows[i].columns[j], rows[i].row);
        }
    }

    // Free memory allocated for CSVRow array
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            free(rows[i].columns[j]);
        }
        free(rows[i].columns);
    }
    free(rows);

    // Close file
    fclose(csv_file);

    return 0;
}