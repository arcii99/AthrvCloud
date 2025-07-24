//FormAI DATASET v1.0 Category: Recursive ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Simple recursive function to calculate the factorial of a given number
int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int num;
    printf("Enter a number to calculate factorial: ");
    scanf("%d", &num);

    // Validate the user input
    if(num < 0) {
        printf("Invalid input! The number must be non-negative.\n");
        return 1;
    }

    // Call the recursive function
    printf("%d! = %d\n", num, factorial(num));

    return 0;
}