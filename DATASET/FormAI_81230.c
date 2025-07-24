//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

int main() {

    char csv_file[] = "data.csv";
    char line[MAX_COLS];
    char *field;

    int row = 0, col = 0;
    char csv_data[MAX_ROWS][MAX_COLS];

    FILE *fp = fopen(csv_file, "r");

    // check if file opened successfully
    if (fp == NULL) {
        printf("Error opening file %s.\n", csv_file);
        return 1;
    }

    // read each line of the CSV file
    while (fgets(line, MAX_COLS, fp)) {

        col = 0;
        field = strtok(line, ",");
        while (field != NULL) {
            // store field in 2D array
            csv_data[row][col] = *field;
            col++;
            field = strtok(NULL, ",");
        }
        row++;
    }

    // print out contents of CSV file
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c ", csv_data[i][j]);
        }
        printf("\n");
    }

    fclose(fp);

    return 0;
}