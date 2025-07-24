//FormAI DATASET v1.0 Category: Recursive ; Style: intelligent
// This is a program to calculate the factorial of a number using recursion

#include <stdio.h>

int factorial(int num);

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("The factorial of %d is %d\n", num, factorial(num));
    return 0;
}

int factorial(int num) {
    if (num <= 1) { // base case
        return 1;
    }
    else { // recursive case
        return num * factorial(num-1);
    }
}