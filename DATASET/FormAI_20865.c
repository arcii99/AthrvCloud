//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CSV_COLUMNS 50
#define MAX_CSV_LINE_LENGTH 512

int main(int argc, char *argv[]) {
    char *csv_filename = argv[1];
    int num_columns = 0;
    char column_names[MAX_CSV_COLUMNS][MAX_CSV_LINE_LENGTH];
    char line[MAX_CSV_LINE_LENGTH];

    FILE *csv_file = fopen(csv_filename, "r");
    if (csv_file == NULL) {
        printf("Error: Could not open file %s.\n", csv_filename);
        return 1;
    }

    // Read the first line and get the column names
    if (fgets(line, MAX_CSV_LINE_LENGTH, csv_file) != NULL) {
        char *column_name = strtok(line, ",");
        while (column_name != NULL) {
            strcpy(column_names[num_columns], column_name);
            column_name = strtok(NULL, ",");
            num_columns++;
        }
    }

    // Read the rest of the lines and print the data
    while (fgets(line, MAX_CSV_LINE_LENGTH, csv_file) != NULL) {
        char *column_value = strtok(line, ",");
        printf("-------\n");
        for (int i = 0; i < num_columns; i++) {
            printf("%s: %s\n", column_names[i], column_value);
            column_value = strtok(NULL, ",");
        }
    }

    fclose(csv_file);
    return 0;
}