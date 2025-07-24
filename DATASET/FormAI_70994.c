//FormAI DATASET v1.0 Category: Binary Converter ; Style: romantic
#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(int num) {
    int binaryNum[32];
    int i = 0;
    while (num > 0) {
        binaryNum[i] = num % 2;
        num = num / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNum[j]);
}

// Function to convert binary to decimal
int binaryToDecimal(long long num) {
    int decimalNum = 0, base = 1, rem;
    while (num > 0) {
        rem = num % 10;
        num = num / 10;
        decimalNum = decimalNum + rem * base;
        base = base * 2;
    }
    return decimalNum;
}

int main() {
    int decimalNum;
    long long binaryNum;

    printf("Enter decimal number: ");
    scanf("%d", &decimalNum);

    printf("Binary equivalent: ");
    decimalToBinary(decimalNum);

    printf("\n\nEnter binary number: ");
    scanf("%lld", &binaryNum);

    printf("Decimal equivalent: %d", binaryToDecimal(binaryNum));

    return 0;
}