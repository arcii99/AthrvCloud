//FormAI DATASET v1.0 Category: Educational ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 5
#define COLS 5

int main(){
    int matrix[ROWS][COLS], i, j;
    int sum_x = 0, sum_y = 0, sum_z = 0, sum_diag = 0;
    float x_avg, y_avg, z_avg, diag_avg;

    srand(time(NULL)); // to generate random numbers in matrix

    // Initialize the matrix with random integers between 1-100
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLS; j++){
            matrix[i][j] = rand()%100 + 1;
        }
    }

    // Display the matrix
    printf("Original matrix:\n");
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLS; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Calculate the sums of each row, column, and diagonal
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLS; j++){
            if(i == j){ // diagonal
                sum_diag += matrix[i][j];
            }
            sum_x += matrix[i][j]; // row
            sum_y += matrix[j][i]; // column
        }
        sum_z += matrix[i][ROWS-1-i]; // other diagonal
    }

    // Calculate the averages
    x_avg = (float)sum_x/COLS;
    y_avg = (float)sum_y/ROWS;
    z_avg = (float)sum_z/ROWS;
    diag_avg = (float)sum_diag/ROWS;

    // Display the results
    printf("\nSum of each row: %d %d %d %d %d\n", sum_x/COLS, sum_x/COLS, sum_x/COLS, sum_x/COLS, sum_x/COLS);
    printf("Sum of each column: %d %d %d %d %d\n", sum_y/ROWS, sum_y/ROWS, sum_y/ROWS, sum_y/ROWS, sum_y/ROWS);
    printf("Sum of diagonal: %d\n", sum_diag);
    printf("Sum of other diagonal: %d\n", sum_z);
    printf("\nAverage of each row: %.1f %.1f %.1f %.1f %.1f\n", x_avg, x_avg, x_avg, x_avg, x_avg);
    printf("Average of each column: %.1f %.1f %.1f %.1f %.1f\n", y_avg, y_avg, y_avg, y_avg, y_avg);
    printf("Average of diagonal: %.1f\n", diag_avg);
    printf("Average of other diagonal: %.1f\n", z_avg);

    return 0;
}