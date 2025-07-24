//FormAI DATASET v1.0 Category: Educational ; Style: authentic
#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check if the number is valid or not
    if (num < 0) {
        printf("Error: Cannot calculate factorial of negative number.\n");
    } else if (num == 0) {
        printf("Factorial of 0 is 1.\n");
    } else {
        int fact = factorial(num);
        printf("Factorial of %d is %d.\n", num, fact);
    }
    return 0;
}