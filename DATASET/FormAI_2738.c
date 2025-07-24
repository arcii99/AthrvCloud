//FormAI DATASET v1.0 Category: Recursive ; Style: grateful
#include <stdio.h>

// function prototype
int calcFactorial(int num);

int main() {
    int number, factorial;

    // get user input
    printf("Welcome! Let's calculate the factorial of a number. Enter a positive integer: ");
    scanf("%d", &number);

    // calculate factorial using recursion 
    factorial = calcFactorial(number);

    // display result
    printf("\nFactorial of %d is %d\n", number, factorial);

    printf("\nThank you! Have a fantastic day!");

    return 0;
}

// recursive function to calculate factorial
int calcFactorial(int num) {
    // base case
    if (num == 0) {
        return 1;
    } else {
        // recursive call
        return num * calcFactorial(num - 1);
    }
}