//FormAI DATASET v1.0 Category: Recursive ; Style: minimalist
#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1; 
    } else {
        return n * factorial(n-1);
    }
}

int main(void) {
    int num = 5;
    printf("Factorial of %d is %d\n", num, factorial(num));
    return 0;
}