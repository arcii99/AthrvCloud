//FormAI DATASET v1.0 Category: Bitwise operations ; Style: authentic
#include <stdio.h>

int main() {
    // bitwise AND
    int a = 5; 
    int b = 3;
    int c = a & b;
    printf("Bitwise AND of %d and %d is %d\n", a, b, c);

    // bitwise OR
    a = 5;
    b = 3;
    c = a | b;
    printf("Bitwise OR of %d and %d is %d\n", a, b, c);

    // bitwise XOR
    a = 5;
    b = 3;
    c = a ^ b;
    printf("Bitwise XOR of %d and %d is %d\n", a, b, c);

    // bitwise NOT
    a = 5;
    c = ~a;
    printf("Bitwise NOT of %d is %d\n", a, c);

    // bitwise left shift
    a = 5;
    b = 2;
    c = a << b;
    printf("%d left-shifted by %d bits is %d\n", a, b, c);

    // bitwise right shift
    a = 5;
    b = 2;
    c = a >> b;
    printf("%d right-shifted by %d bits is %d\n", a, b, c);

    return 0;
}