//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

void convertToHexadecimal(int decimalNumber)
{
    int tempNumber, remainder; 
    char hexadecimalNumber[50];

    tempNumber = decimalNumber;
    int i = 0;
    while(tempNumber != 0){
        remainder = tempNumber % 16;
        if(remainder < 10){
            hexadecimalNumber[i++] = 48 + remainder;
        }
        else{
            hexadecimalNumber[i++] = 55 + remainder;
        }
        tempNumber /= 16;
    }
    printf("The equivalent hexadecimal number for decimal number %d is: ", decimalNumber);
    for(int j=i-1; j>=0; j--){
        printf("%c", hexadecimalNumber[j]);
    }
    printf("\n");
}

int main()
{
    printf("\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t|  C HEXADECIMAL CONVERTER  |\n");
    printf("\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    int decimalNumber;
    printf("Enter the decimal number you want to convert to hexadecimal: ");
    scanf("%d", &decimalNumber);

    if(decimalNumber < 0){
        printf("Please enter a positive integer!\n");
    }
    else{
        convertToHexadecimal(decimalNumber);
    }

    return 0;
}