//FormAI DATASET v1.0 Category: Binary Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char hex[17],binary[65] = {0};
    long decimal, quotient, remainder;
    int i, j, index = 0;

    printf("\nEnter a hexadecimal number: ");
    fgets(hex, sizeof(hex), stdin);
    hex[strcspn(hex, "\n")] = 0;

    for (i = 0; hex[i] != '\0'; i++) {
        switch (hex[i]) {
        case '0':
            strcat(binary, "0000");
            break;
        case '1':
            strcat(binary, "0001");
            break;
        case '2':
            strcat(binary, "0010");
            break;
        case '3':
            strcat(binary, "0011");
            break;
        case '4':
            strcat(binary, "0100");
            break;
        case '5':
            strcat(binary, "0101");
            break;
        case '6':
            strcat(binary, "0110");
            break;
        case '7':
            strcat(binary, "0111");
            break;
        case '8':
            strcat(binary, "1000");
            break;
        case '9':
            strcat(binary, "1001");
            break;
        case 'A':
        case 'a':
            strcat(binary, "1010");
            break;
        case 'B':
        case 'b':
            strcat(binary, "1011");
            break;
        case 'C':
        case 'c':
            strcat(binary, "1100");
            break;
        case 'D':
        case 'd':
            strcat(binary, "1101");
            break;
        case 'E':
        case 'e':
            strcat(binary, "1110");
            break;
        case 'F':
        case 'f':
            strcat(binary, "1111");
            break;
        default:
            printf("\nInvalid Hexadecimal Number.\n");
            return EXIT_FAILURE;
        }
    }

    decimal = 0;
    quotient = 0;
    remainder = 0;

    for (i = strlen(binary) - 1, j = 0; i >= 0; i--, j++) {
        if (binary[i] == '1') {
            decimal += pow(2, j);
        }
    }

    quotient = decimal;

    while (quotient != 0) {
        remainder = quotient % 2;
        binary[index++] = remainder + '0';
        quotient /= 2;
    }

    printf("\nBinary equivalent: ");

    for (i = index - 1; i >= 0; i--) {
        printf("%c", binary[i]);
    }

    printf("\n");

    return EXIT_SUCCESS;
}