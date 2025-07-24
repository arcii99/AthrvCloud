//FormAI DATASET v1.0 Category: Recursive ; Style: protected
#include <stdio.h>

// This function is used to prompt the user for the number of times they want to perform a certain operation
// It returns a positive integer value that is greater than zero
int promptPositiveInteger() {
    int num;
    do {
        printf("Please enter a positive integer: ");
        scanf("%d", &num);
    } while (num <= 0);
    return num;
}

// This function is used to perform a calculation of the Fibonacci sequence using recursion
// It takes in a positive integer value as a parameter and returns the calculated Fibonacci value
int fibonacci(int num) {
    if (num == 1 || num == 2) {
        return 1;
    }
    return fibonacci(num-1) + fibonacci(num-2);
}

int main() {
    int num = promptPositiveInteger();
    printf("The %dth number in the Fibonacci sequence is: %d\n", num, fibonacci(num));
    return 0;
}