//FormAI DATASET v1.0 Category: Bitwise operations ; Style: retro
#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(int n)
{
    int binary[32];
    int i = 0;

    while (n > 0) {
        binary[i] = n % 2;
        n /= 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
        printf("%d", binary[j]);
}

int main()
{
    int a = 22;
    int b = 11;

    printf("Binary value of %d: ", a);
    decimalToBinary(a);

    printf("\nBinary value of %d: ", b);
    decimalToBinary(b);

    int c = a & b;
    printf("\n\na & b = %d\n", c);

    int d = a | b;
    printf("a | b = %d\n", d);

    int e = ~a;
    printf("~a = %d\n\n", e);

    printf("Binary value of %d: ", c);
    decimalToBinary(c);

    printf("\nBinary value of %d: ", d);
    decimalToBinary(d);

    printf("\nBinary value of ~%d: ", a);
    decimalToBinary(e);

    return 0;
}