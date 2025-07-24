//FormAI DATASET v1.0 Category: Binary Converter ; Style: interoperable
#include<stdio.h>

void decimalToBinary(int decimal) {
    int binary[32], index = 0;
    while(decimal > 0) {
        binary[index] = decimal % 2;
        decimal = decimal / 2;
        index++;
    }
    printf("Binary representation of decimal number is: ");
    for(int i = index - 1; i >= 0; i--)
        printf("%d", binary[i]);
    printf("\n");
}

int binaryToDecimal(long long binary) {
    int decimal = 0, base = 1, remainder;
    while(binary > 0) {
        remainder = binary % 10;
        binary = binary / 10;
        decimal = decimal + remainder * base;
        base *= 2;
    }
    return decimal;
}

int main() {
    int choice;
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        int decimal;
        printf("Enter decimal number: ");
        scanf("%d", &decimal);
        decimalToBinary(decimal);
    } else if(choice == 2) {
        long long binary;
        printf("Enter binary number: ");
        scanf("%lld", &binary);
        int decimal = binaryToDecimal(binary);
        printf("Decimal representation of binary number is: %d\n", decimal);
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}