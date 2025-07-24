//FormAI DATASET v1.0 Category: Recursive ; Style: thoughtful
#include <stdio.h>

int recursiveSum(int n);

int main() {
    int num;
    printf("Enter a number to find the sum of natural numbers up to that number: ");
    scanf("%d", &num);
    int sum = recursiveSum(num);
    printf("The sum of natural numbers up to %d is: %d", num, sum);
    return 0;
}

int recursiveSum(int n) {
    if (n == 1) { // Base case
        return 1;
    } else { // Recursive case
        int sum = n + recursiveSum(n-1);
        return sum;
    }
}