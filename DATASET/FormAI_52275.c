//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10

typedef struct csv_data {
    char columns[MAX_COLS][50];
    char data[MAX_ROWS][MAX_COLS][50];
    int num_rows;
    int num_cols;
} CSVData;

void parse_csv(char *filename, CSVData *csv) {
    FILE *fptr;
    char buffer[1024];
    int row = 0;
    int col = 0;

    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Could not open file %s\n", filename);
        exit(1);
    }

    fgets(buffer, 1024, fptr);
    char *token = strtok(buffer, ",");
    while (token != NULL) {
        strncpy(csv->columns[col], token, 50);
        col++;
        token = strtok(NULL, ",");
    }
    csv->num_cols = col;

    while (fgets(buffer, 1024, fptr)) {
        col = 0;
        token = strtok(buffer, ",");
        while (token != NULL) {
            strncpy(csv->data[row][col], token, 50);
            col++;
            token = strtok(NULL, ",");
        }
        row++;
        if (row >= MAX_ROWS) {
            printf("Exceeded maximum number of rows\n");
            break;
        }
    }
    csv->num_rows = row;

    fclose(fptr);
}

void print_csv(CSVData *csv) {
    int i, j;

    for (i = 0; i < csv->num_cols; i++) {
        printf("%s\t", csv->columns[i]);
    }
    printf("\n");

    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_cols; j++) {
            printf("%s\t", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    CSVData csv;
    char filename[] = "example.csv";

    parse_csv(filename, &csv);
    print_csv(&csv);

    return 0;
}