//FormAI DATASET v1.0 Category: Binary Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// function to convert decimal to binary
void decimalToBinary(int decimal) {
    int binary[32];
    int i = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

// function to convert binary to decimal
void binaryToDecimal(char* binary) {
    int decimal = 0;
    int length = strlen(binary);
    int power = length - 1;
    for (int i = 0; i < length; i++) {
        int digit = binary[i] - '0';
        decimal += digit * pow(2, power);
        power--;
    }
    printf("Decimal: %d\n", decimal);
}

int main() {
    int choice;
    printf("C Binary Converter\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            // decimal to binary conversion
            int decimal;
            printf("\nEnter decimal number: ");
            scanf("%d", &decimal);
            decimalToBinary(decimal);
            break;
        case 2:
            // binary to decimal conversion
            char binary[32];
            printf("\nEnter binary number: ");
            scanf("%s", binary);
            binaryToDecimal(binary);
            break;
        default:
            printf("\nInvalid choice!\n");
    }
    return 0;
}