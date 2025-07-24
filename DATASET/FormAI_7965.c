//FormAI DATASET v1.0 Category: Data mining ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_ROWS 1000
#define MAX_COLS 10

// Data structure to hold the dataset
typedef struct Dataset {
    double data[MAX_ROWS][MAX_COLS];
    int num_rows;
    int num_cols;
} Dataset;

// Function to read a dataset from a CSV file
void read_dataset_csv(char* filename, Dataset* dataset) {
    FILE* file_ptr = fopen(filename, "r");

    if (file_ptr == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    int row_num = 0;
    char line[1024];

    while (fgets(line, 1024, file_ptr)) {
        char* token = strtok(line, ",");
        int col_num = 0;

        while (token) {
            dataset->data[row_num][col_num] = atof(token);
            token = strtok(NULL, ",");
            col_num++;
        }

        row_num++;
    }

    dataset->num_rows = row_num;
    dataset->num_cols = MAX_COLS; // Assuming all rows have same number of columns

    fclose(file_ptr);
}

// Function to calculate the mean of a column
double calculate_mean(double* col_data, int num_rows) {
    double sum = 0.0;

    for (int i = 0; i < num_rows; i++) {
        sum += col_data[i];
    }

    return sum / (double)num_rows;
}

// Function to calculate the standard deviation of a column
double calculate_std_dev(double* col_data, int num_rows) {
    double mean = calculate_mean(col_data, num_rows);
    double sum_squared_diff = 0.0;

    for (int i = 0; i < num_rows; i++) {
        double diff = col_data[i] - mean;
        sum_squared_diff += diff * diff;
    }

    return sqrt(sum_squared_diff / (double)num_rows);
}

// Function to normalize a column using z-score normalization
void normalize_column(double* col_data, int num_rows) {
    double mean = calculate_mean(col_data, num_rows);
    double std_dev = calculate_std_dev(col_data, num_rows);

    for (int i = 0; i < num_rows; i++) {
        col_data[i] = (col_data[i] - mean) / std_dev;
    }
}

int main() {
    Dataset dataset;
    read_dataset_csv("data.csv", &dataset);

    // Normalize each column of the dataset
    for (int col_num = 0; col_num < dataset.num_cols; col_num++) {
        double* col_data = dataset.data[col_num];

        normalize_column(col_data, dataset.num_rows);
    }

    // Print the normalized dataset
    for (int row_num = 0; row_num < dataset.num_rows; row_num++) {
        for (int col_num = 0; col_num < dataset.num_cols; col_num++) {
            printf("%f,", dataset.data[row_num][col_num]);
        }

        printf("\n");
    }

    return 0;
}