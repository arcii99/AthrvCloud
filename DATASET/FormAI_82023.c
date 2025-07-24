//FormAI DATASET v1.0 Category: Data mining ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COLS 100
#define MAX_ROWS 1000

void read_file(const char* filename, double data[MAX_ROWS][MAX_COLS], int* rows, int* cols);
void compute_stats(const double data[MAX_ROWS][MAX_COLS], int rows, int cols, double means[MAX_COLS], double stddevs[MAX_COLS]);
void print_stats(const double means[MAX_COLS], const double stddevs[MAX_COLS], int cols);

int main(int argc, char* argv[]) {
    // parse command-line arguments
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    const char* filename = argv[1];

    // read the data from the file
    double data[MAX_ROWS][MAX_COLS];
    int rows, cols;
    read_file(filename, data, &rows, &cols);

    // compute the mean and standard deviation of each column
    double means[MAX_COLS], stddevs[MAX_COLS];
    compute_stats(data, rows, cols, means, stddevs);

    // print the results
    print_stats(means, stddevs, cols);

    return 0;
}

/**
 * Reads a CSV file into a matrix of doubles.
 * Assumes the file has at most MAX_ROWS rows and MAX_COLS columns.
 * Sets the 'rows' and 'cols' output parameters accordingly.
 */
void read_file(const char* filename, double data[MAX_ROWS][MAX_COLS], int* rows, int* cols) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen failed");
        exit(1);
    }

    *rows = 0;
    *cols = 0;

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char* tok = strtok(line, ",");
        int i = 0;
        while (tok != NULL) {
            if (i >= MAX_COLS) {
                fprintf(stderr, "Too many columns (limit=%d)\n", MAX_COLS);
                exit(1);
            }
            data[*rows][i++] = atof(tok);
            tok = strtok(NULL, ",");
        }
        if (*cols == 0) {
            *cols = i;
        } else if (i != *cols) {
            fprintf(stderr, "Inconsistent number of columns at row %d\n", *rows+1);
            exit(1);
        }
        (*rows)++;
    }

    fclose(fp);
}

/**
 * Computes the mean and standard deviation of each column in the matrix.
 * Assumes 'means' and 'stddevs' have at least 'cols' elements.
 */
void compute_stats(const double data[MAX_ROWS][MAX_COLS], int rows, int cols, double means[MAX_COLS], double stddevs[MAX_COLS]) {
    // initialize the arrays
    for (int j = 0; j < cols; j++) {
        means[j] = 0.0;
        stddevs[j] = 0.0;
    }

    // compute the means
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            means[j] += data[i][j];
        }
    }
    for (int j = 0; j < cols; j++) {
        means[j] /= rows;
    }

    // compute the standard deviations
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            stddevs[j] += pow(data[i][j] - means[j], 2);
        }
    }
    for (int j = 0; j < cols; j++) {
        stddevs[j] = sqrt(stddevs[j] / rows);
    }
}

/**
 * Prints the mean and standard deviation of each column.
 */
void print_stats(const double means[MAX_COLS], const double stddevs[MAX_COLS], int cols) {
    for (int j = 0; j < cols; j++) {
        printf("col %d: mean=%lf stddev=%lf\n", j+1, means[j], stddevs[j]);
    }
}