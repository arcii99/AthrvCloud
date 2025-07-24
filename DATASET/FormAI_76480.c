//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Linus Torvalds
#include <stdio.h>

#define BOLD "\033[1m"
#define RED "\033[31m"
#define RESET "\033[0m"

/* Bitwise operations example program */

int main() {
    int x = 159; // Initial value
    int y = 327; // Second value

    printf(BOLD "Original Values:\n" RESET);
    printf("x: %d\n", x);
    printf("y: %d\n", y);

    x = x ^ y; // XOR operation between x and y
    y = x ^ y; // XOR operation between x and y (since x is now x^y)
    x = x ^ y; // XOR operation between x and y (since y is now x^y)

    printf(BOLD "\nValues after XOR:\n" RESET);
    printf("x: %d\n", x);
    printf("y: %d\n", y);

    x = x | y; // OR operation between x and y
    y = x & y; // AND operation between x and y
    x = x & y; // AND operation between x and y (since y is now x&y)

    printf(BOLD "\nValues after OR AND:\n" RESET);
    printf("x: %d\n", x);
    printf("y: %d\n", y);

    x = ~x; // NOT operation on x
    y = ~y; // NOT operation on y

    printf(BOLD "\nValues after NOT:\n" RESET);
    printf("x: %d\n", x);
    printf("y: %d\n", y);

    return 0;
}