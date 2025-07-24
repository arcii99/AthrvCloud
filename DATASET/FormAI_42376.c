//FormAI DATASET v1.0 Category: Recursive ; Style: satisfied
#include<stdio.h>

int factorial(int n) {
    if (n == 1) { // base case
        return 1;
    } else {
        return n * factorial(n-1); // recursive call
    }
}

int main() {
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Error: Please enter a positive integer");
    } else {
        int result = factorial(num);
        printf("The factorial of %d is %d\n", num, result);
    }

    return 0;
}