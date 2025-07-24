//FormAI DATASET v1.0 Category: Bitwise operations ; Style: energetic
#include <stdio.h>
#include <stdbool.h>

// This is a simple program that demonstrates bitwise operations in C
// In this program, we'll use bitwise AND, OR, NOT, and XOR operators

int main() {

    printf("=============== WELCOME TO OUR BITWISE OPERATIONS PROGRAM ===============\n\n");

    int a = 10;
    int b = 5;
    int c;

    printf("OPERATIONS:\n");
    printf("a = %d, b = %d\n", a, b);

    // AND operation
    c = a & b;
    printf("a & b = %d\n", c);

    // OR operation
    c = a | b;
    printf("a | b = %d\n", c);

    // NOT operation
    c = ~a;
    printf("~%d = %d\n", a, c);

    // XOR operation
    c = a ^ b;
    printf("a ^ b = %d\n", c);

    // Checking if a number is even or odd using bitwise AND
    int num = 15;
    bool is_even = (num & 1) == 0;
    printf("%d is %s\n", num, is_even ? "even" : "odd");

    printf("=============== THANK YOU FOR USING OUR PROGRAM! ===============\n\n");

    return 0;
}