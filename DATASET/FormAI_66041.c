//FormAI DATASET v1.0 Category: Recursive ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int factorial(int num);

int main() {
    int num, fact;
    printf("Enter a number: ");
    scanf("%d", &num);
    fact = factorial(num);
    printf("Factorial of %d is %d", num, fact);
    return 0;
}

int factorial(int num) {
    if(num == 0) {
        return 1;
    }
    return num * factorial(num - 1);
}