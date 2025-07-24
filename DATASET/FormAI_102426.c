//FormAI DATASET v1.0 Category: Recursive ; Style: synchronous
#include<stdio.h>

int factorial(int num) {
    if(num <= 1) {
        return 1;
    }

    return num * factorial(num-1);
}

int main() {
    int n;
    printf("Please enter a number: ");
    scanf("%d", &n);

    int result = factorial(n);
    printf("The factorial of %d is %d", n, result);

    return 0;
}