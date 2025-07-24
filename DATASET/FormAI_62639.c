//FormAI DATASET v1.0 Category: Educational ; Style: Claude Shannon
//This program demonstrates how to convert a binary number to decimal using bitwise operations.

#include <stdio.h>

int main() {
    int binary = 1101; //binary number to be converted
    int decimal = 0; //intialize decimal value to 0
    int bit = 0; //intialize bit position to 0
    
    while(binary > 0){
        int temp = binary & 1; //get the rightmost bit of binary number
        decimal += (temp << bit); //add the value of the bit to the decimal value
        bit++; //move to the next bit
        binary = binary >> 1; //shift the binary number right by 1
    }

    printf("Binary: %d\n", 1101); //print the original binary number
    printf("Decimal: %d\n", decimal); //print the converted decimal number

    return 0;
}