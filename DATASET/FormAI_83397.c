//FormAI DATASET v1.0 Category: Recursive ; Style: expert-level
#include <stdio.h>

int factorial(int n);

int main() {
    int number, answer;

    printf("Please enter a positive integer: ");
    scanf("%d", &number);

    if(number < 0)
        printf("Sorry, factorial of negative numbers is undefined.\n");
    else {
        answer = factorial(number);
        printf("Factorial of %d is %d\n", number, answer);
    }

    return 0;
}

int factorial(int n) {
    if(n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}