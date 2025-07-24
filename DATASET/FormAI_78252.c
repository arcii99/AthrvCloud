//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: calm
#include <stdio.h>

int main(){

    char hex[17] = "0123456789abcdef"; //this array holds all possible hexadecimal characters
    unsigned int decimal, quotient, remainder, i = 0;
    char hexnumber[20]; //we will store the hexadecimal number in this array

    printf("Enter a decimal number: ");
    scanf("%u", &decimal);

    quotient = decimal;

    while(quotient != 0){

        remainder = quotient % 16; //divide the decimal number by 16 to get remainder as hexadecimal number
        hexnumber[i++] = hex[remainder]; //store the remainder in an array
        quotient = quotient / 16; //update the quotient

    }

    printf("Hexadecimal Equivalent : ");
    for(int j = i - 1; j >= 0; j--){ //print the hexadecimal number stored in array in reverse order

        printf("%c", hexnumber[j]);

    }

    return 0;
}