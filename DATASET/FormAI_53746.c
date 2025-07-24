//FormAI DATASET v1.0 Category: Recursive ; Style: satisfied
#include <stdio.h>

int factorial(int num);

int main() {
    int num, fact;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if(num < 0) {
        printf("Error: Please enter a positive integer.");
        return 1;
    }

    fact = factorial(num);
    printf("Factorial of %d is %d", num, fact);

    return 0;
}

int factorial(int num) {
    if(num == 0) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}