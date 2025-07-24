//FormAI DATASET v1.0 Category: Computer Biology ; Style: active
#include <stdio.h>

// function for calculating factorial of a number
int factorial(int num) {
    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    // calculating the binomial coefficients using the formula
    // C(n,k) = n! / (k! * (n-k)!)
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            int coeff = factorial(i) / (factorial(j) * factorial(i-j));
            printf("%d ", coeff);
        }
        printf("\n");
    }
    return 0;
}