//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: futuristic
#include <stdio.h>

// function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimalNumber)
{
    // array to store hexadecimal number
    char hexadecimalNumber[100];
    
    // counter for hexadecimal number array
    int i = 0;
    
    while(decimalNumber != 0)
    {
        // temporary variable to store remainder
        int remainder = 0;
        
        // get remainder by dividing decimal number by 16
        remainder = decimalNumber % 16;
        
        // check if remainder is less than 10
        if(remainder < 10)
            hexadecimalNumber[i] = remainder + 48;
        else
            hexadecimalNumber[i] = remainder + 55;
        
        // move to next digit
        i++;
        
        // update decimal number for next iteration
        decimalNumber /= 16;
    }
    
    // print the hexadecimal number in reverse order
    printf("Hexadecimal Number: ");
    for(int j = i - 1; j >= 0; j--)
        printf("%c", hexadecimalNumber[j]);
}

int main()
{
    int decimalNumber;
    
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);
    
    decimalToHexadecimal(decimalNumber);
    
    return 0;
}