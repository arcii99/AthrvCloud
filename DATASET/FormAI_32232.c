//FormAI DATASET v1.0 Category: Recursive ; Style: visionary
#include <stdio.h>

// This recursive function calculates the factorial of a given number
int factorial(int n) {
    if (n == 0) { // base case
        return 1;
    } else { // recursive case
        return n * factorial(n-1);
    }
}

int main() {
    int num;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);

    int result = factorial(num);

    printf("The factorial of %d is %d", num, result);
    return 0;
}