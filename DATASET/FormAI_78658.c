//FormAI DATASET v1.0 Category: Recursive ; Style: modular
#include <stdio.h>

int factorial(int n);

int main() {
    int num = 5;
    int fact = factorial(num);
    printf("Factorial of %d = %d", num, fact);
    return 0;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}