//FormAI DATASET v1.0 Category: Scientific ; Style: mathematical
#include <stdio.h>

/* This program calculates the sum of the first n natural numbers using a formula */

int main() {
    int n, sum;
    printf("Please enter a positive integer: ");
    scanf("%d", &n);

    // formula to calculate sum of first n natural numbers: (n * (n+1)) / 2
    sum = (n * (n + 1)) / 2;

    printf("The sum of the first %d natural numbers is: %d", n, sum);

    return 0;
}