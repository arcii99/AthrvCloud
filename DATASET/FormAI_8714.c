//FormAI DATASET v1.0 Category: Educational ; Style: real-life
#include <stdio.h>

// Function prototype
int calculateFactorial(int);

int main() {
    int num, fact;

    // User input
    printf("Enter a positive integer to calculate its factorial: ");
    scanf("%d", &num);

    // Check if input is valid
    if (num < 0) {
        printf("Invalid input! Please enter a positive integer.\n");
        return 0;
    }

    // Calculate factorial using a function
    fact = calculateFactorial(num);

    // Display output
    printf("%d! = %d\n", num, fact);

    return 0;
}

// Function definition
int calculateFactorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * calculateFactorial(n-1);
    }
}