//FormAI DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>

int main() {
    int decimalNum, binaryNum[64];
    int i = 0, j;

    printf("Greetings noble squire! Please enter thy decimal number: ");
    scanf("%d", &decimalNum);

    if (decimalNum < 0) {
        printf("My apologies noble squire, binary conversion does not support negative numbers.\n");
        return 0;
    }

    while (decimalNum > 0) {
        binaryNum[i] = decimalNum % 2;
        decimalNum = decimalNum / 2;
        i++;
    }

    printf("Verily! Thy binary number is: ");
    for (j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
    printf("\nMayhaps it shalt be of use to thee in thy battles!\n");

    return 0;
}