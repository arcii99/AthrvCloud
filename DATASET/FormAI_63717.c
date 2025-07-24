//FormAI DATASET v1.0 Category: Binary Converter ; Style: visionary
#include <stdio.h>

//function to convert decimal to binary
void decimalToBinary(int decimal) {
    int binary = 0, reminder, i = 1;
    while (decimal != 0) {
        reminder = decimal % 2;
        decimal /= 2;
        binary += reminder * i;
        i *= 10;
    }
    printf("Binary: %d\n", binary);
}

//function to convert binary to decimal
void binaryToDecimal(int binary) {
    int decimal = 0, reminder, i = 0;
    while (binary != 0) {
        reminder = binary % 10;
        binary /= 10;
        decimal += reminder * pow(2, i);
        i++;
    }
    printf("Decimal: %d\n", decimal);
}

int main() {
    int choice;
    printf("1. Decimal to Binary Conversion\n2. Binary to Decimal Conversion\nEnter your choice: ");
    scanf("%d", &choice);
    if(choice == 1) {
        int decimal;
        printf("Enter Decimal: ");
        scanf("%d", &decimal);
        decimalToBinary(decimal);
    } else if(choice == 2) {
        int binary;
        printf("Enter Binary: ");
        scanf("%d", &binary);
        binaryToDecimal(binary);
    } else {
        printf("Invalid Choice!!\n");
    }

    return 0;
}