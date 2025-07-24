//FormAI DATASET v1.0 Category: Recursive ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Recursive function to calculate the factorial of a number
int factorial(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int num = 5;
    printf("The factorial of %d is %d\n", num, factorial(num));
    return 0;
}