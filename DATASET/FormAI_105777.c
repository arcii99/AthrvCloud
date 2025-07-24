//FormAI DATASET v1.0 Category: Recursive ; Style: rigorous
#include <stdio.h>

// Recursive function to calculate the sum of natural numbers from 1 to n
int calculateSum(int n) {
    // Base case: When n becomes 0, return 0
    if (n == 0) {
        return 0;
    }

    // Recursive case: Add n to the sum of natural numbers from 1 to n-1
    return n + calculateSum(n-1);
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Call the recursive function to calculate the sum of natural numbers from 1 to n
    int sum = calculateSum(n);

    printf("The sum of natural numbers from 1 to %d is: %d\n", n, sum);

    return 0;
}