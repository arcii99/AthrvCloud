//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    long long int a, b, c;

    // accept number of terms to be output
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // initialize first two terms of fibonacci series
    a = 0;
    b = 1;

    // print the first two terms of series
    printf("%lld %lld ", a, b);

    // loop through the remaining terms of the series
    for (i = 2; i < n; i++){
        // calculate the next term of the series
        c = a + b;

        // print the current term
        printf("%lld ", c);

        // update the first two terms
        a = b;
        b = c;
    }

    // output a newline character to separate the fibonacci sequence from the rest of the output
    printf("\n");

    return 0;
}