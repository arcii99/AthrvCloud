//FormAI DATASET v1.0 Category: Binary Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void convertToBinary(int decimalNumber){
    int binaryNumber = 0, base = 1, remainder;
    while(decimalNumber > 0){
        remainder = decimalNumber % 2;
        decimalNumber = decimalNumber / 2;
        binaryNumber = binaryNumber + remainder * base;
        base = base * 10;
    }
    printf("The binary equivalent of the decimal number is: %d", binaryNumber);
}

int main(){
    int decimalNumber;
    printf("Enter the decimal number: ");
    scanf("%d", &decimalNumber);
    convertToBinary(decimalNumber);
    return 0;
}