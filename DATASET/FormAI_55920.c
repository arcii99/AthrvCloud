//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: enthusiastic
#include <stdio.h>

int main() {
    printf("Welcome to the Hexadecimal Converter!\n");
    printf("Enter a decimal number to convert: ");

    int decimal;
    scanf("%d", &decimal);

    char hex[100];
    int i = 0;

    // conversion loop
    while (decimal != 0) {
        int remainder = decimal % 16;

        if (remainder < 10) {
            hex[i] = remainder + 48; // ASCII code for 0-9
        } else {
            hex[i] = remainder + 55; // ASCII code for A-F
        }

        i++;
        decimal /= 16;
    }

    // output in reverse order
    printf("The hexadecimal representation is: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    printf("\n");

    return 0;
}