//FormAI DATASET v1.0 Category: Recursive ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

int factorial(int n) {
    if(n < 0) {
        return 0;
    }
    else if(n == 0) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

int main() {
    int x;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &x);
    printf("Factorial of %d is %d", x, factorial(x));
    return 0;
}