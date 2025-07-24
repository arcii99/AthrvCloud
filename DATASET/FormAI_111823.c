//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: minimalist
#include <stdio.h>

int main(void) {
    unsigned int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    char hex[50];
    int i = 0;
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[i] = remainder + 48; // ASCII code for 0-9
        } else {
            hex[i] = remainder + 55; // ASCII code for A-F
        }
        i++;
        decimal /= 16;
    }
    printf("The hexadecimal of the decimal number is: ");
    for (i = i - 1; i >= 0; i--) {
        printf("%c", hex[i]);
    }
    return 0;
}