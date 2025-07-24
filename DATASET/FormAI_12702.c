//FormAI DATASET v1.0 Category: Matrix operations ; Style: introspective
#include<stdio.h>

int main(){

    int n, m, i, j, k, determinant = 0;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d%d", &n, &m);

    int matrix[n][m];

    printf("\nEnter the elements of the matrix:\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nThe entered matrix is:\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    if (n == m){
        int temp[n - 1][n - 1], sign = 1;

        //Calculating determinant
        for (i = 0; i < n; i++){
            k = 0;
            for (j = 1; j < n; j++){
                int p;
                for (p = 0; p < n; p++){
                    if (p == i){
                        continue;
                    }
                    temp[j - 1][k] = matrix[j][p];
                    k++;
                }
                k = 0;
            }
            determinant += sign * matrix[0][i] * ((n == 1) ? 1 : det(temp, n - 1));
            sign = -sign;
        }

        printf("\nThe determinant of the matrix is: %d\n", determinant);
    } 

    else{
        printf("\nCannot calculate determinant as the matrix is not square\n");
    }

    return 0;
}

int det(int matrix[][15], int n){
    int i, j, k, determinant = 0;
    if (n == 1){
        return matrix[0][0];
    }
    else if (n == 2){
        return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
    }
    else{
        int temp[n - 1][n - 1], sign = 1;

        for (i = 0; i < n; i++){
            k = 0;
            for (j = 1; j < n; j++){
                int p;
                for (p = 0; p < n; p++){
                    if (p == i){
                        continue;
                    }
                    temp[j - 1][k] = matrix[j][p];
                    k++;
                }
                k = 0;
            }
            determinant += sign * matrix[0][i] * det(temp, n - 1);
            sign = -sign;
        }
        return determinant;
    }
}