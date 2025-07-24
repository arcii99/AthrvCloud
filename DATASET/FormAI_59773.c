//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: romantic
#include <stdio.h>

unsigned long long factorial(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

int main() {
    unsigned int number = 5;  // can be replaced with user input or any other value
    unsigned long long result = factorial(number);

    printf("The factorial of %u is: %llu\n", number, result);

    return 0;
}