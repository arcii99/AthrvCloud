//FormAI DATASET v1.0 Category: Recursive ; Style: single-threaded
#include<stdio.h>

// Recursive function to find the factorial of a number
int factorial(int n) {
    if(n<=1)
        return 1;
    else
        return n * factorial(n-1);
}

int main() {
    int num, fact;

    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);

    fact = factorial(num);

    printf("The factorial of %d is: %d", num, fact);

    return 0;
}