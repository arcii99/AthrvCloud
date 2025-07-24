//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void generateFibonacci(int n){
    int first = 0, second = 1, next, i;
    printf("%d %d ", first, second);
    for (i = 2; i < n; i++){
        next = first + second;
        first = second;
        second = next;
        printf("%d ", next);
    }
    printf("\n");
}

void plotFibonacci(int n){
    int first = 0, second = 1, next, i;
    printf("\nPlotting Fibonacci Sequence of %d terms...\n\n", n);
    for (i = 1; i <= n; i++){
        next = first + second;
        first = second;
        second = next;
        int j;
        for (j = 1; j <= next; j++){
            printf("* ");
        }
        printf("\n");
    }
}

int main(){
    int n;
    printf("Enter the number of terms for Fibonacci Sequence: ");
    scanf("%d", &n);
    
    // Generate and print Fibonacci Sequence
    printf("\nGenerated Fibonacci Sequence: ");
    generateFibonacci(n);
    
    // Plot Fibonacci Sequence
    plotFibonacci(n);
    
    return 0;
}