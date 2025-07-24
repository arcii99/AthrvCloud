//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX_LENGTH 1000

bool is_valid_hex(char hex_char)
{
    if((hex_char >= '0' && hex_char <= '9') || (hex_char >= 'a' && hex_char <= 'f') || 
      (hex_char >= 'A' && hex_char <= 'F'))
    {
        return true;
    }
    return false;
}

int hex_to_decimal(char hex_char)
{
    if (hex_char >= '0' && hex_char <= '9')
    {
        return hex_char - '0';
    }
    else if (hex_char >= 'a' && hex_char <='f')
    {
        return hex_char - 'a' + 10;
    } 
    else if (hex_char >= 'A' && hex_char <='F')
    {
        return hex_char - 'A' + 10;
    }
    return -1;
}

void hexadecimal_to_decimal(char hex_number[MAX_LENGTH])
{
    int length = strlen(hex_number);
    int decimal_number = 0;
    for (int i = length - 1, power = 0; i >= 0; i--, power++)
    {
        if (!is_valid_hex(hex_number[i]))
        {
            printf("Invalid hex number!");
            return;
        }
        decimal_number += hex_to_decimal(hex_number[i]) * (int)(pow(16, power));
    }
    printf("The hexadecimal number %s in decimal is %d\n", hex_number, decimal_number);
}

int main()
{
    char hex_number[MAX_LENGTH];
    printf("Please enter a hexadecimal number: ");
    fgets(hex_number, MAX_LENGTH, stdin);
    hex_number[strcspn(hex_number, "\n")] = '\0';
    hexadecimal_to_decimal(hex_number);
    return 0;
}