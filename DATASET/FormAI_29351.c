//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char hex_chars[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void decimal_to_hexadecimal(int decimal);

int main() {
    int number;
    printf("Enter a decimal number: ");
    scanf("%d", &number);

    printf("The hexadecimal equivalent of %d is: ", number);
    decimal_to_hexadecimal(number);
    printf("\n");

    return 0;
}

void decimal_to_hexadecimal(int decimal) {
    char hex[10]; // max length of a 32-bit number is 8 hexadecimal digits
    int index = 0;

    while (decimal > 0) {
        int remainder = decimal % 16;
        decimal = decimal / 16;
        hex[index] = hex_chars[remainder];
        index++;
    }

    // print the hex number in reverse order
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hex[i]);
    }
}