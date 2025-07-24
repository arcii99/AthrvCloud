//FormAI DATASET v1.0 Category: Recursive ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>

int factorial(int n) {
    if (n == 0) {
        printf("0! = 1\n");
        return 1;
    }
    else {
        int result = n * factorial(n-1);
        printf("%d! = %d\n", n, result);
        return result;
    }
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    int result = factorial(number);

    printf("The factorial of %d is: %d\n", number, result);

    return 0;
}