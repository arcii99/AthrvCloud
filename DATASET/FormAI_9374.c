//FormAI DATASET v1.0 Category: Game of Life ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// create a matrix with random binary values
void createMatrix(int m, int n, int matrix[m][n]) {
    srand(time(NULL));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            matrix[i][j] = rand() % 2;
        }
    }
}

// print out the matrix
void printMatrix(int m, int n, int matrix[m][n]) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// apply the Game of Life rules
void applyRules(int m, int n, int matrix[m][n], int newMatrix[m][n]) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            int count = 0;
            // count the number of neighbors that are alive
            for(int k=i-1; k<=i+1; k++) {
                for(int l=j-1; l<=j+1; l++) {
                    if((k>=0 && k<m) && (l>=0 && l<n) && !(k==i && l==j) && matrix[k][l]==1) {
                        count++;
                    }
                }
            }
            // apply the rules of the Game of Life
            if(matrix[i][j]==1 && (count<2 || count>3)) {
                newMatrix[i][j] = 0;
            } else if(matrix[i][j]==0 && count==3) {
                newMatrix[i][j] = 1;
            } else {
                newMatrix[i][j] = matrix[i][j];
            }
        }
    }
}

int main() {
    int m = 10;
    int n = 10;
    
    int matrix[m][n];
    createMatrix(m, n, matrix);
    printf("Initial matrix:\n");
    printMatrix(m, n, matrix);
    
    int newMatrix[m][n];
    applyRules(m, n, matrix, newMatrix);
    printf("New matrix:\n");
    printMatrix(m, n, newMatrix);
    
    return 0;
}