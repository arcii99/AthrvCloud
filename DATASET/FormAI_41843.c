//FormAI DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>

long int recursive_factorial(int n) {
    if (n == 0) {
        return 1;   // base case
    }
    else {
        return n * recursive_factorial(n - 1);   // recursive call
    }
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Factorial of negative number doesn't exist.\n");
    }
    else {
        long int result = recursive_factorial(num);
        printf("The factorial of %d is %ld.\n", num, result);
    }
    return 0;
}