//FormAI DATASET v1.0 Category: Data mining ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

int main() {
    FILE *fp;
    int rows = 0, cols = 0, size = 0;
    int data[MAX_ROWS][MAX_COLS];
    double means[MAX_COLS];
    char buffer[1024], *token;

    /* open data file */
    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("error opening file");
        exit(1);
    }

    /* read data */
    while (fgets(buffer, 1024, fp) != NULL) {
        token = strtok(buffer, ",");
        cols = 0;
        while (token != NULL) {
            data[rows][cols++] = atoi(token);
            token = strtok(NULL, ",");
        }
        rows++;
    }
    fclose(fp);

    /* calculate means */
    for (int i = 0; i < cols; i++) {
        size = 0;
        for (int j = 0; j < rows; j++) {
            size++;
            means[i] += data[j][i];
        }
        means[i] /= size;
    }

    /* print means */
    printf("Column Means:\n");
    for (int i = 0; i < cols; i++) {
        printf("%lf ", means[i]);
    }
    printf("\n");

    return 0;
}