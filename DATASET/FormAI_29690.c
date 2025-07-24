//FormAI DATASET v1.0 Category: Arithmetic ; Style: Alan Touring
#include <stdio.h>

int main(void) {
    int fib[20] = {0, 1}; // Store the first two numbers of Fibonacci sequence
    int i, j, k, l, m, n, x, y, z;
    // i, j, k, l are loop counters, m stores the row index, n stores the column index
    // x, y, z are temporary variables for swapping values

    // Compute the first 18 numbers of Fibonacci sequence and store them in the array
    for (i = 2; i < 20; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // Spiral print the first 20 numbers of Fibonacci sequence
    m = n = 5; // Starting position of printing spiral
    printf("%d\n", fib[0]);

    for (i = 1; i < 20; i++) {
        if (i == 1) { // Special case for the second number
            printf("%d ", fib[1]);
            n++;
        }

        // Spiral down
        for (j = 1; j < m && i < 20; j++) {
            if (n < 10) {
                printf("%d ", fib[i++]);
            } else {
                printf("%d", fib[i++]);
            }
            n++;
        }

        // Spiral right
        for (k = 1; k < n && i < 20; k++) {
            if (n+k <= 10) {
                printf("%d ", fib[i++]);
            } else {
                printf("%d", fib[i++]);
            }
        }
        n -= k-1;

        // Spiral up
        for (l = 1; l < m && i < 20; l++) {
            if (n > 1) {
                if (n <= 10) {
                    printf("%d ", fib[i++]);
                } else {
                    printf("%d", fib[i++]);
                }
                n--;
            } else {
                break;
            }
        }
        m -= l-1;

        // Spiral left
        for (x = 1, y = n-1; x < n && i < 20; x++, y--) {
            if (y > 1) {
                if (y <= 10) {
                    printf("%d ", fib[i++]);
                } else {
                    printf("%d", fib[i++]);
                }
            } else {
                break;
            }
        }
        n -= x-1;

        // Move to the next starting position of printing spiral
        if (i < 20) {
            m -= 2;
            n++;
        }
    }

    return 0;
}