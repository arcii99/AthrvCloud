//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEX_LEN 16

int main()
{
    char hex_in[MAX_HEX_LEN];
    long decimal_out = 0;
    int hex_len;

    printf("Enter a hexadecimal number (up to 16 characters): ");
    fgets(hex_in, MAX_HEX_LEN, stdin);

    hex_len = strlen(hex_in) - 1; // subtracting newline character

    for (int i = hex_len - 1; i >= 0; i--) {
        int digit_val;

        if (hex_in[i] >= '0' && hex_in[i] <= '9') {
            digit_val = hex_in[i] - '0';
        } else if (hex_in[i] >= 'a' && hex_in[i] <= 'f') {
            digit_val = hex_in[i] - 'a' + 10;
        } else if (hex_in[i] >= 'A' && hex_in[i] <= 'F') {
            digit_val = hex_in[i] - 'A' + 10;
        } else {
            printf("Invalid digit: %c\n", hex_in[i]);
            return 1;
        }

        decimal_out += digit_val << ((hex_len - 1 - i) * 4);
    }

    printf("Decimal value: %ld\n", decimal_out);

    return 0;
}