//FormAI DATASET v1.0 Category: Recursive ; Style: mind-bending
/* Welcome to the twisted world of recursion */

#include <stdio.h>

int factorial(int n) {
    if(n == 0 || n == 1) {
        return 1; //Base case 1 and 0
    } else if(n % 2 == 0) {
        return n * factorial(n - 2); //Even number case
    } else {
        return n + factorial(n - 1); //Odd number case
    }
}

int main() {
    int num;
    printf("Welcome to the factorial function!\n");
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("The factorial of %d is %d", num, factorial(num));
    return 0;
}