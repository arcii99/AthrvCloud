//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: excited
#include<stdio.h>

int main(){
    int decimal_num, quotient, remainder;
    int i=1, j, temp;
    char hexadecimalNumber[100];

    printf("Welcome to the C Hexadecimal Converter Program, Let's convert Decimal numbers to Hexadecimal\n");

    printf("Enter the decimal number you wish to convert: ");
    scanf("%d", &decimal_num);

    quotient = decimal_num;

    while(quotient != 0){
        temp = quotient % 16;
        if( temp < 10)
            temp = temp + 48;
        else
            temp = temp + 87;

        hexadecimalNumber[i++] = temp;
        quotient = quotient / 16;
    }

    printf("\nEquivalent Hexadecimal Number of %d is : ", decimal_num);
    for(j = i -1 ;j > 0;j--)
        printf("%c", hexadecimalNumber[j]);

    printf("\nThank you for using my program! Come back soon ;)\n");
    return 0;
}