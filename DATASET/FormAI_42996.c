//FormAI DATASET v1.0 Category: Benchmarking ; Style: high level of detail
#include <stdio.h>
#include <time.h>

// This function calculates the product of two matrices
void matrix_product(int *matrix1, int *matrix2, int *result_matrix, int rows1, int cols1, int rows2, int cols2){
    int i, j, k;
    for(i=0;i<rows1;i++){
        for(j=0;j<cols2;j++){
            *(result_matrix + i * cols2 + j) = 0;
            for(k=0;k<cols1;k++){
                *(result_matrix + i * cols2 + j) += *(matrix1 + i * cols1 + k) * *(matrix2 + k * cols2 + j);
            }
        }
    }
}

int main(){
    int rows1 = 10, cols1 = 10, rows2 = 10, cols2 = 10, i, j;

    // Define matrices
    int matrix1[rows1][cols1], matrix2[rows2][cols2], result_matrix[rows1][cols2];

    // Populate matrix1 with random values
    for(i=0;i < rows1;i++){
        for(j=0;j < cols1;j++){
            matrix1[i][j] = rand() % 100;
        }
    }

    // Populate matrix2 with random values
    for(i=0;i < rows2;i++){
        for(j=0;j < cols2;j++){
            matrix2[i][j] = rand() % 100;
        }
    }

    // Start timer
    clock_t start_time = clock();

    // Calculate matrix product
    matrix_product(&matrix1[0][0], &matrix2[0][0], &result_matrix[0][0], rows1, cols1, rows2, cols2);

    // End timer
    clock_t end_time = clock();

    // Calculate elapsed time
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Elapsed time: %f seconds.\n", time_spent);

    return 0;
}