//FormAI DATASET v1.0 Category: Binary Converter ; Style: Ada Lovelace
#include <stdio.h>

int main() {
    int num, binary[32], i = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    while (num > 0) {
        binary[i++] = num % 2;
        num /= 2;
    }

    printf("Binary number: ");
    for (i = i - 1; i >= 0; i--)
        printf("%d", binary[i]);

    return 0;
}