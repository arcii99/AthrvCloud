//FormAI DATASET v1.0 Category: Binary Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binaryConverter(int decimalNumber) {
    int binaryNumber = 0, remainder, i = 1;

    while(decimalNumber != 0) {
        remainder = decimalNumber%2;
        decimalNumber /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }

    printf("The binary number is %d.\n", binaryNumber);
}


int main() {
    int decimalNumber;

    printf("Enter a decimal number: ");
    scanf("%d",&decimalNumber);

    if(decimalNumber < 0) {
        printf("Invalid input! Enter a positive decimal number.\n");
        main();
    } else {
        binaryConverter(decimalNumber);
    }

    return 0;
}