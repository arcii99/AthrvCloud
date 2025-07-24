//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide the path to the CSV file as an argument.\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    char buffer[MAX_LEN];
    int row_count = 0;
    int column_count = 0;

    while (fgets(buffer, MAX_LEN, file)) {
        if (row_count == 0) {
            // Count the number of columns in a CSV file by counting the number of commas in the first row
            for (int i = 0; i < strlen(buffer); i++) {
                if (buffer[i] == ',') {
                    column_count++;
                }
            }
            // Add 1 for the last column
            column_count++;
        }
        // Count the number of rows in a CSV file
        row_count++;
    }

    // Allocate memory for the 2D array
    double **data = malloc(row_count * sizeof(double *));
    for (int i = 0; i < row_count; i++) {
        data[i] = malloc(column_count * sizeof(double));
    }

    // Reset the file pointer
    fseek(file, 0, SEEK_SET);

    int row_index = 0;
    int column_index = 0;
    char *token;

    while (fgets(buffer, MAX_LEN, file)) {
        token = strtok(buffer, ",");
        while (token != NULL) {
            data[row_index][column_index++] = atof(token);
            token = strtok(NULL, ",");
        }
        row_index++;
        column_index = 0;
    }

    // Print the CSV file contents
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < column_count; j++) {
            printf("%.2f\t", data[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the 2D array
    for (int i = 0; i < row_count; i++) {
        free(data[i]);
    }
    free(data);

    // Close the file
    if (fclose(file) != 0) {
        printf("Failed to close the file.\n");
    }

    return 0;
}