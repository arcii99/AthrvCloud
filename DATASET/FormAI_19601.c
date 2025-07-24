//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1 = 0, num2 = 1, sum, i, n;
    
    printf("Enter the number of terms for Fibonacci sequence: ");
    scanf("%d", &n);
    
    printf("\nFibonacci Sequence:\n");
    
    for (i = 1; i <= n; i++)
    {
        printf("%d ", num1);
        sum = num1 + num2;
        num1 = num2;
        num2 = sum;
    }
    
    printf("\n\n");
    
    return 0;
}