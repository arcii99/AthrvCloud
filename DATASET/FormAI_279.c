//FormAI DATASET v1.0 Category: Binary Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    char binary[17];
    int decimal, bits;

    printf("Enter a binary number (up to 16 bits): ");
    scanf("%s", binary);

    for (bits = 0; binary[bits] != '\0'; bits++);
    decimal = 0;

    for (int i = 0; i < bits; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            printf("The entered number is not a binary number!\n");
            exit(0);
        }
        decimal += (binary[i] - '0') * pow(2, bits - i - 1);
    }

    printf("The decimal number of %s is %d", binary, decimal);
    return 0;
}