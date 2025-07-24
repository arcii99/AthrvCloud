//FormAI DATASET v1.0 Category: Binary Converter ; Style: lively
#include <stdio.h>

void convertToBinary(int decimalNum) {
    if (decimalNum == 0) {
        return;
    } else {
        convertToBinary(decimalNum / 2);
        printf("%d", decimalNum % 2);
    }
}

int main() {
    int decimalNum;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);
    printf("The binary representation of %d is: ", decimalNum);
    convertToBinary(decimalNum);
    printf("\n");
    return 0;
}