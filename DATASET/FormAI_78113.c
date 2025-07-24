//FormAI DATASET v1.0 Category: Matrix operations ; Style: happy
#include<stdio.h>

int main(){

    printf("Welcome to our Matrix Operations program!\n");

    //Initialize matrices
    int matrix1[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int matrix2[3][3] = {{9,8,7}, {6,5,4}, {3,2,1}};

    printf("\nMatrix 1:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    //Addition of matrices
    int sum[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("\nSum of the matrices:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    //Subtraction of matrices
    int difference[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            difference[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    printf("\nDifference of the matrices:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ", difference[i][j]);
        }
        printf("\n");
    }

    //Multiplication of matrices
    int product[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            product[i][j] = 0;
            for(int k=0;k<3;k++){
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("\nProduct of the matrices:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    printf("\nThank you for using our program!\n");

    return 0;
}