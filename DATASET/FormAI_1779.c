//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    char hex[100];
    int i = 0;

    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10)
            hex[i++] = remainder + 48; // 0-9
        else
            hex[i++] = remainder + 55; // A-F
        decimal /= 16;
    }
    hex[i] = '\0';

    printf("Hexadecimal number: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);
    printf("\n");

    return 0;
}