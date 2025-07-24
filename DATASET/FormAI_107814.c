//FormAI DATASET v1.0 Category: Color Code Converter ; Style: optimized
#include <stdio.h>

#define HEX_BASE 16

unsigned char convert_hex_char_to_decimal(char hex_char)
{
    if (hex_char >= '0' && hex_char <= '9')
        return hex_char - '0';
    else if (hex_char >= 'a' && hex_char <= 'f')
        return hex_char - 'a' + 10;
    else if (hex_char >= 'A' && hex_char <= 'F')
        return hex_char - 'A' + 10;

    return 0;
}

int main(void)
{
    char hex_code[7];
    unsigned char red, green, blue;

    printf("Enter a 6-digit hexadecimal color code: ");
    scanf("%6s", hex_code);

    red = convert_hex_char_to_decimal(hex_code[0]) * HEX_BASE + convert_hex_char_to_decimal(hex_code[1]);
    green = convert_hex_char_to_decimal(hex_code[2]) * HEX_BASE + convert_hex_char_to_decimal(hex_code[3]);
    blue = convert_hex_char_to_decimal(hex_code[4]) * HEX_BASE + convert_hex_char_to_decimal(hex_code[5]);

    printf("The RGB values for the color code #%s are: %d, %d, %d\n", hex_code, red, green, blue);

    return 0;
}