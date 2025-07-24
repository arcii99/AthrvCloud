//FormAI DATASET v1.0 Category: Binary Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void binary_converter(float decimal){
    if(decimal >= 1 || decimal < 0){
        printf("Error! Decimal number should be between 0 and 1.\n");
        return;
    }

    char binary[32];
    int index = 0;

    while(decimal > 0){
        if(index > 31){
            printf("Error! Cannot convert the decimal number to binary representation with precision higher than 31 bits.\n");
            return;
        }

        decimal = decimal * 2;
        if(decimal >= 1){
            binary[index++] = '1';
            decimal = decimal - 1;
        } else {
            binary[index++] = '0';
        }
    }
    binary[index] = '\0';

    printf("Binary equivalent: %s\n", binary);
}

int main(){
    float decimal;
    printf("Enter a decimal number between 0 and 1: ");
    scanf("%f", &decimal);

    binary_converter(decimal);

    return 0;
}