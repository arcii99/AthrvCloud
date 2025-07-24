//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10

typedef struct {
    char data[MAX_ROWS][MAX_COLS][50];
    int row_count;
    int col_count;
} CSV;

CSV read_csv_file(char* filename) {
    CSV csv_data;
    csv_data.row_count = 0;
    csv_data.col_count = 0;

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[1000];
    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\r\n")] = 0;
        char* token = strtok(line, ",");
        int col_count = 0;

        while (token != NULL) {
            strcpy(csv_data.data[csv_data.row_count][col_count], token);
            col_count++;
            token = strtok(NULL, ",");
        }

        if (csv_data.col_count == 0) {
            csv_data.col_count = col_count;
        } else if (csv_data.col_count != col_count) {
            printf("Error: invalid CSV format in file %s\n", filename);
            exit(1);
        }

        csv_data.row_count++;
    }

    fclose(fp);

    return csv_data;
}

int main() {
    CSV csv_data = read_csv_file("example.csv");

    printf("Number of rows: %d\n", csv_data.row_count);
    printf("Number of columns: %d\n", csv_data.col_count);

    for (int i = 0; i < csv_data.row_count; i++) {
        for (int j = 0; j < csv_data.col_count; j++) {
            printf("%s ", csv_data.data[i][j]);
        }
        printf("\n");
    }

    return 0;
}