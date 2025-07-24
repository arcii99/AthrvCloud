//FormAI DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>

int main() {
    int a = 8, b = 12;

    // Perform AND operation
    int c = a & b;
    printf("%d AND %d = %d\n", a, b, c);

    // Perform OR operation
    int d = a | b;
    printf("%d OR %d = %d\n", a, b, d);

    // Perform XOR operation
    int e = a ^ b;
    printf("%d XOR %d = %d\n", a, b, e);

    // Perform left-shift operation
    int f = a << 2;
    printf("%d left-shifted by 2 = %d\n", a, f);

    // Perform right-shift operation
    int g = b >> 2;
    printf("%d right-shifted by 2 = %d\n", b, g);

    // Perform NOT operation
    int h = ~a;
    printf("NOT %d = %d\n", a, h);
    
    return 0;
}