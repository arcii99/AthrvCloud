//FormAI DATASET v1.0 Category: Binary Converter ; Style: standalone
#include <stdio.h>
#include <stdbool.h>

int main() {
    long decimal, quotient;
    int binary[100], i = 1, j;

    printf("Enter a decimal number: ");
    scanf("%ld", &decimal);

    quotient = decimal;

    while (quotient != 0) {
        binary[i++] = quotient % 2;
        quotient /= 2;
    }

    printf("The binary equivalent of %ld is: ", decimal);

    for (j = i - 1; j > 0; j--) {
        printf("%d", binary[j]);
    }

    printf("\n");

    return 0;
}