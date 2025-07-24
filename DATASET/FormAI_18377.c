//FormAI DATASET v1.0 Category: Educational ; Style: expert-level
#include <stdio.h>

// function to calculate the factorial of a number
int factorial(int num) {
    int res = 1;
    for(int i = 1; i <= num; i++) {
        res *= i;
    }
    return res;
}

int main() {
    int n, m;
    printf("Enter two numbers: ");
    scanf("%d %d", &n, &m);

    // calculate the binomial coefficient of n and m
    int binom = factorial(n) / (factorial(n - m) * factorial(m));
    printf("The binomial coefficient of %d and %d is %d", n, m, binom);

    return 0;
}