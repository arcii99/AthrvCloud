//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: relaxed
#include<stdio.h>
#include<string.h>

void hexadecimalConverter(int decimalNum)
{
    // Array to store hexadecimal values
    char hexaDecimalNum[100];
 
    // Counter for hexadecimal number array
    int i=0;
    while(decimalNum!=0)
    {
        // Temporary variable to store remainder
        int temp  = 0;
 
        // Getting remainder by taking modulo
        temp = decimalNum % 16;
 
        // Checking if the remainder is less than 10
        if(temp < 10)
        {
            hexaDecimalNum[i] = temp + 48;
            i++;
        }
        else
        {
            hexaDecimalNum[i] = temp + 55;
            i++;
        }
 
        decimalNum = decimalNum/16;
    }
 
    //Printing hexadecimal number array in reverse order
    printf("The hexadecimal number is: ");
    for(int j=i-1; j>=0; j--)
        printf("%c", hexaDecimalNum[j]);
}
 
int main()
{
    int decimalNum;
    printf("Enter the decimal number: ");
    scanf("%d", &decimalNum);

    hexadecimalConverter(decimalNum);

    return 0;
}