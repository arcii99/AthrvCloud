//FormAI DATASET v1.0 Category: Recursive ; Style: thoughtful
#include <stdio.h>

long long factorial(int n) {
    if(n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n-1);
}

int main() {
    int num;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);

    if(num < 0)
        printf("Factorial of negative number is not possible.");
    else {
        long long result = factorial(num);
        printf("Factorial of %d is %lld", num, result);
    }

    return 0;
}