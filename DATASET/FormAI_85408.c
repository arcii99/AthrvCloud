//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: artistic
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int decimal_num, rem, quotient;   // Variables to store the decimal number, remainder and quotient.
    int i = 1, j, temp;               // Variables for loop counter, temporary variable and output array.
    char hex_num[100];                // Array to store the hexadecimal number.

    printf("Enter a Decimal Number: ");
    scanf("%d", &decimal_num);        // Accepting the decimal number from user.

    quotient = decimal_num;           // Copy the value of decimal_num to quotient.

    while(quotient != 0)             // Loop to convert decimal to hexadecimal.
    {
        temp = quotient % 16;        // Find the remainder.
        if(temp < 10)               // Condition to check whether temp is less than 10.
        {
            temp = temp + 48;       // Add 48 to temp to get its corresponding ASCII value.
        }
        else
        {
            temp = temp + 55;       // Add 55 to temp to get its corresponding ASCII value.
        }
        hex_num[i++] = temp;        // Add the ASCII value of temp to the hex_num array.
        quotient = quotient / 16;   // Divide quotient by 16.
    }

    printf("Hexadecimal Equivalent of %d is: ", decimal_num);  
    
    for(j = i - 1; j > 0; j--)      // Loop to display the hexadecimal number.
    {
        printf("%c", hex_num[j]);   // Print each digit of hexadecimal number.
    }

    return 0;                       // End of main function.
}