//FormAI DATASET v1.0 Category: Matrix operations ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

int main(){
    int m, n;
    printf("Enter the number of rows and columns of matrix: \n");
    scanf("%d %d", &m, &n);
    
    printf("Creating a matrix with %d rows and %d columns...\n", m, n);
    int matrix[m][n]; //declaring matrix of size m x n
    printf("Matrix created successfully. Enter the values now: \n");
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    
    printf("\nPrinting the matrix entered: \n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Surrealist operation: \n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            matrix[i][j] += rand()%10; //adding a random number to each element of the matrix
        }
    }
    printf("\nPrinting the surrealistically operated matrix: \n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}