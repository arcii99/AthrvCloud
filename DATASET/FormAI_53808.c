//FormAI DATASET v1.0 Category: Matrix operations ; Style: sophisticated
#include<stdio.h>

int main(){

    int n, m; // n and m are size of matrix
    printf("Enter the size of matrix: ");
    scanf("%d %d", &n, &m);

    int matrix[n][m]; // 2D array initialization

    // read the elements of the matrix
    printf("\nEnter the elements of the matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &matrix[i][j]); 
        }
    }

    // display the matrix
    printf("\nMatrix: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ", matrix[i][j]); 
        }
        printf("\n");
    }

    // find the transpose of the matrix
    int transpose[m][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            transpose[j][i] = matrix[i][j];
        }
    }

    // display the transpose of the matrix
    printf("\nTranspose of the matrix: \n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d ", transpose[i][j]); 
        }
        printf("\n");
    }

    // calculate determinant of matrix
    int determinant;
    if(n == m){
        int size = n;
        int temp[size][size];
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                temp[i][j] = matrix[i][j];
            }
        }
        for(int i=0; i<size-1; i++){
            for(int j=i+1; j<size; j++){
                float ratio = temp[j][i]/(float)temp[i][i];
                for(int k=0; k<size; k++){
                    temp[j][k] = temp[j][k] - ratio*temp[i][k];
                }
            }
        }
        determinant = 1;
        for(int i=0; i<size; i++){
            determinant *= temp[i][i];
        }
    }
    else{
        printf("\nError: Determinant can only be calculated for square matrix.");
        return 0;
    }

    // display determinant of the matrix
    printf("\nDeterminant of the matrix: %d", determinant);

    return 0;
}