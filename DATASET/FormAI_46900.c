//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Dennis Ritchie
#include <stdio.h>

void convertToHex(int decimal) {
    int remainder, quotient;
    char hexadecimal[100];
    int i = 0;
    
    quotient = decimal;
    
    while (quotient != 0) {
        remainder = quotient % 16;
        
        if (remainder < 10) {
            hexadecimal[i++] = 48 + remainder;
        } else {
            hexadecimal[i++] = 55 + remainder;
        }
        
        quotient = quotient / 16;
    }
    
    printf("Hexadecimal Conversion: ");
    
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
}

int main() {
    int decimal;
    
    printf("Enter a Decimal Number: ");
    scanf("%d", &decimal);
    
    convertToHex(decimal);
    
    return 0;
}