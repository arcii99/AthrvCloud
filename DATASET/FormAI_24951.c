//FormAI DATASET v1.0 Category: Bitwise operations ; Style: energetic
#include <stdio.h>

int main() {
    int a = 10;
    int b = 5;
    int result;

    printf("The original value of 'a' is %d\n", a);

    // Left shift operator
    result = a << b;
    printf("After left shifting, 'a' is %d\n", result);

    // Right shift operator
    result = a >> b;
    printf("After right shifting, 'a' is %d\n", result);

    // Bitwise AND operator
    result = a & b;
    printf("'a' AND 'b' is %d\n", result);

    // Bitwise OR operator
    result = a | b;
    printf("'a' OR 'b' is %d\n", result);

    // Bitwise XOR operator
    result = a ^ b;
    printf("'a' XOR 'b' is %d\n", result);

    // Bitwise NOT operator
    result = ~a;
    printf("NOT 'a' is %d\n", result);

    // Bitwise AND assignment operator
    a &= b;
    printf("'a' AND= 'b' is %d\n", a);

    // Bitwise OR assignment operator
    a |= b;
    printf("'a' OR= 'b' is %d\n", a);

    // Bitwise XOR assignment operator
    a ^= b;
    printf("'a' XOR= 'b' is %d\n", a);

    // Bitwise NOT assignment operator
    a = ~a;
    printf("NOT 'a' is %d\n", a);
    
    return 0;
}