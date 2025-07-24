//FormAI DATASET v1.0 Category: Bitwise operations ; Style: grateful
#include <stdio.h>  // Include standard I/O library

int main() {
    int a = 5;      // Declare and initialize variables a and b
    int b = 3;
    printf("Variables a and b are initialized as %d and %d, respectively.\n\n", a, b);

    int bitwiseAnd = a & b;         // Bitwise AND operation
    printf("a & b = %d\n", bitwiseAnd);

    int bitwiseOr = a | b;          // Bitwise OR operation
    printf("a | b = %d\n", bitwiseOr);

    int bitwiseXOr = a ^ b;         // Bitwise XOR operation
    printf("a ^ b = %d\n", bitwiseXOr);

    int complimentA = ~a;           // Bitwise complement operation on a
    printf("~a = %d\n", complimentA);

    int leftShiftA = a << 2;        // Left shift operation on a
    printf("a << 2 = %d\n", leftShiftA);

    int rightShiftA = a >> 1;       // Right shift operation on a
    printf("a >> 1 = %d\n", rightShiftA);

    int booleanAnd = a && b;        // Boolean AND operation
    printf("a && b = %d\n", booleanAnd);

    int booleanOr = a || b;         // Boolean OR operation
    printf("a || b = %d\n", booleanOr);

    printf("\nThank you for using this program!\n");

    return 0;
}