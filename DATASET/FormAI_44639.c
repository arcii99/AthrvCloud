//FormAI DATASET v1.0 Category: Recursive ; Style: detailed
#include <stdio.h>

int factorial(int n);

int main() {
    int num;
    printf("Enter a positive integer to find factorial: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Factorial of negative numbers is not defined!");
        return 0;
    }
    printf("Factorial of %d is %d", num, factorial(num));
    return 0;
}

int factorial(int n) {
    if (n == 0)
       return 1;
    else
       return(n * factorial(n-1));
}