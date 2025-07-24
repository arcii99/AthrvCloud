//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: sophisticated
#include <stdio.h>

// Function to convert decimal to hexadecimal 
void decimal_to_hexadecimal(int decimal_num)
{
    int remainder, quotient;
    char hexadecimal[100];
    quotient = decimal_num;
    int i = 0;
    
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[i++] = 48 + remainder;  // Covert numeric remainder to char & add to string
        else
            hexadecimal[i++] = 55 + remainder;  // Covert alphabet remainder to char & add to string
        quotient = quotient / 16;
    }
    
    // Print the hexadecimal string in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hexadecimal[j]);
}

int main()
{
    int decimal_num;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);
    printf("The equivalent hexadecimal number is : ");
    decimal_to_hexadecimal(decimal_num);
    printf("\n");
    return 0;
}