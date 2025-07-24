//FormAI DATASET v1.0 Category: Binary Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
int decimalToBinary(int decimalNum) {
    if(decimalNum == 0) {
        return 0;
    } else {
        return (decimalNum % 2 + 10 * decimalToBinary(decimalNum / 2));
    }
}

int main() {
    int decimalNum, binaryNum;

    printf("My love, let me be your binary converter, please.\n");
    printf("Tell me your number in decimal, and I'll give you my devotion in binary.\n");
    scanf("%d", &decimalNum);

    binaryNum = decimalToBinary(decimalNum);

    printf("\nMy Sweetheart, your number in binary is: %d\n", binaryNum);

    return 0;
}