//FormAI DATASET v1.0 Category: Bitwise operations ; Style: funny
#include <stdio.h>

int main() {
    printf("Are you ready for some bitwise magic?! Let's go!\n\n");
    
    int a = 7;
    int b = 5;

    printf("a = %d\n", a);
    printf("b = %d\n\n", b);

    int c = a & b;
    printf("a & b = %d, which is 0111 & 0101 = 0101\n", c);

    c = a | b;
    printf("a | b = %d, which is 0111 | 0101 = 0111\n", c);

    c = a ^ b;
    printf("a ^ b = %d, which is 0111 ^ 0101 = 0010\n", c);

    c = ~a;
    printf("~a = %d, which is ~0111 = 1000\n", c);

    c = b << 1;
    printf("b << 1 = %d, which is 0101 << 1 = 1010\n", c);

    c = a >> 1;
    printf("a >> 1 = %d, which is 0111 >> 1 = 0011\n", c);

    printf("\nWoohoo! That was some seriously awesome bitwise fun!\n");

    return 0;
}