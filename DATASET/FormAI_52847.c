//FormAI DATASET v1.0 Category: Recursive ; Style: mathematical
#include <stdio.h>

int factorial(int n) {
    if(n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if(num < 0) {
        printf("Factorial of negative number is not defined.\n");
    } else {
        printf("Factorial of %d is %d\n", num, factorial(num));
    }

    return 0;
}