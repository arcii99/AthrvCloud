//FormAI DATASET v1.0 Category: Bitwise operations ; Style: excited
#include <stdio.h>

int main() {
    int a = 5, b = 9;

    printf("***** Bitwise Operations Excitement *****\n\n");

    // AND Operation
    printf("Performing AND operation...\n");
    int andResult = a & b;
    printf("The result of %d AND %d is %d.\n\n", a, b, andResult);

    // OR Operation
    printf("Performing OR operation...\n");
    int orResult = a | b;
    printf("The result of %d OR %d is %d.\n\n", a, b, orResult);

    // XOR Operation
    printf("Performing XOR operation...\n");
    int xorResult = a ^ b;
    printf("The result of %d XOR %d is %d.\n\n", a, b, xorResult);

    // NOT Operation
    printf("Performing NOT operation on %d...\n", a);
    int notResult = ~a;
    printf("The result of NOT %d is %d.\n\n", a, notResult);

    // Left Shift Operation
    printf("Performing Left Shift operation on %d...\n", b);
    int leftShiftResult = b << 2;
    printf("The result of %d Left Shifted by 2 is %d.\n\n", b, leftShiftResult);

    // Right Shift Operation
    printf("Performing Right Shift operation on %d...\n", b);
    int rightShiftResult = b >> 2;
    printf("The result of %d Right Shifted by 2 is %d.\n\n", b, rightShiftResult);

    // Bitwise AND Assignment Operation
    printf("Performing Bitwise AND Assignment operation between %d and %d...\n", a, b);
    a &= b;
    printf("The value of a after performing Bitwise AND Assignment is %d.\n\n", a);

    // Bitwise OR Assignment Operation
    printf("Performing Bitwise OR Assignment operation between %d and %d...\n", a, b);
    a |= b;
    printf("The value of a after performing Bitwise OR Assignment is %d.\n\n", a);

    // Bitwise XOR Assignment Operation
    printf("Performing Bitwise XOR Assignment operation between %d and %d...\n", a, b);
    a ^= b;
    printf("The value of a after performing Bitwise XOR Assignment is %d.\n\n", a);

    // Bitwise NOT Assignment Operation
    printf("Performing Bitwise NOT Assignment operation on %d...\n", a);
    a = ~a;
    printf("The value of a after performing Bitwise NOT Assignment is %d.\n\n", a);
    
    printf("***** End of Bitwise Operations Excitement *****\n");

    return 0;
}