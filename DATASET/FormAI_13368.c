//FormAI DATASET v1.0 Category: Arithmetic ; Style: Ada Lovelace
#include <stdio.h>

int main() {
    int a, b, sum, diff, prod, quotient, remainder;
    printf("Welcome to Ada Lovelace's arithmetic calculator!\n");
    printf("Enter two integer values:");
    scanf("%d %d", &a, &b);
    sum = a + b;
    diff = a - b;
    prod = a * b;
    quotient = a / b;
    remainder = a % b;
    printf("Sum(%d, %d) = %d\n", a, b, sum);
    printf("Difference(%d, %d) = %d\n", a, b, diff);
    printf("Product(%d, %d) = %d\n", a, b, prod);
    printf("Quotient(%d, %d) = %d\n", a, b, quotient);
    printf("Remainder(%d, %d) = %d\n", a, b, remainder);
    return 0;
}