//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include <stdio.h>

void printBinary(unsigned int num) {
    if (num > 1) {
        printBinary(num / 2);
    }
    printf("%d", num % 2);
}

int main() {
    unsigned int a = 42;
    unsigned int b = 27;
    unsigned int c = ~a;
    unsigned int d = a | b;
    unsigned int e = a & b;
    unsigned int f = a ^ b;
    unsigned int g = a << 2;
    unsigned int h = b >> 3;

    printf("a = %d in binary form is: ", a);
    printBinary(a);
    printf("\n");

    printf("b = %d in binary form is: ", b);
    printBinary(b);
    printf("\n");

    printf("~a = %d in binary form is: ", c);
    printBinary(c);
    printf("\n");

    printf("a | b = %d in binary form is: ", d);
    printBinary(d);
    printf("\n");

    printf("a & b = %d in binary form is: ", e);
    printBinary(e);
    printf("\n");

    printf("a ^ b = %d in binary form is: ", f);
    printBinary(f);
    printf("\n");

    printf("a << 2 = %d in binary form is: ", g);
    printBinary(g);
    printf("\n");

    printf("b >> 3 = %d in binary form is: ", h);
    printBinary(h);
    printf("\n");

    return 0;
}