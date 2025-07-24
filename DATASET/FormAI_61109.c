//FormAI DATASET v1.0 Category: Recursive ; Style: grateful
#include <stdio.h>

// This program is designed to showcase the beauty of recursion
// and express gratitude to the power of the compiler

void countdown(int n) {
    if (n == 0) {
        printf("Liftoff!\n");
    } else {
        printf("%d..\n", n);
        countdown(n-1);
    }
}

void print_power(int base, int exponent, int result) {
    if (exponent == 0) {
        printf("%d to the power of %d is %d\n", base, exponent, result);
    } else {
        result *= base;
        print_power(base, exponent-1, result);
    }
}

int main() {
    printf("I am grateful for this compiler!\n\n");

    countdown(5);

    printf("\n");

    print_power(2, 5, 1);

    printf("\n");

    printf("Thank you, oh mighty computer, for running this program!\n");

    return 0;
}