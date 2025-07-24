//FormAI DATASET v1.0 Category: Recursive ; Style: creative
#include <stdio.h>

int factorial(int n) {
    if(n == 1) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

int main() {
    int num;
    printf("Enter a number to compute its factorial: ");
    scanf("%d", &num);
    if(num < 0) {
        printf("Invalid input! Factorial of negative numbers cannot be computed.\n");
    }
    else {
        int result = factorial(num);
        printf("The factorial of %d is %d\n", num, result);
    }
    return 0;
}