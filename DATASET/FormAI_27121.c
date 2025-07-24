//FormAI DATASET v1.0 Category: Binary Converter ; Style: shocked
#include <stdio.h>

// This function is used to convert decimal to binary
void decimalToBinary(int decimal) {
    int binaryNumber[100], index = 0;
    while(decimal > 0) {
        binaryNumber[index] = decimal % 2;
        decimal = decimal / 2;
        index++;
    }

    //Now printing binary array in reverse order
    printf("\nBinary of given decimal is: ");
    for (int j = index - 1; j >= 0; j--){
        printf("%d", binaryNumber[j]);
    }
}

int main() {
    int decimal;

    printf("Enter a Decimal Number : ");
    scanf("%d", &decimal);

    decimalToBinary(decimal);

    return 0;
}