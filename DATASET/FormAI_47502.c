//FormAI DATASET v1.0 Category: Recursive ; Style: systematic
#include <stdio.h>

int factorial(int n) {     //Recursive function to calculate factorial of a number
    if (n == 0 || n == 1) {  //Base case
        return 1;
    }
    else {
        return n * factorial(n-1);  //Function calls itself
    }
}

int main() {
    int num;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Factorial of negative numbers doesn't exist!");
    }
    else {
        int fact = factorial(num);
        printf("Factorial of %d is %d", num, fact);
    }
    return 0;
}