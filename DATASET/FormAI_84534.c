//FormAI DATASET v1.0 Category: Data mining ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

void read_csv(char *filename, float data[][MAX_COLS], int *nrows, int *ncols) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Could not open file.\n");
        exit(1);
    }

    int row = 0, col = 0;
    char buffer[1024];
    char *field;

    while(fgets(buffer, 1024, fp)) {
        field = strtok(buffer, ",");
        col = 0;

        while (field) {
            data[row][col++] = atof(field);
            field = strtok(NULL, ",");
        }

        row++;
    }

    *nrows = row;
    *ncols = col;

    fclose(fp);
}

void print_data(float data[][MAX_COLS], int nrows, int ncols) {
    int i, j;

    for (i = 0; i < nrows; i++) {
        for (j = 0; j < ncols; j++) {
            printf("%f ", data[i][j]);
        }

        printf("\n");
    }
}

int main() {
    float data[MAX_ROWS][MAX_COLS];
    int nrows, ncols;

    read_csv("data.csv", data, &nrows, &ncols);
    print_data(data, nrows, ncols);

    return 0;
}