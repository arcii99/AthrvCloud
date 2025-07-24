//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: romantic
#include <stdio.h>

void decimalToHex(int decimal){
    int remainder, quotient;
    char hexadecimal[20];
    int i = 0;

    quotient = decimal;

    while(quotient != 0){
        remainder = quotient % 16;
        if(remainder < 10)
            hexadecimal[i++] = 48 + remainder;
        else
            hexadecimal[i++] = 55 + remainder;
        quotient /= 16;
    }

    printf("The hexadecimal equivalent of %d is:", decimal);
    for(int j = i - 1; j >= 0; j--)
        printf("%c", hexadecimal[j]);
}

int main(){
    int decimal;

    printf("My love, please give me a decimal number to convert to hexadecimal: ");
    scanf("%d", &decimal);

    decimalToHex(decimal);

    return 0;
}