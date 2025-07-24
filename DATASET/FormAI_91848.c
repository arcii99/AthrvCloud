//FormAI DATASET v1.0 Category: Recursive ; Style: Ada Lovelace
/* Ada Lovelace Style Recursive C Program */
#include<stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int num;
    printf("Hello World! Let's calculate the factorial of a number.\n");
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if(num < 0) {
        printf("Error: Please enter a positive integer.\n");
    } else {
        printf("The factorial of %d is %d.\n", num, factorial(num));
    }
    return 0;
}