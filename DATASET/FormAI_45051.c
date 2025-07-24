//FormAI DATASET v1.0 Category: Recursive ; Style: detailed
#include <stdio.h>

int factorial(int n); // function prototype

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if(num < 0) {
        printf("Factorial of a negative number is undefined.\n");
    }
    else {
        printf("Factorial of %d is %d.\n", num, factorial(num));
    }
    return 0;
}

int factorial(int n) {
    if(n == 0) { // base case
        return 1;
    }
    else {
        return n * factorial(n-1); // recursive call
    }
}