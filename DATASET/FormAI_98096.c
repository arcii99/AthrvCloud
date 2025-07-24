//FormAI DATASET v1.0 Category: Recursive ; Style: calm
#include <stdio.h>

int recursiveAddition(int n) {
    if (n == 0) // base case
        return 0;
    else
        return n + recursiveAddition(n - 1); // recursive call 
}

int main() {
    int n, sum;
    printf("Enter a number to find the sum of integers from 1 to n: ");
    scanf("%d", &n);
    sum = recursiveAddition(n);
    printf("Sum of integers from 1 to %d is: %d", n, sum);
    return 0;
}