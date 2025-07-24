//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: single-threaded
#include <stdio.h>

#define HEX_BASE 16

int main() {

    unsigned long hexValue;
    char hexString[16] = {0};
    int i, j, numDigits;
    char temp;

    printf("Enter a hexadecimal number: ");
    scanf("%lx", &hexValue);

    // convert hexValue to a string in reverse order
    i = 0;
    while (hexValue) {
        hexString[i] = hexValue % HEX_BASE;
        if (hexString[i] < 10) {
            hexString[i] += '0';
        }
        else {
            hexString[i] += 'A' - 10;
        }
        hexValue /= HEX_BASE;
        i++;
    }

    numDigits = i;

    // reverse the string
    j = 0;
    i--;
    while (j < i) {
        temp = hexString[i];
        hexString[i] = hexString[j];
        hexString[j] = temp;
        i--;
        j++;
    }

    printf("The equivalent decimal value is: %lu\n", hexValue);

    return 0;
}