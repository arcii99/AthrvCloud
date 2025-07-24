//FormAI DATASET v1.0 Category: Scientific ; Style: thoughtful
#include <stdio.h>

int main() {

    /* This program calculates the sum of the first N odd numbers using a for loop. */

    int N;
    int sum = 0;

    // Prompt the user to enter a value for N.
    printf("Enter a value for N: ");
    scanf("%d", &N);

    // Calculate the sum of the first N odd numbers.
    for (int i = 1; i <= N; i++) {
        sum += (2*i) - 1; // Alternatively, we could use sum += i*2 - 1.
    }

    // Display the result.
    printf("The sum of the first %d odd numbers is %d.\n", N, sum);

    return 0;
}