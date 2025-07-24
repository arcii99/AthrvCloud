//FormAI DATASET v1.0 Category: Educational ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

/* This program prints the Fibonacci sequence up to a user specified number. */

int main() {
    int input;

    printf("Enter the number of Fibonacci terms to display: ");
    scanf("%d", &input);

    int a = 0, b = 1, c = 0;
    printf("%d ", a);
    printf("%d ", b);

    for (int i = 0; i < input - 2; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }

    return 0;
}