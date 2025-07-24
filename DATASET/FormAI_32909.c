//FormAI DATASET v1.0 Category: Recursive ; Style: statistical
/* Recursive example program for factorial calculation */
#include <stdio.h>

int factorial(int num) {
    if(num == 0) {
        return 1;
    }
    else {
        return num * factorial(num - 1); // Recursive call to factorial function
    }
}

int main() {
    int num;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);
    if(num < 0) { // Check for negative input
        printf("Factorial cannot be found for negative numbers\n");
    }
    else {
        int result = factorial(num);
        printf("Factorial of %d is: %d\n", num, result);
    }
    return 0;
}