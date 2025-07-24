//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include<stdio.h>

int main(){
    int a = 3; //binary 011
    int b = 5; //binary 101

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    int c = a & b; //perform bitwise AND operation
    printf("a & b = %d (binary %d)\n", c, c);

    int d = a | b; //perform bitwise OR operation
    printf("a | b = %d (binary %d)\n", d, d);

    int e = a ^ b; //perform bitwise XOR operation
    printf("a ^ b = %d (binary %d)\n", e, e);

    int f = ~a; //perform bitwise NOT operation
    printf("~a = %d (binary %d)\n", f, f);

    int g = b << 2; //perform left shift operation
    printf("b << 2 = %d (binary %d)\n", g, g);

    int h = b >> 1; //perform right shift operation
    printf("b >> 1 = %d (binary %d)\n", h, h);

    return 0;
}