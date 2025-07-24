//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, n, t1 = 0, t2 = 1, nextTerm, randNum;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Generate random number between 1 and 100
    srand(time(0)); 
    randNum = (rand() % 100) + 1;

    printf("Random Number: %d\n", randNum);

    // Check if random number is even or odd
    if (randNum % 2 == 0) {
        printf("\nGenerating even numbers in Fibonacci sequence up to %d:\n", n);
        for (i = 1; i <= n; i++) {
            printf("%d, ", t1);
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
            while (nextTerm % 2 != 0) {
                nextTerm = t1 + t2;
                t1 = t2;
                t2 = nextTerm;
            }
        }
    } else {
        printf("\nGenerating odd numbers in Fibonacci sequence up to %d:\n", n);
        for (i = 1; i <= n; i++) {
            printf("%d, ", t1);
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
            while (nextTerm % 2 == 0) {
                nextTerm = t1 + t2;
                t1 = t2;
                t2 = nextTerm;
            }
        }
    }
    return 0;
}