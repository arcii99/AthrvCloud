//FormAI DATASET v1.0 Category: Recursive ; Style: careful
#include <stdio.h>

int factorial(int n) {
    if(n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int number;
    printf("Enter a number to find the factorial: ");
    scanf("%d", &number);

    int result = factorial(number);
    printf("The factorial of %d is %d", number, result);

    return 0;
}