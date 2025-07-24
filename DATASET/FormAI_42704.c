//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: innovative
#include <stdio.h>

int main() {
    int n, i, first = 0, second = 1, next;
    printf("Enter the number of terms you want to generate: ");
    scanf("%d", &n);
    
    printf("Fibonacci Series of %d terms:\n", n);
    
    for (i = 0; i < n; i++) {
        if (i <= 1)
            next = i;
        else {
            next = first + second;
            first = second;
            second = next;
        }
        int j;
        for (j = 0; j < next; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}