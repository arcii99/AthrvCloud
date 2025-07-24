//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: rigorous
#include <stdio.h>

int main() {
    unsigned int decimal; 
    int i = 0, j;
    char hexadecimal[100]; // maximum 100 digits for hexadecimal representation
    printf("Enter a decimal number: ");
    scanf("%u", &decimal);
    
    while(decimal != 0) {
        int remainder = decimal % 16;
        if(remainder < 10) {
            hexadecimal[i] = 48 + remainder; // ASCII code for digit 0-9
        } else {
            hexadecimal[i] = 55 + remainder; // ASCII code for letter A-F
        }
        i++;
        decimal = decimal / 16;
    }
    
    printf("Hexadecimal representation: ");
    for(j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n");
    return 0;
}