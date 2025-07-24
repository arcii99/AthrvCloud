//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

/**
 * This program reads a CSV file and stores the values in a two-dimensional array.
 */

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    int row = 0;
    int col = 0;
    int num_rows = 0;
    int num_cols = 0;
    
    // Open the CSV file
    fp = fopen("sample.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    // Count the number of rows and columns in the file
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        col = 0;
        token = strtok(line, ",");
        while (token) {
            col++;
            token = strtok(NULL, ",");
        }
        if (col > num_cols) {
            num_cols = col;
        }
        num_rows++;
    }
    
    // Allocate memory for the two-dimensional array
    double **data = (double**)malloc(num_rows * sizeof(double*));
    for (int i=0; i<num_rows; i++) {
        data[i] = (double*)malloc(num_cols * sizeof(double));
    }
    
    // Reset the file pointer
    rewind(fp);
    
    // Fill the two-dimensional array with the values from the file
    row = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        col = 0;
        token = strtok(line, ",");
        while (token) {
            data[row][col] = atof(token);
            col++;
            token = strtok(NULL, ",");
        }
        row++;
    }
    
    // Print the contents of the two-dimensional array
    printf("Data:\n");
    for (int i=0; i<num_rows; i++) {
        for (int j=0; j<num_cols; j++) {
            printf("%f,", data[i][j]);
        }
        printf("\n");
    }
    
    // Free the memory allocated for the two-dimensional array
    for (int i=0; i<num_rows; i++) {
        free(data[i]);
    }
    free(data);
    
    // Close the file
    fclose(fp);
    
    return 0;
}