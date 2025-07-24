//FormAI DATASET v1.0 Category: Recursive ; Style: accurate
#include <stdio.h>

int factorial(int n);

int main() {
    int n;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &n);
    if(n<0) {
        printf("Factorial of negative number is not possible.");
        return 0;
    }
    printf("Factorial of %d is %d", n, factorial(n));
    return 0;
}

int factorial(int n) {
    if(n==1 || n==0) {
        return 1;
    }
    return n * factorial(n-1);
}