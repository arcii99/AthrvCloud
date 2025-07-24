//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: innovative
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define MATRIX_DIMENSION 10
#define PERCOLATION_THRESHOLD 0.5

bool does_percolate(int matrix[MATRIX_DIMENSION][MATRIX_DIMENSION]) {
    bool visited[MATRIX_DIMENSION][MATRIX_DIMENSION] = {{false}};
    bool percolates = false;
    int queue[MATRIX_DIMENSION*MATRIX_DIMENSION][2];
    int front = -1, rear = -1;
    for(int i=0; i<MATRIX_DIMENSION; i++) {
        if(matrix[0][i] == 1) {
            queue[++rear][0] = 0;
            queue[rear][1] = i;
            visited[0][i] = true;
        }
    }
    while(front != rear) {
        int row = queue[++front][0];
        int col = queue[front][1];
        if(row == MATRIX_DIMENSION-1) {
            percolates = true;
            break;
        }
        if(row+1 < MATRIX_DIMENSION && !visited[row+1][col] && matrix[row+1][col] == 1) {
            queue[++rear][0] = row+1;
            queue[rear][1] = col;
            visited[row+1][col] = true;
        }
        if(col+1 < MATRIX_DIMENSION && !visited[row][col+1] && matrix[row][col+1] == 1) {
            queue[++rear][0] = row;
            queue[rear][1] = col+1;
            visited[row][col+1] = true;
        }
        if(row-1 >= 0 && !visited[row-1][col] && matrix[row-1][col] == 1) {
            queue[++rear][0] = row-1;
            queue[rear][1] = col;
            visited[row-1][col] = true;
        }
        if(col-1 >= 0 && !visited[row][col-1] && matrix[row][col-1] == 1) {
            queue[++rear][0] = row;
            queue[rear][1] = col-1;
            visited[row][col-1] = true;
        }
    }
    return percolates;
}

int main() {
    srand(time(NULL));
    int matrix[MATRIX_DIMENSION][MATRIX_DIMENSION];
    int open_sites = 0;
    for(int i=0; i<MATRIX_DIMENSION; i++) {
        for(int j=0; j<MATRIX_DIMENSION; j++) {
            if((double)rand()/RAND_MAX <= PERCOLATION_THRESHOLD) {
                matrix[i][j] = 1;
                open_sites++;
            }
            else {
                matrix[i][j] = 0;
            }
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    if(does_percolate(matrix)) {
        printf("\nYES, the system percolates!\n");
    }
    else {
        printf("\nNO, the system does not percolate.\n");
    }
    printf("%d open sites out of %d total sites.\n", open_sites, MATRIX_DIMENSION*MATRIX_DIMENSION);
    return 0;
}