//FormAI DATASET v1.0 Category: Matrix operations ; Style: lively
#include<stdio.h>

// Function to display matrix
void display(int matrix[][3], int row, int col) {
    int i,j;
    printf("\nThe matrix is:\n");
    for(i=0;i<row;i++) {
        for(j=0;j<col;j++) {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void add(int matrix1[][3], int matrix2[][3], int result[][3]) {
    int i,j;
    for(i=0;i<3;i++) {
        for(j=0;j<3;j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main() {
    int matrix1[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int matrix2[3][3] = {{9,8,7}, {6,5,4}, {3,2,1}};
    int result[3][3];
    printf("Welcome to MATRIX operations!\n");
    
    // Display the matrices
    display(matrix1,3,3);
    display(matrix2,3,3);
    
    // Add the matrices
    add(matrix1,matrix2,result);
    display(result,3,3);
    
    printf("Thanks for using MATRIX operations!\n");
    return 0;
}