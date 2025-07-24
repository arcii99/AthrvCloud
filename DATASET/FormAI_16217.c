//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program converts decimal numbers to hexadecimal numbers. */

int main() {
    int decimal;
    char hex[100];
    int i = 0;
    
    /* Ask for a decimal integer. */
    printf("Enter a decimal integer: ");
    scanf("%d", &decimal);
    
    /* Convert decimal integer to hexadecimal. */
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[i] = remainder + 48;
        } else {
            hex[i] = remainder + 55;
        }
        decimal /= 16;
        i++;
    }
    hex[i] = '\0';
    
    /* Reverse the hexadecimal string. */
    int len = strlen(hex);
    for (int j = 0; j < len/2; j++) {
        char temp = hex[j];
        hex[j] = hex[len-1-j];
        hex[len-1-j] = temp;
    }
    
    /* Print the converted hexadecimal number. */
    printf("Hexadecimal: %s\n", hex);
    
    return 0;
}