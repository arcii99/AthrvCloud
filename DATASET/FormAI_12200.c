//FormAI DATASET v1.0 Category: Recursive ; Style: Ada Lovelace
#include <stdio.h>

int factorial(int num);

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("Factorial of %d is: %d\n", num, factorial(num));
    return 0;
}

int factorial(int num) {
    if(num == 0 || num == 1) // base case
        return 1;
    else // recursive case
        return num * factorial(num-1);
}