//FormAI DATASET v1.0 Category: Recursive ; Style: realistic
#include <stdio.h>

int factorial(int n) {
    if(n == 0) {
        return 1;
    }
    else if(n < 0) {
        return -1;
    }
    else {
        return n * factorial(n-1);
    }
}

int main() {
    int num;
    printf("Enter a positive number to find its factorial: ");
    scanf("%d", &num);
    int fact = factorial(num);
    if(fact == -1) {
        printf("Factorial of a negative number doesn't exist.\n");
    }
    else {
        printf("The factorial of %d is %d.\n", num, fact);
    }
    return 0;
}