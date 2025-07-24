//FormAI DATASET v1.0 Category: Recursive ; Style: real-life
#include <stdio.h>

long factorial(int n); // Recursive function prototype

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    // Check if input is valid
    if(num < 0) {
        printf("Error! Factorial of a negative number doesn't exist.");
    }
    else {
        long fact = factorial(num); // Call recursive function
        printf("Factorial of %d = %ld", num, fact);
    }

    return 0;
}

// Recursive function to calculate factorial
long factorial(int n) {
    if(n == 0) {
        return 1; // Base case
    }
    else {
        return n * factorial(n-1); // Recursive case
    }
}