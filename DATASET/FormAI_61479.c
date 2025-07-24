//FormAI DATASET v1.0 Category: Arithmetic ; Style: shape shifting
#include <stdio.h>

int main() {
    int a = 5;
    float b = 2.5;
    double c = 0.8;
    char d = 'A';
    unsigned int e = 10;
    signed long int f = -12345;
    short int g = 32767;

    printf("Initial values:\n");
    printf("a = %d\n", a);
    printf("b = %f\n", b);
    printf("c = %lf\n", c);
    printf("d = %c\n", d);
    printf("e = %u\n", e);
    printf("f = %ld\n", f);
    printf("g = %hd\n", g);

    printf("\nShapeshifting time!\n");

    a += 5;
    b *= 2;
    c /= 4;
    d += 32;
    e -= 5;
    f *= -1;
    g <<= 1;

    printf("New values:\n");
    printf("a = %d\n", a);
    printf("b = %f\n", b);
    printf("c = %lf\n", c);
    printf("d = %c\n", d);
    printf("e = %u\n", e);
    printf("f = %ld\n", f);
    printf("g = %hd\n", g);

    return 0;
}