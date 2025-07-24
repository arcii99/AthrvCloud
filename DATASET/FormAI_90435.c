//FormAI DATASET v1.0 Category: Binary Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void binaryConverter(int decimal) {
    int binary[1000], i=0;
    while(decimal > 0) {
        binary[i] = decimal%2;
        decimal = decimal/2;
        i++;
    }
    i--;
    printf("\nBinary of entered decimal is: ");
    while(i >= 0) {
        printf("%d", binary[i]);
        i--;
    }
    printf("\n");
}

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    if(decimal < 0) {
        printf("Invalid input. Decimal number must be non-negative.\n");
        exit(0);
    }
    binaryConverter(decimal);
    return 0;
}