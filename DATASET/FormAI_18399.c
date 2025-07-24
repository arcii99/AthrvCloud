//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Oh fair maiden, wilt thou witness the marvels of the Fibonacci sequence?\n");
    printf("Pray, tell me, what value wouldst thou like me to compute?\n");
    int n;
    scanf("%d", &n);

    printf("Ah, %d, a fine choice indeed!\n", n);

    // Compute the Fibonacci sequence
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    printf("Behold, the sequence of Fibonacci, created in all its glory:\n");

    // Print the sequence in a beautiful format
    for (int i = 1; i <= n; i++) {
        printf("| %6d |", fib[i]);
        if (i % 3 == 0) {
            printf("\n");
        }
    }

    printf("Pray, dear lady, hast thou seen such beauty before?\n");
    printf("Forsooth, it is a sight to behold!\n");

    return 0; 
}