//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: romantic
#include <stdio.h>

int fibonacci(int n) {
    if(n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

void print_fibonacci(int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", fibonacci(i));
    }
}

int main() {
    int n;
    printf("How many terms of the Fibonacci sequence do you want to visualize: ");
    scanf("%d", &n);
    printf("Here is your Fibonacci sequence in a romantic style:\n\n");

    // Romantic Fibonacci sequence
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\nAnd here it is in a more traditional style:\n\n");
    print_fibonacci(n);

    return 0;
}