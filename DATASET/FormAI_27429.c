//FormAI DATASET v1.0 Category: Binary Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

void binaryConverter(int decimalNum); // function to convert decimal to binary

int main()
{
    int decimalNum;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);
    binaryConverter(decimalNum);
    return 0;
}

void binaryConverter(int decimalNum){
    // array to store binary number
    int binaryArr[32];

    // counter for binary array
    int i = 0;

    while(decimalNum > 0){
        // storing remainder in binary array
        binaryArr[i] = decimalNum % 2;
        decimalNum /= 2;
        i++;
    }

    // printing binary array in reverse order
    printf("Binary Number: ");
    for(int j = i-1; j >= 0; j--)
        printf("%d", binaryArr[j]);
}