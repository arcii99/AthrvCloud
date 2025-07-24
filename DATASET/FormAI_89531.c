//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
    char hex[17], ch;
    int i = 0, decimal;
    
    printf("Enter a hexadecimal number: ");
    do{
        scanf("%c", &ch);
        hex[i++] = ch;
    } while (ch != '\n');
    
    hex[--i] = '\0';
    decimal = hexToDecimal(hex);
    
    printf("The Decimal value of %s is %d\n", hex, decimal);
    
    return 0;
}

int hexToDecimal(char hex[]) {
    int decimal = 0, base = 1, i = 0;
    while (hex[i]) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * base;
            base *= 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            decimal += (hex[i] - 87) * base;
            base *= 16;
        }
        else {
            printf("Invalid hexadecimal number\n");
            exit(0);
        }
        i++;
    }
    return decimal;
}