//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>

void hextobinary(char hexa)
{
    switch (hexa) {
    case '0':
        printf("0000");
        break;
    case '1':
        printf("0001");
        break;
    case '2':
        printf("0010");
        break;
    case '3':
        printf("0011");
        break;
    case '4':
        printf("0100");
        break;
    case '5':
        printf("0101");
        break;
    case '6':
        printf("0110");
        break;
    case '7':
        printf("0111");
        break;
    case '8':
        printf("1000");
        break;
    case '9':
        printf("1001");
        break;
    case 'A':
    case 'a':
        printf("1010");
        break;
    case 'B':
    case 'b':
        printf("1011");
        break;
    case 'C':
    case 'c':
        printf("1100");
        break;
    case 'D':
    case 'd':
        printf("1101");
        break;
    case 'E':
    case 'e':
        printf("1110");
        break;
    case 'F':
    case 'f':
        printf("1111");
        break;
    default:
        printf("invalid hexadecimal digit %c", hexa);
    }
}

int main()
{
    char hex[17];
    long long decimal, place;
    int i = 0, val, len;

    printf("Enter hexadecimal number: ");
    fgets(hex, 17, stdin);

    // Find the length of the input hexadecimal number
    len = strlen(hex);
    // Check if the input is too long
    if (len > 16) {
        printf("Error: Input too long. Max length is 16.\n");
        exit(0);
    }
    // Check if the input contains an invalid character
    for(i = 0; i < len - 1; i++) {
        if ((hex[i] < 48 || hex[i] > 57) &&
            (hex[i] < 65 || hex[i] > 70) &&
            (hex[i] < 97 || hex[i] > 102)) {
            printf("Error: Invalid character '%c' in input.\n", hex[i]);
            exit(0);
        }
    }

    decimal = 0;
    place = 1;
    i = len - 2;

    while (i >= 0) {
        // Convert the current hexadecimal digit to binary
        hextobinary(hex[i]);
        // Convert the current hexadecimal digit to decimal
        if (hex[i] >= '0' && hex[i] <= '9') {
            val = hex[i] - 48;
        } else if(hex[i] >= 'a' && hex[i] <= 'f') {
            val = hex[i] - 97 + 10;
        } else if(hex[i] >= 'A' && hex[i] <= 'F') {
            val = hex[i] - 65 + 10;
        }
        // Add the decimal value of the current hexadecimal digit to the total
        decimal += val * place;
        place *= 16;
        i--;
    }

    printf("\nDecimal number of %s is %lld.\n", hex, decimal);

    return 0;
}