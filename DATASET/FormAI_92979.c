//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to calculate fibonacci sequence
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    // seed random number generator
    srand(time(NULL));

    // generate random number between 20 and 30
    int n = rand() % 11 + 20;

    // calculate fibonacci sequence for random number
    int result = 0;
    for (int i = 0; i <= n; i++) {
        result += fibonacci(i);
    }

    // display result
    printf("The sum of the first %d numbers in the fibonacci sequence is %d\n", n, result);

    return 0;
}