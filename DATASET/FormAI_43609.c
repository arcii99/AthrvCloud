//FormAI DATASET v1.0 Category: Binary Converter ; Style: configurable
#include <stdio.h>

int main() {
    int numToConvert, base, convertedNum[100], result = 0, i = 0;
    printf("Enter a number to convert: ");
    scanf("%d", &numToConvert);
    printf("Enter the base (2-16): ");
    scanf("%d", &base);
    while (numToConvert != 0) {
        convertedNum[i] = numToConvert % base;
        numToConvert /= base;
        i++;
    }
    printf("The converted number is: ");
    for (int j = i - 1; j >= 0; j--) {
        if (convertedNum[j] >= 10) {
            printf("%c", convertedNum[j] + 55);
            result += ((convertedNum[j] + 55) * pow(base, j));
        } else {
            printf("%d", convertedNum[j]);
            result += (convertedNum[j] * pow(base, j));
        }
    }
    printf("\n");
    printf("Decimal equivalent: %d", result);
    return 0;
}