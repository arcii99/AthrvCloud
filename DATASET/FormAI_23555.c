//FormAI DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>

int main() {
    // Program to find the sum of natural numbers up to n
    int n, sum = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    // Validation check
    if (n < 0) {
        printf("Invalid input! Please enter a positive integer.\n");
        return 0;
    }

    // Computing the sum of natural numbers up to n
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    // Displaying the sum
    printf("The sum of natural numbers up to %d is %d.\n", n, sum);
    return 0;
}