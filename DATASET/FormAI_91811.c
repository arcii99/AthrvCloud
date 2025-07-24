//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: light-weight
#include <stdio.h>

int main() {
    // Input number in decimal format
    int decimal, remainder, quotient;
    printf("Enter decimal number to convert: ");
    scanf("%d", &decimal);

    // Converting decimal to hexadecimal
    char hexadecimal[20];
    int i=0;
    quotient = decimal;
    while(quotient!=0) {
        remainder = quotient % 16;
        if(remainder<10) {
            hexadecimal[i] = 48 + remainder;
            i++;
        }
        else {
            hexadecimal[i] = 55 + remainder;
            i++;
        }
        quotient = quotient / 16;
    }
    printf("Hexadecimal equivalent: ");

    // Printing hexadecimal value in reverse order
    for(int j=i-1; j>=0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n");

    return 0;
}