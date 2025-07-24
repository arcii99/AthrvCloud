//FormAI DATASET v1.0 Category: Binary Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 33

int main(void) {
    char binary[MAX_LENGTH];
    char converted[MAX_LENGTH];
    int decimal = 0, remainder, quotient;
    int i, j;

    printf("Enter binary number: ");
    fgets(binary, MAX_LENGTH, stdin);
    binary[strcspn(binary, "\n")] = 0;

    for(i = 0; i < strlen(binary); i++) {
        if(binary[i] != '0' && binary[i] != '1') {
            printf("Invalid input!\n");
            return 1;
        }
    }

    for(i = strlen(binary) - 1, j = 0; i >= 0; i--, j++) {
        decimal += (binary[i] - '0') * (1 << j);
    }
    
    quotient = decimal;
    i = 0;

    while(quotient > 0) {
        remainder = quotient % 2;
        quotient = quotient / 2;

        converted[i++] = remainder + '0';
    }

    converted[i] = '\0';

    for(i = 0, j = strlen(converted) - 1; i < j; i++, j--) {
        char temp = converted[i];
        converted[i] = converted[j];
        converted[j] = temp;
    }

    printf("Binary: %s\nDecimal: %d\nConverted: %s\n", binary, decimal, converted);

    return 0;
}