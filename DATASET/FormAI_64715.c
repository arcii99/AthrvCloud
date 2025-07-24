//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 1000     // Maximum number of columns in each row
#define MAX_ROWS 1000000  // Maximum number of rows in CSV file

// Struct to store CSV data
typedef struct {
    int num_cols;
    int num_rows;
    char *data[MAX_ROWS][MAX_COLS];
} csv_data;

// Function to read CSV file and return csv_data struct
csv_data read_csv(char *filename) {

    csv_data csv;
    csv.num_cols = 0;
    csv.num_rows = 0;
    FILE *file = fopen(filename, "r");

    if (file != NULL) {
        char line[1024];
        char *token;

        while (fgets(line, 1024, file) != NULL) {
            int col_count = 0;
            token = strtok(line, ",");
            while (token != NULL) {
                csv.data[csv.num_rows][col_count] = strdup(token);
                col_count++;
                token = strtok(NULL, ",");
            }

            // Update the number of columns if this row has more than previous rows
            if (col_count > csv.num_cols) {
                csv.num_cols = col_count;
            }

            csv.num_rows++;
        }
        fclose(file);
    }

    return csv;
}

// Function to print CSV data
void print_csv(csv_data csv) {
    for (int row = 0; row < csv.num_rows; row++) {
        for (int col = 0; col < csv.num_cols; col++) {
            printf("%s,", csv.data[row][col]);
        }
        printf("\n");
    }
}

int main() {

    char *filename = "example.csv";
    csv_data csv = read_csv(filename);
    if (csv.num_rows > 0) {
        printf("CSV data in file '%s':\n", filename);
        print_csv(csv);
    } else {
        printf("No data found in file '%s'\n", filename);
    }

    return 0;
}