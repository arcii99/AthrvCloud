//FormAI DATASET v1.0 Category: Matrix operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices
void add(int m, int n, int a[][n], int b[][n], int c[][n])
{
    int i, j;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            
            // Adding two matrices
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract(int m, int n, int a[][n], int b[][n], int c[][n])
{
    int i, j;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            
            // Subtracting two matrices
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

// Function to multiply two matrices
void multiply(int m, int n, int l, int a[][n], int b[][l], int c[][l])
{
    int i, j, k;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < l; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++) {
                
                // Multiplying matrices
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main()
{
    int m, n, l, i, j;
    
    // Creating two matrices of size m*n and l*n
    printf("Enter the size of first matrix (m*n): ");
    scanf("%d %d", &m, &n);
    int a[m][n];
    printf("\nEnter elements of first matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("\nEnter the size of second matrix (l*n): ");
    scanf("%d %d", &l, &n);
    int b[l][n];
    printf("\nEnter elements of second matrix:\n");
    for (i = 0; i < l; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    
    // Creating a matrix of size m*l to store the result
    int c[m][l];
    printf("\nEnter choice:\n1. Add two matrices\n2. Subtract two matrices\n3. Multiply two matrices\n");
    int choice;
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            if (m != l || n != l) {
                printf("\nMatrices cannot be added!\n");
            } else {
                add(m, n, a, b, c);
                printf("Result: \n");
                for (i = 0; i < m; i++) {
                    for (j = 0; j < n; j++) {
                        printf("%d ", c[i][j]);
                    }
                    printf("\n");
                }
            }
            break;
        case 2:
            if (m != l || n != l) {
                printf("\nMatrices cannot be subtracted!\n");
            } else {
                subtract(m, n, a, b, c);
                printf("Result: \n");
                for (i = 0; i < m; i++) {
                    for (j = 0; j < n; j++) {
                        printf("%d ", c[i][j]);
                    }
                    printf("\n");
                }
            }
            break;
        case 3:
            if (n != l) {
                printf("\nMatrices cannot be multiplied!\n");
            } else {
                multiply(m, n, l, a, b, c);
                printf("Result: \n");
                for (i = 0; i < m; i++) {
                    for (j = 0; j < l; j++) {
                        printf("%d ", c[i][j]);
                    }
                    printf("\n");
                }
            }
            break;
        default:
            printf("\nInvalid choice!\n");
    }
    
    return 0;
}