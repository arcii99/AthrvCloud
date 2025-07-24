//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: optimized
#include <stdio.h>

int main() {
    int n, i = 0, j = 1, next;
    
    printf("Enter the number of terms:");
    scanf("%d", &n);

    printf("Fibonacci Series:\n");

    for (int k = 0; k < n; k++)  
    {
        if (k <= 1)
            next = k;
        else {
            next = i + j;
            i = j;
            j = next;
        }
        printf("%d, ", next);
    }

    printf("\n");

    return 0;
}