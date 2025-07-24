//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10
#define MAX_LINE_LENGTH 200

/* Struct to hold data from CSV file */
typedef struct {
    int rows;
    int cols;
    char data[MAX_ROWS][MAX_COLS][MAX_LINE_LENGTH];
} CSVFile;

/* Function to read CSV file and store data in struct */
int read_csv(const char* filename, CSVFile* csv) {

    FILE* fp = fopen(filename, "r");

    if (!fp) {
        printf("Failed to open file %s\n", filename);
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    int row = 0;
    int col = 0;
    int in_quote = 0;

    /* Read CSV file line by line and store data in struct */
    while (fgets(line, sizeof(line), fp) != NULL && row < MAX_ROWS) {

        col = 0;
        in_quote = 0;
        int line_length = strlen(line);

        for (int i = 0; i < line_length && col < MAX_COLS; i++) {

            /* Handle quotes for values with commas */
            if (line[i] == '\"') {
                in_quote = !in_quote;
            }
            else if (line[i] == ',' && !in_quote) {
                csv->data[row][col++][0] = '\0';
            }
            else {
                strncat(csv->data[row][col], &line[i], 1);
            }
        }

        /* Add final value of line */
        csv->data[row][col][0] = '\0';
        row++;
    }

    csv->rows = row;
    csv->cols = col;

    fclose(fp);

    return 1;
}

/* Example usage */
int main() {

    CSVFile csv;

    /* Read CSV file and store data in struct */
    if (!read_csv("example.csv", &csv)) {
        return 1;
    }

    /* Print data stored in struct */
    for (int i = 0; i < csv.rows; i++) {
        for (int j = 0; j < csv.cols; j++) {
            printf("%s\t", csv.data[i][j]);
        }
        printf("\n");
    }

    return 0;
}