//FormAI DATASET v1.0 Category: Recursive ; Style: Linus Torvalds
#include <stdio.h>

int factorial(int n) {
    if (n == 1) { // base case
        return 1;
    } else {
        return n * factorial(n-1); // recursive call
    }
}

int main() {
    int n = 5;
    int result = factorial(n);
    printf("%d! = %d\n", n, result);
    return 0;
}