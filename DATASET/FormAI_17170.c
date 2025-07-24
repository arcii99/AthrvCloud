//FormAI DATASET v1.0 Category: Recursive ; Style: statistical
#include <stdio.h>

int factorial(int n);

int main() {
    int n = 5;
    int result = factorial(n);
    printf("%d! = %d\n", n, result);
    return 0;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}