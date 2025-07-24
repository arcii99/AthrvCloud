//FormAI DATASET v1.0 Category: Data mining ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_COLUMNS 10
#define MAX_ROW_COUNT 100

int main() {
    int num_columns, num_rows;
    char* column_names[MAX_COLUMNS];
    char* data[MAX_COLUMNS][MAX_ROW_COUNT];
    char line[MAX_LINE_LENGTH];
    char *token, *delim;

    // Read first row for column names
    fgets(line, MAX_LINE_LENGTH, stdin);
    delim = ",";
    token = strtok(line, delim);
    num_columns = 0;
    while (token != NULL) {
        column_names[num_columns++] = strdup(token);
        token = strtok(NULL, delim);
    }

    // Read remaining rows for data
    num_rows = 0;
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        token = strtok(line, delim);
        int col_num = 0;
        while (token != NULL) {
            data[col_num++][num_rows] = strdup(token);
            token = strtok(NULL, delim);
        }
        num_rows++;
    }

    // Print out column names
    printf("Column names: ");
    for (int i = 0; i < num_columns; i++) {
        printf("%s, ", column_names[i]);
    }
    printf("\n");

    // Print out data
    printf("Data:\n");
    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < num_columns; col++) {
            printf("%s, ", data[col][row]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < num_columns; i++) {
        free(column_names[i]);
        for (int j = 0; j < num_rows; j++) {
            free(data[i][j]);
        }
    }

    return 0;
}