//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: intelligent
#include <stdio.h>

int main(void) {
    printf("Welcome to the Hexadecimal Converter!\n");
    printf("Please enter a decimal number to convert: ");

    int decimal;
    scanf("%d", &decimal);

    // Converting to hexadecimal
    char hex[50];
    int remainder, i = 0;
    while(decimal != 0) {
        remainder = decimal % 16;
        if (remainder < 10) {
            hex[i] = remainder + 48;
        } else {
            hex[i] = remainder + 55;
        }
        i++;
        decimal /= 16;
    }
    hex[i] = '\0';

    // Reversing the hexadecimal
    char reversed_hex[50];
    for(int j = i - 1, k = 0; j >= 0; j--, k++) {
        reversed_hex[k] = hex[j];
    }
    reversed_hex[i] = '\0';

    // Outputting results
    printf("Decimal number: %d\n", decimal);
    printf("Hexadecimal number: %s\n", reversed_hex);

    return 0;
}