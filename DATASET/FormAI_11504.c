//FormAI DATASET v1.0 Category: Data mining ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);

    // Dynamically allocate memory for the 2D array
    int **arr = (int **)malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++)
        arr[i] = (int *)malloc(m * sizeof(int));

    // Populate the 2D array with user input
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("Enter the value for arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // Find the maximum value in the array
    int max = arr[0][0];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] > max)
                max = arr[i][j];
        }
    }

    // Print the maximum value and its location in the array
    printf("\nThe maximum value in the array is %d\n", max);
    printf("It is located at:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == max)
                printf("(%d, %d)\n", i, j);
        }
    }

    // Free the dynamically allocated memory
    for(int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);

    return 0;
}