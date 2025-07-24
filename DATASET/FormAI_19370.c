//FormAI DATASET v1.0 Category: Arithmetic ; Style: modular
#include<stdio.h>

/* Modular approach for calculating the factorial of a number */

int factorial(int num) { // function to calculate factorial
    int i, fact = 1;
    for(i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n, result;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    if(n < 0) {
        printf("Negative numbers are not allowed!\n");
        return 0;
    }
    
    result = factorial(n); // calling the function to calculate factorial
    printf("The factorial of %d is %d.\n", n, result);
    
    return 0;
}