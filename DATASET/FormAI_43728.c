//FormAI DATASET v1.0 Category: Binary Converter ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_header()
{
    printf("\n********************************************\n");
    printf("**** WELCOME TO THE HAPPY BINARY CONVERTER ****\n");
    printf("********************************************\n");
}

int validate_input(char input[])
{
    int i;
    for(i=0; i<strlen(input); i++)
    {
        if (input[i] != '0' && input[i] != '1')
            return 0;
    }
    return 1;
}

int binary_to_decimal(char input[])
{
    int i, result = 0;
    for(i=0; i<strlen(input); i++)
    {
        int digit = input[i] - '0';
        result += digit * pow(2, strlen(input)-i-1);
    }
    return result;
}

void decimal_to_binary(int decimal)
{
    int binary[32], i = 0;
    while(decimal > 0)
    {
        binary[i++] = decimal % 2;
        decimal /= 2;        
    }
    printf("\nBinary representation: ");
    while(--i >= 0) printf("%d", binary[i]);
}

int main()
{
    char input[33];
    print_header();
    printf("\nEnter a binary number (up to 32 bits): ");
    scanf("%32s", input);
    
    if(validate_input(input) == 0)
    {
        printf("\nOops! Invalid input. Only 0s and 1s are allowed.\n");
        return 0;
    }
    
    int decimal = binary_to_decimal(input);
    printf("\nDecimal representation: %d", decimal);
    
    decimal_to_binary(decimal);
    printf("\n");
    
    return 0;
}