//FormAI DATASET v1.0 Category: Binary Converter ; Style: multivariable
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int decimalNum;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);

    int binaryDigits[32];
    int tempDecimal = decimalNum;
    int i = 0;

    while (tempDecimal > 0) {
        binaryDigits[i] = tempDecimal % 2;
        tempDecimal /= 2;
        i++;
    }

    printf("\nBinary number of %d is: ", decimalNum);
    bool trailingZero = true;
    for (int j = i - 1; j >= 0; j--) {
        if (binaryDigits[j] == 1) {
            trailingZero = false;
        }

        if (trailingZero && j == 0) {
            printf("0");
        } else {
            printf("%d", binaryDigits[j]);
        }
    }

    printf("\n");

    return 0;
}