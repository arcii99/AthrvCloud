//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
    if(n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int numTerms;
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Please enter the number of terms you want to see: ");
    scanf("%d", &numTerms);

    if(numTerms <= 0) {
        printf("Please enter a number greater than zero.\n");
        exit(1);
    }

    printf("Here are the first %d terms of the Fibonacci sequence:\n", numTerms);
    int i;
    for(i = 0; i < numTerms; i++) {
        int term = fibonacci(i);
        printf("%d ", term);
    }
    printf("\n");

    printf("Now let's visualize the sequence!\n");

    int j, k;
    for(j = numTerms; j > 0; j--) {
        for(k = 0; k < j; k++) {
            printf("%d ", fibonacci(k));
        }
        printf("\n");
    }

    return 0;
}