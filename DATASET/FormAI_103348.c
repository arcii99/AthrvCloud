//FormAI DATASET v1.0 Category: Data mining ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS 20
#define MAX_ROWS 100

// Function to read the input CSV file
void readCSV(const char *file_path, double data[MAX_ROWS][MAX_COLS], int *num_rows, int *num_cols) {
    FILE *fp = fopen(file_path, "r");
    char buffer[1024];

    if (fp == NULL) {
        printf("Error: Unable to open file: %s\n", file_path);
        exit(1);
    }

    *num_rows = 0;

    while (fgets(buffer, 1024, fp)) {
        int col_idx = 0;
        char *value = strtok(buffer, ",");
        while (value) {
            data[*num_rows][col_idx++] = atof(value);
            value = strtok(NULL, ",");
        }
        *num_cols = col_idx;
        (*num_rows)++;
    }

    fclose(fp);
}

// Function to normalize the data to range [0, 1]
void normalizeData(double data[MAX_ROWS][MAX_COLS], int num_rows, int num_cols) {
    double min_val[MAX_COLS], max_val[MAX_COLS];
    
    for (int i = 0; i < num_cols; i++) {
        min_val[i] = data[0][i];
        max_val[i] = data[0][i];

        for (int j = 0; j < num_rows; j++) {
            if (data[j][i] < min_val[i]) {
                min_val[i] = data[j][i];
            }
            if (data[j][i] > max_val[i]) {
                max_val[i] = data[j][i];
            }
        }

        for (int j = 0; j < num_rows; j++) {
            data[j][i] = (data[j][i] - min_val[i]) / (max_val[i] - min_val[i]);
        }
    }
}

// Function to perform k-means clustering
void kMeans(double data[MAX_ROWS][MAX_COLS], int num_rows, int num_cols, int k, double centroids[k][MAX_COLS]) {
    int labels[num_rows];
    int iter = 0;

    // Initialize the centroids randomly
    for (int i = 0; i < k; i++) {
        int idx = rand() % num_rows;
        for (int j = 0; j < num_cols; j++) {
            centroids[i][j] = data[idx][j];
        }
    }

    while (iter < 100) { // Maximum 100 iterations
        int changes = 0;
        
        // Assign data points to their nearest centroid
        for (int i = 0; i < num_rows; i++) {
            double min_dist = 999999.0;
            int min_idx = -1;

            for (int j = 0; j < k; j++) {
                double dist = 0.0;

                for (int l = 0; l < num_cols; l++) {
                    dist += (data[i][l] - centroids[j][l]) * (data[i][l] - centroids[j][l]);
                }

                if (dist < min_dist) {
                    min_dist = dist;
                    min_idx = j;
                }
            }

            if (labels[i] != min_idx) {
                labels[i] = min_idx;
                changes++;
            }
        }

        if (changes == 0) {
            break;
        }

        // Update the centroids
        double sums[k][MAX_COLS];
        int counts[k];

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < num_cols; j++) {
                sums[i][j] = 0.0;
            }
            counts[i] = 0;
        }

        for (int i = 0; i < num_rows; i++) {
            int label = labels[i];
            for (int j = 0; j < num_cols; j++) {
                sums[label][j] += data[i][j];
            }
            counts[label]++;
        }

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < num_cols; j++) {
                centroids[i][j] = sums[i][j] / counts[i];
            }
        }

        iter++;
    }

    printf("Final centroids:\n");
    for (int i = 0; i < k; i++) {
        printf("Centroid %d: ", i+1);
        for (int j = 0; j < num_cols; j++) {
            printf("%lf ", centroids[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double data[MAX_ROWS][MAX_COLS];
    int num_rows, num_cols, k;

    // Read the input CSV file
    readCSV("data.csv", data, &num_rows, &num_cols);
    
    // Normalize the data to range [0, 1]
    normalizeData(data, num_rows, num_cols);

    printf("Enter the number of clusters (k): ");
    scanf("%d", &k);

    double centroids[k][MAX_COLS];

    // Perform k-means clustering
    kMeans(data, num_rows, num_cols, k, centroids);

    return 0;
}