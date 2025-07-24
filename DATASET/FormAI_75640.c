//FormAI DATASET v1.0 Category: Data mining ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 5
#define MAX_INPUT_LENGTH 100

int main() {

    // Creating a 2D array to hold the dataset
    float dataset[ROWS][COLS];

    // Reading the dataset from a file
    FILE *fp;
    fp = fopen("dataset.txt", "r");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    int row = 0;
    char line[MAX_INPUT_LENGTH];
    char *token;
    while(fgets(line, MAX_INPUT_LENGTH, fp)) {
        int col = 0;
        token = strtok(line, ",");
        while(token != NULL) {
            dataset[row][col] = atof(token);
            col++;
            token = strtok(NULL, ",");
        }
        row++;
    }
    fclose(fp);

    // Finding the maximum value in the dataset
    float max_value = dataset[0][0];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(dataset[i][j] > max_value) {
                max_value = dataset[i][j];
            }
        }
    }
    printf("The maximum value in the dataset is: %f\n", max_value);

    // Finding the average value in each column of the dataset
    float column_averages[COLS] = {0};
    for(int i = 0; i < COLS; i++) {
        float sum = 0;
        for(int j = 0; j < ROWS; j++) {
            sum += dataset[j][i];
        }
        column_averages[i] = sum / ROWS;
        printf("The average value in column %d is: %f\n", i+1, column_averages[i]);
    }

    return 0;
}