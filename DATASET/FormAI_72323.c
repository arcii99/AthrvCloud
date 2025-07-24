//FormAI DATASET v1.0 Category: Color Code Converter ; Style: minimalist
#include <stdio.h>

int main() {
    char c;
    int n, r, g, b;

    printf("Enter a character: ");
    scanf("%c", &c);
    printf("The ASCII value of %c is %d\n", c, c);

    printf("\nEnter a color code in hexadecimal format (R G B): ");
    scanf("%2x %2x %2x", &r, &g, &b);

    printf("The equivalent RGB color values are (%d, %d, %d)\n", r, g, b);
    printf("The equivalent HEX code is #%02x%02x%02x\n", r, g, b);

    printf("\nEnter a color code in RGB format (R G B): ");
    scanf("%d %d %d", &r, &g, &b);

    printf("The equivalent HEX code is #%02x%02x%02x\n", r, g, b);

    printf("\nEnter a color code in decimal format (0-255, 0-255, 0-255): ");
    scanf("%d %d %d", &r, &g, &b);

    printf("The equivalent HEX code is #%02x%02x%02x\n", r, g, b);

    printf("\nEnter a number to convert to binary: ");
    scanf("%d", &n);

    printf("%d in binary is ", n);
    for (int i = 31; i >= 0; i--) {
        if (n >> i & 1)
            printf("1");
        else
            printf("0");
    }

    return 0;
}