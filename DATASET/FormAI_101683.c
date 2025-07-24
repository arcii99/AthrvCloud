//FormAI DATASET v1.0 Category: Binary Converter ; Style: authentic
#include <stdio.h>

int main(void) {
    unsigned int decimal;
    int bit, binary[32], i = 0;

    printf("Enter a decimal number: ");
    scanf("%u", &decimal);

    while(decimal > 0) {
        bit = decimal % 2;
        binary[i] = bit;
        decimal = decimal / 2;
        i++;
    }

    printf("Binary number: ");
    for(int j = i-1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");

    return 0;
}