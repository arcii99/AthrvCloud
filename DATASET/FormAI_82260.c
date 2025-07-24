//FormAI DATASET v1.0 Category: Bitwise operations ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Welcome to the Bitwise Funhouse!\n");
    printf("We're going to play with some operators,\n");
    printf("So let's get started without any waiters!\n");

    int num1 = 23; //011101
    int num2 = 18; //010010

    int bitwiseAnd = num1 & num2;
    int bitwiseOr = num1 | num2;
    int bitwiseXor = num1 ^ num2;

    printf("\nFirst number is 23 (011101 in binary)\n");
    printf("Second number is 18 (010010 in binary)\n\n");

    printf("Let's try the bitwise AND operator (&)\n");
    printf("011101 & 010010 = %d (010000 in binary)\n\n", bitwiseAnd);

    printf("Now let's try the bitwise OR operator (|)\n");
    printf("011101 | 010010 = %d (011111 in binary)\n\n", bitwiseOr);

    printf("Finally, let's try the bitwise XOR operator (^)\n");
    printf("011101 ^ 010010 = %d (001111 in binary)\n\n", bitwiseXor);

    printf("Wasn't that fun? Thanks for playing!\n");

    return 0;
}