//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: inquisitive
#include <stdio.h>

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    char hex[50];
    int i = 0;

    while (decimal > 0) {
        int digit = decimal % 16;

        if (digit < 10) {
            hex[i++] = digit + '0';
        } else {
            hex[i++] = digit + 'A' - 10;
        }

        decimal /= 16;
    }

    printf("Hexadecimal value: ");
    for (int j = i-1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");

    return 0;
}