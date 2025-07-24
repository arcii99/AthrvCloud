//FormAI DATASET v1.0 Category: Bitwise operations ; Style: puzzling
#include <stdio.h>

int main() {
    int x = 13;
    int y = 23;
    
    // Left shift by 2
    printf("Left shift by 2\n");
    printf("%d << 2 = %d\n\n", x, (x<<2));
    printf("%d << 2 = %d\n\n", y, (y<<2));

    // Bitwise AND operator
    printf("Bitwise AND operator\n");
    printf("x & y = %d\n\n", (x & y));

    // Bitwise OR operator
    printf("Bitwise OR operator\n");
    printf("x | y = %d\n\n", (x | y));

    // Bitwise NOT operator
    printf("Bitwise NOT operator\n");
    printf("~x = %d\n", (~x));
    printf("~y = %d\n\n", (~y));

    // Right shift by 2
    printf("Right shift by 2\n");
    printf("%d >> 2 = %d\n\n", x, (x>>2));
    printf("%d >> 2 = %d\n\n", y, (y>>2));

    // XOR operation
    printf("XOR operation\n");
    printf("%d ^ %d = %d\n\n", x, y, (x^y));

    // Two's complement
    printf("Two's complement\n");
    printf("~%d + 1 = %d\n\n", x, (~x+1));
    printf("~%d + 1 = %d\n\n", y, (~y+1));
    
    return 0;
}