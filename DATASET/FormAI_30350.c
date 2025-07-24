//FormAI DATASET v1.0 Category: Bitwise operations ; Style: all-encompassing
#include <stdio.h>

/* Define a function to print the binary representation of a decimal number */
void print_binary(int n) {
    int i, k;
    for (i = 31; i >= 0; i--) {
        k = n >> i;
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
}

int main() {
    /* Declare two variables for bitwise operations */
    unsigned int a = 22;
    unsigned int b = 65;

    printf("a = ");
    print_binary(a);
    printf(" (decimal %d)\n", a);

    printf("b = ");
    print_binary(b);
    printf(" (decimal %d)\n", b);

    /* Perform AND operation between a and b */
    unsigned int c = a & b;
    printf("a & b = ");
    print_binary(c);
    printf(" (decimal %d)\n", c);

    /* Perform OR operation between a and b */
    unsigned int d = a | b;
    printf("a | b = ");
    print_binary(d);
    printf(" (decimal %d)\n", d);

    /* Perform XOR operation between a and b */
    unsigned int e = a ^ b;
    printf("a ^ b = ");
    print_binary(e);
    printf(" (decimal %d)\n", e);

    /* Perform left shift operation on a */
    unsigned int f = a << 3;
    printf("a << 3 = ");
    print_binary(f);
    printf(" (decimal %d)\n", f);

    /* Perform right shift operation on b */
    unsigned int g = b >> 2;
    printf("b >> 2 = ");
    print_binary(g);
    printf(" (decimal %d)\n", g);

    /* Perform bitwise complement operation on a */
    unsigned int h = ~a;
    printf("~a = ");
    print_binary(h);
    printf(" (decimal %d)\n", h);

    return 0;
}