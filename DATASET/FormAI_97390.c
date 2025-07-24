//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: random
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, m;
    printf("Enter the dimensions of the matrix: ");
    scanf("%d %d", &n, &m);
    int matrix[n][m];

    // Reading input matrix
    printf("Enter the matrix elements:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    // Step-1 : selecting maximum element from each row
    int row_max[n], max_index;
    for(int i=0;i<n;i++){
        max_index = 0;
        for(int j=1;j<m;j++){
            if(matrix[i][j] > matrix[i][max_index]){
                max_index = j;
            }
        }
        row_max[i] = matrix[i][max_index];
    }

    // Step-2 : selecting minimum element from row_max array
    int min_index = 0;
    for(int i=1;i<n;i++){
        if(row_max[i] < row_max[min_index]){
            min_index = i;
        }
    }

    printf("The smallest maximum element in the matrix is: %d\n", row_max[min_index]);

    return 0;
}