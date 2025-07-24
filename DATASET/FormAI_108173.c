//FormAI DATASET v1.0 Category: Recursive ; Style: accurate
#include <stdio.h>

int recursiveFactorial(int n);

int main() {
    int num;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    if(num < 0) {
        printf("Error! Factorial of a negative number doesn't exist.");
    } else {
        printf("Factorial of %d = %d", num, recursiveFactorial(num));
    }

    return 0;
}

int recursiveFactorial(int n) {
    if(n == 0) {
        return 1;
    } else {
        return n * recursiveFactorial(n-1);
    }
}