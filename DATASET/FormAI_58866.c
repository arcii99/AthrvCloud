//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: inquisitive
#include <stdio.h>

int main() {

    int decimalNum, remainder, quotient, i=1, j;    
    char hexadecimalNum[100];

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNum);

    quotient = decimalNum;

    while(quotient != 0) {        
        remainder = quotient % 16;

        if(remainder < 10)
            hexadecimalNum[i++] = 48 + remainder;
        else
            hexadecimalNum[i++] = 55 + remainder;

        quotient /= 16;
    }

    printf("\nHexadecimal number: ");
    for(j=i; j>0; j--)
        printf("%c", hexadecimalNum[j]);

    return 0;
}