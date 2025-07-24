//FormAI DATASET v1.0 Category: Recursive ; Style: shape shifting
#include <stdio.h>

// Recursive function to compute the factorial of a number
int factorial(int num) {
    if (num == 1 || num == 0) {  // base case for recursion
        return 1;
    } else {
        return num * factorial(num - 1);  // recursive call
    }
}

int main() {
    int num;
    printf("Enter a non-negative number: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Invalid input! Number must be non-negative.\n");
    } else {
        int result = factorial(num);
        printf("The factorial of %d is %d\n", num, result);
    }
    return 0;
}