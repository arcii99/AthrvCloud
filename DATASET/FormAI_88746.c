//FormAI DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>

int main() {
    int n, m, i, j, k, sum = 0;
    float avg;
    // get number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);
    // create 2D array
    int a[n][m];
    // get input from user for array elements
    for (i = 0; i < n; i++) {
        printf("Enter the elements for row %d: ", i+1);
        for (j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    //display the array
    printf("\n Given array is : \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf(" %d ", a[i][j]);
        }
        printf("\n");
    }
    // calculate the sum and average of each row
    printf("\nSum and average of each row: \n");
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < m; j++) {
            sum += a[i][j];
        }
        avg = (float)sum / m;
        printf("Sum of row %d = %d, Average of row %d = %.2f \n", i+1, sum, i+1, avg);
    }
    // calculate the sum and average of each column
    printf("\nSum and average of each column: \n");
    for (i = 0; i < m; i++) {
        sum = 0;
        for (j = 0; j < n; j++) {
            sum += a[j][i];
        }
        avg = (float)sum / n;
        printf("Sum of column %d = %d, Average of column %d = %.2f \n", i+1, sum, i+1, avg);
    }
    return 0;
}