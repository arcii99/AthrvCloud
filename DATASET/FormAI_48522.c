//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    int i, j, isPrime;
    printf("Prime numbers from 1 to 100:\n");

    for (i = 2; i <= 100; i++) {
        isPrime = 1;

        for (j = 2; j <= i/2; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime == 1) {
            printf("%d ", i);
        }
    }

    return 0;
}

/*
 *    "Talk is cheap. Show me the code." -Linus Torvalds
 */