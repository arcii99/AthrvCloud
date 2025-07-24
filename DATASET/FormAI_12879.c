//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_LEN 500

void parse_csv(char* buffer, char* rows[MAX_ROWS][MAX_COLS], int* num_rows, int* num_cols) {
    char* row;
    char* col;

    *num_rows = 0;
    *num_cols = 0;

    row = strtok(buffer, "\r\n");
    while (row != NULL && *num_rows < MAX_ROWS) {
        col = strtok(row, ",");
        while (col != NULL && *num_cols < MAX_COLS) {
            rows[*num_rows][*num_cols] = col;
            (*num_cols)++;
            col = strtok(NULL, ",");
        }
        (*num_rows)++;
        row = strtok(NULL, "\r\n");
    }
}

int main(int argc, char** argv) {
    char buffer[MAX_LEN];
    char* rows[MAX_ROWS][MAX_COLS];
    int num_rows, num_cols;

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fread(buffer, sizeof(char), MAX_LEN, file);
    fclose(file);

    parse_csv(buffer, rows, &num_rows, &num_cols);

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%s\t", rows[i][j]);
        }
        printf("\n");
    }

    return 0;
}