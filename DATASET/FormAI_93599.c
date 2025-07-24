//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 10

void print_matrix(int matrix[][MATRIX_SIZE]){
    int row, col;
    for(row = 0; row < MATRIX_SIZE; ++row)
    {
        for(col = 0; col < MATRIX_SIZE; ++col)
        {
            if(matrix[row][col])
            {
                printf("# ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Checks for percolation
int check_percolation(int matrix[][MATRIX_SIZE]){
    int i, j, k, l, sum;
    for(i = MATRIX_SIZE-1; i >= 0 ; --i)
    {
        sum = 0;
        for(j = 0; j < MATRIX_SIZE; ++j)
        {
            if(matrix[i][j]){
                sum = 1;
                break;
            }
        }

        if(sum == 0)
            return 0;

        for(k = 0; k < MATRIX_SIZE; ++k){
            if(matrix[i][k])
            {
                for(l = i+1; l < MATRIX_SIZE; ++l)
                {
                    if(matrix[l][k])
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
};


int main(){
    srand(time(0));
    int i, j, percolation;
    int matrix[MATRIX_SIZE][MATRIX_SIZE] = {{0}};

    for(i = 0; i < MATRIX_SIZE; ++i)
    {
        for(j = 0; j < MATRIX_SIZE; ++j)
        {
            if((double)rand()/RAND_MAX > 0.65){
                matrix[i][j] = 1;
            }
        }
    }

    percolation = check_percolation(matrix);
    printf("Initial Matrix:\n");
    print_matrix(matrix);

    if(percolation == 1){
        printf("The system is percolating\n");
    }
    else {
        printf("The system is not percolating\n");
    }
    return 0;
}