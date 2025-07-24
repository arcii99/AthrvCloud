//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 50
#define MAX_COLS 10
#define MAX_LINE_LEN 1024

/* Data structure to store CSV data */
typedef struct {
    int nrows;
    int ncols;
    char data[MAX_ROWS][MAX_COLS][MAX_LINE_LEN];
} CsvData;

/* Loads CSV data from file */
int load_csv(const char *filename, CsvData *csv)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Failed to open file %s\n", filename);
        return -1;
    }

    char buf[MAX_LINE_LEN];
    int nrow = 0;
    int ncols = 0;

    while (fgets(buf, MAX_LINE_LEN, fp) != NULL) {
        if (nrow == 0) {
            /* This is the header row */
            char *tok = strtok(buf, ",");
            while (tok != NULL && ncols < MAX_COLS) {
                strcpy(csv->data[nrow][ncols], tok);
                tok = strtok(NULL, ",");
                ncols++;
            }
            csv->nrows = 0;
            csv->ncols = ncols;
        } else {
            /* This is a data row */
            char *tok = strtok(buf, ",");
            int idx = 0;
            while (tok != NULL && idx < ncols) {
                strcpy(csv->data[nrow][idx], tok);
                tok = strtok(NULL, ",");
                idx++;
            }
            nrow++;
        }
    }

    csv->nrows = nrow;

    fclose(fp);

    return 0;
}

/* Prints CSV data */
void print_csv(CsvData *csv)
{
    int nrows = csv->nrows;
    int ncols = csv->ncols;

    printf("CSV Data:\n");

    /* Print header row */
    for (int i = 0; i < ncols; i++) {
        printf("%s", csv->data[0][i]);
        if (i < ncols - 1) {
            printf(",");
        }
    }
    printf("\n");

    /* Print data rows */
    for (int i = 1; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            printf("%s", csv->data[i][j]);
            if (j < ncols - 1) {
                printf(",");
            }
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    CsvData csv;

    if (argc != 2) {
        printf("Usage: csv_reader <filename>\n");
        return -1;
    }

    if (load_csv(argv[1], &csv) != 0) {
        return -1;
    }

    print_csv(&csv);

    return 0;
}