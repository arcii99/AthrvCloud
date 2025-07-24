//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: minimalist
#include <stdio.h>

int main() {
    unsigned int decimal;
    printf("Please enter a decimal number: ");
    scanf("%u", &decimal);

    char hexadecimal[100];
    int i = 0, remainder;

    while(decimal != 0) {
        remainder = decimal % 16;

        if (remainder < 10) {
            hexadecimal[i] = remainder + 48;
        } else {
            hexadecimal[i] = remainder + 55; 
          /* 55 = ASCII value of 'A' - 10. This step converts remainder 10 to 'A', 
          11 to 'B' and so on */
        }

        decimal = decimal / 16;
        i++;
    }

    printf("The equivalent hexadecimal number is: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }

    return 0;
}