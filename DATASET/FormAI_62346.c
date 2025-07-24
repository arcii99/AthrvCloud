//FormAI DATASET v1.0 Category: Educational ; Style: optimized
#include <stdio.h>

// Function to calculate the factorial of a number
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    while (n > 0) {
        result *= n--;
    }
    return result;
}

// Function to calculate the sum of all factorials from 1 to n
unsigned long long sumOfFactorials(int n) {
    unsigned long long result = 0;
    for (int i = 1; i <= n; i++) {
        result += factorial(i);
    }
    return result;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    unsigned long long sum = sumOfFactorials(n);

    printf("The sum of all factorials from 1 to %d is: %llu\n", n, sum);
    return 0;
}