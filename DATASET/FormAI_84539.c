//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: cheerful
#include <stdio.h>

int main() {
    int decimal, remainder;
    char hexadecimal[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    
    printf("Welcome to the Decimal to Hexadecimal Converter!\n");
    printf("Please enter a decimal number: ");
    scanf("%d", &decimal);
    
    int quotient = decimal;
    int i = 0;
    char hex[20];
    
    while (quotient > 0) {
        remainder = quotient % 16;
        hex[i++] = hexadecimal[remainder];
        quotient /= 16;
    }
    
    printf("The hexadecimal value of %d is: ", decimal);
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");
    
    return 0;
}