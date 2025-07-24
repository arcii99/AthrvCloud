//FormAI DATASET v1.0 Category: Color Code Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, r, g, b;
    printf("Enter a color code: ");
    scanf("%d", &c);

    r = (c >> 16) & 0xff;
    g = (c >> 8) & 0xff;
    b = c & 0xff;

    printf("RGB Color Code: (%d, %d, %d)\n", r, g, b);

    int n = r;
    printf("Hexadecimal Value of Red: %02X\n", n);

    int m = g;
    printf("Hexadecimal Value of Green: %02X\n", m);

    int o = b;
    printf("Hexadecimal Value of Blue: %02X\n", o);

    return 0;
}