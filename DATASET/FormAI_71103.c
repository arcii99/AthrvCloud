//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: brave
#include <stdio.h>

void fibonacciVisualizer(int terms) {
    int sequence[terms], i;
    
    sequence[0] = 0;
    sequence[1] = 1;
    
    for (i = 2; i < terms; i++) {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }
    
    for (i = 0; i < terms; i++) {
        printf("%d\t", sequence[i]);
        int j;
        for (j = 0; j < sequence[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    printf("--- Fibonacci Sequence Visualizer ---\n");
    printf("Enter the number of terms to generate: ");
    int terms;
    scanf("%d", &terms);
    printf("\n");
    
    fibonacciVisualizer(terms);
    
    return 0;
}