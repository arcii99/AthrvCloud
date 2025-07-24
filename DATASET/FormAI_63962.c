//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: genious
#include <stdio.h>
#include <string.h>

// function to convert decimal to hexadecimal
char* decToHex(int n)
{
    char hexaDeciNum[100];
    int i = 0;

    while (n != 0) {
        int temp = 0;
        temp = n % 16;
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        n /= 16;
    }

    char* hexValue = malloc(sizeof(char)*(strlen(hexaDeciNum)+1));
    int j=0;
    for(i=strlen(hexaDeciNum)-1; i>=0; i--) {
        hexValue[j] = hexaDeciNum[i];
        j++;
    }

    hexValue[j] = '\0';

    return hexValue;
}

int main() {
    int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    char *hexadecimalNumber = decToHex(decimalNumber);
    printf("Hexadecimal Equivalent: %s", hexadecimalNumber);

    return 0;
}