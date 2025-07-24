//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main() {
    int decimal, remainder, tempDecimal;
    char hexadecimal[100]; 
    int i = 0, j;
    
    printf("Enter a decimal number: ");
    scanf("%d", &decimal); 
    
    tempDecimal = decimal;
    
    /* convert decimal to hexadecimal */
    while (tempDecimal != 0) {
        remainder = tempDecimal % 16;
        if (remainder < 10) {
            hexadecimal[i++] = 48 + remainder;
        } else {
            hexadecimal[i++] = 55 + remainder;
        }
        tempDecimal /= 16;
    }
    hexadecimal[i] = '\0';
    
    /* reverse the string */
    for (j = 0; j < i / 2; j++) {
        char temp = hexadecimal[j];
        hexadecimal[j] = hexadecimal[i - j - 1];
        hexadecimal[i - j - 1] = temp;
    }
    
    /* print the hexadecimal number */
    printf("Hexadecimal number is: %s\n", hexadecimal);
    
    return 0;
}