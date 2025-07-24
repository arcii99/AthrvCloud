//FormAI DATASET v1.0 Category: Data mining ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 1000
#define MAX_NUM_COLUMNS 10
#define MAX_NUM_ROWS 1000

int main() {
    // Open file for reading
    FILE *file = fopen("data.txt", "r");
    if (!file) {
        printf("Failed to open file.\n");
        return 1;
    }

    // Read data into 2D array
    float data[MAX_NUM_ROWS][MAX_NUM_COLUMNS];
    int num_rows = 0;
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file) != NULL) {
        char *token = strtok(line, ",");
        int num_columns = 0;
        while (token != NULL) {
            data[num_rows][num_columns] = atof(token);
            num_columns++;
            token = strtok(NULL, ",");
        }
        num_rows++;
    }

    // Print data
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < MAX_NUM_COLUMNS; j++) {
            printf("%f ", data[i][j]);
        }
        printf("\n");
    }

    // Perform some basic data mining
    float column_means[MAX_NUM_COLUMNS] = {0};
    float column_variance[MAX_NUM_COLUMNS] = {0};
    for (int j = 0; j < MAX_NUM_COLUMNS; j++) {
        // Calculate mean
        float sum = 0;
        for (int i = 0; i < num_rows; i++) {
            sum += data[i][j];
        }
        column_means[j] = sum / num_rows;

        // Calculate variance
        float variance_sum = 0;
        for (int i = 0; i < num_rows; i++) {
            variance_sum += (data[i][j] - column_means[j]) * (data[i][j] - column_means[j]);
        }
        column_variance[j] = variance_sum / num_rows;
    }

    // Print results
    printf("---------------------------------------\n");
    printf("Some basic data mining results:\n");
    printf("---------------------------------------\n");
    for (int j = 0; j < MAX_NUM_COLUMNS; j++) {
        printf("Column %d mean: %f\n", j, column_means[j]);
        printf("Column %d variance: %f\n", j, column_variance[j]);
    }

    // Close file
    fclose(file);

    return 0;
}