//FormAI DATASET v1.0 Category: Binary Converter ; Style: shape shifting
#include <stdio.h>

void decimalToBinary(int num) { // function to convert decimal to binary
    int binaryNum[32], i = 0;
    while (num > 0) {
        binaryNum[i] = num % 2;
        num = num / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
}

void binaryToDecimal(char *binaryNum) { // function to convert binary to decimal
    int decimalNum = 0, base = 1, len = strlen(binaryNum);
    for (int i = len - 1; i >= 0; i--) {
        if (binaryNum[i] == '1') {
            decimalNum += base;
        }
        base *= 2;
    }
    printf("%d", decimalNum);
}

int main() {
    int num;
    char binaryNum[100001];
    printf("What operation would you like to do?\n");
    printf("1. Decimal to Binary Conversion\n");
    printf("2. Binary to Decimal Conversion\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter Decimal Number: ");
        scanf("%d", &num);
        printf("Binary Conversion: ");
        decimalToBinary(num);
    } else if (choice == 2) {
        printf("Enter Binary Number: ");
        scanf("%s", binaryNum);
        printf("Decimal Conversion: ");
        binaryToDecimal(binaryNum);
    } else {
        printf("Invalid Choice!\n");
    }
    return 0;
}