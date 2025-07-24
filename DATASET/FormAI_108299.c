//FormAI DATASET v1.0 Category: Recursive ; Style: real-life
#include <stdio.h>

// function to calculate the factorial recursively
int factorial(int n) {
    if(n == 0) { // base case
        return 1;
    } else { // recursive step
        return n * factorial(n-1);
    }
}

int main() {
    int num;

    // asking for user input
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);

    // calling the recursive function
    int result = factorial(num);

    // printing the result
    printf("The factorial of %d is %d\n", num, result);

    return 0;
}