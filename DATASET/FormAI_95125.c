//FormAI DATASET v1.0 Category: Educational ; Style: modular
#include <stdio.h>

// Function to calculate the power of a number
int power(int base, int exponent) {
    int result = 1;
    for(int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// Function to calculate the factorial of a number
int factorial(int num) {
    if(num <= 1) {
        return 1;
    }
    return num * factorial(num-1);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int sum = 0, term;
    for(int i = 0; i < n; i++) {
        term = power(i,2)/factorial(i);
        sum += term;
    }

    printf("The sum of first %d terms of the series is %d", n, sum);
    return 0;
}