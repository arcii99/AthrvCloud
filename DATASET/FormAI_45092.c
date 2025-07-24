//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// function to generate Fibonacci sequence
int fibonacci(int n)
{
    if (n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n, i, j;

    printf("Enter the number of terms for Fibonacci sequence: ");
    scanf("%d", &n);

    // loop to print out the sequence
    for (i = 0; i < n; i++) {
        printf("Term %d: %d\n", i+1, fibonacci(i));
        sleep(1); // add a delay for visualization effect
    }

    // clear console and print out the final sequence
    system("clear");
    printf("Final Sequence:\n");
    for (j = 0; j < n; j++) {
        printf("%d ", fibonacci(j));
    }
    printf("\n");

    return 0;
}