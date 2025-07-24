//FormAI DATASET v1.0 Category: Recursive ; Style: interoperable
#include <stdio.h>

// Defining the recursive function
int factorial(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1); // recursive call to factorial function
    }
}

// Main function to test the recursive function
int main() {
    int num;
    
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);
    
    // Checking if the number is negative
    if(num < 0) {
        printf("Error! Factorial of a negative number doesn't exist.\n");
    }
    else {
        int fact = factorial(num); // calling the recursive function
        printf("Factorial of %d = %d\n", num, fact);
    }
    
    return 0;
}