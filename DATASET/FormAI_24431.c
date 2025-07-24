//FormAI DATASET v1.0 Category: Recursive ; Style: portable
/*
 * This is a program that utilizes recursive function calls to find the factorial of a given number.
 * The user is prompted to input a non-negative integer and the program uses recursion to calculate its factorial value.
 * This program is written in portable style, meaning it is written to be platform-independent. 
 */

#include <stdio.h>

// Define prototype of recursive function
int find_factorial(int num);

int main() {
    int num;

    // Prompt user to input number
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    if (num < 0) {
        // Negative integer input
        printf("Factorial cannot be found for negative integers.\n");
    } else {
        // Call recursive function to find factorial
        int fact = find_factorial(num);
        printf("%d! is %d\n", num, fact);
    }

    return 0;
}

int find_factorial(int num) {
    if (num == 0) {
        // Base case: factorial of 0 is 1
        return 1;
    } else {
        // Recursive case: factorial of n is n * (n-1)!
        return num * find_factorial(num - 1);
    }
}