//FormAI DATASET v1.0 Category: Binary Converter ; Style: rigorous
#include <stdio.h>

int main() {
    int num, i;
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    int binary[32];
    for (i = 0; num > 0; i++) {
        binary[i] = num % 2;
        num /= 2;
    }

    printf("Binary representation: ");
    for (i = i - 1; i >= 0; i--)
        printf("%d", binary[i]);
    printf("\n");

    return 0;
}