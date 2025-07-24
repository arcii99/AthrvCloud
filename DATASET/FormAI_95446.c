//FormAI DATASET v1.0 Category: Recursive ; Style: beginner-friendly
#include <stdio.h>

int recursiveSum(int n); // function declaration

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Sum of first %d natural numbers = %d\n", n, recursiveSum(n));
    return 0;
}

int recursiveSum(int n) {
    if (n == 0) { //base case
        return 0;
    } else {
        return n + recursiveSum(n-1); //recursive case
    }
}