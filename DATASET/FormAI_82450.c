//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CSV_ROW_LEN 1024
#define MAX_CSV_COL_NUM 10

typedef struct {
    char **cols;
    int num_cols;
} csv_row_t;

typedef struct {
    csv_row_t *rows;
    int num_rows;
} csv_t;

int read_csv(const char *filename, csv_t *csv) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Failed to open csv file.\n");
        return -1;
    }

    char buf[MAX_CSV_ROW_LEN];
    int row_count = 0;
    int col_count = 0;
    while (fgets(buf, MAX_CSV_ROW_LEN, fp)) {
        // Ignore line breaks
        if (buf[strlen(buf) - 1] == '\n'){
            buf[strlen(buf) - 1] = '\0';
        }
        if (buf[strlen(buf) - 1] == '\r'){
            buf[strlen(buf) - 1] = '\0';
        }
        if (strlen(buf) == 0) {
            continue;
        }

        // Tokenize row
        char *token = strtok(buf, ",");
        char **cols = (char **) malloc(sizeof(char *) * MAX_CSV_COL_NUM);
        int col_count = 0;
        while (token != NULL && col_count < MAX_CSV_COL_NUM) {
            cols[col_count++] = strdup(token);
            token = strtok(NULL, ",");
        }

        // Build csv row
        csv_row_t row = {cols, col_count};
        csv->rows[row_count++] = row;

        // Check max number of rows
        if (row_count >= MAX_CSV_ROW_LEN) {
            break;
        }
    }

    csv->num_rows = row_count;
    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return -1;
    }

    // Build CSV
    csv_t csv = {{NULL, 0}, 0};
    csv.rows = (csv_row_t *) malloc(sizeof(csv_row_t) * MAX_CSV_ROW_LEN);
    if (read_csv(argv[1], &csv) != 0) {
        return -1;
    }

    // Print CSV
    int i, j;
    for (i = 0; i < csv.num_rows; i++) {
        printf("Row %d: ", i);
        csv_row_t row = csv.rows[i];
        for (j = 0; j < row.num_cols; j++) {
            printf("%s, ", row.cols[j]);
        }
        printf("\n");
    }

    // Free memory
    for (i = 0; i < csv.num_rows; i++) {
        csv_row_t row = csv.rows[i];
        for (j = 0; j < row.num_cols; j++) {
            free(row.cols[j]);
        }
        free(row.cols);
    }
    free(csv.rows);

    return 0;
}