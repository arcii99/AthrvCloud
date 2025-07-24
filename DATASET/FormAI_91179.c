//FormAI DATASET v1.0 Category: Color Code Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void convert_to_hex(int decimal_number, char* hex_number);
char convert_to_char(int digit);


int main()
{
    int decimal_number;
    char hex_number[20] = "";
    printf("Enter decimal number: ");
    scanf("%d", &decimal_number);
    convert_to_hex(decimal_number, hex_number);
    printf("Hexadecimal equivalent: %s\n", hex_number);
    return 0;
}

void convert_to_hex(int decimal_number, char* hex_number)
{
    if (decimal_number == 0)
    {
        return;
    }
    else
    {
        int remainder = decimal_number % 16;
        hex_number[strlen(hex_number)] = convert_to_char(remainder);
        convert_to_hex(decimal_number/16, hex_number);
    }
}

char convert_to_char(int digit)
{
    if (digit >= 0 && digit <= 9)
    {
        return (char)('0' + digit);
    }
    else
    {
        return (char)('A' + (digit - 10));
    }
}