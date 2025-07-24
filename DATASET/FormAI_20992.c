//FormAI DATASET v1.0 Category: Educational ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols, i, j, sum = 0;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    int arr[rows][cols];
    srand(time(NULL));

    printf("\nInitial matrix:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            arr[i][j] = rand() % 10;
            printf("%d ", arr[i][j]);
            sum += arr[i][j];
        }
        printf("\n");
    }
    printf("\nSum of all elements = %d\n\n", sum);

    int max = arr[0][0];
    int min = arr[0][0];
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(arr[i][j] > max) {
                max = arr[i][j];
            }
            if(arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    printf("Maximum element = %d\n", max);
    printf("Minimum element = %d\n", min);

    printf("\nTransposed matrix:\n");
    for(i = 0; i < cols; i++) {
        for(j = 0; j < rows; j++) {
            printf("%d ", arr[j][i]);
        }
        printf("\n");
    }

    return 0;
}