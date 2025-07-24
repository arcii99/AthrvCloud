//FormAI DATASET v1.0 Category: Binary Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main() {
    char user_input[64];
    int decimal = 0, binary = 0, base = 1, remainder;

    printf("Enter a decimal number to convert to binary: ");
    fgets(user_input, sizeof(user_input), stdin);
    decimal = atoi(user_input);

    while(decimal > 0) {
        remainder = decimal % 2;
        decimal /= 2;
        binary += remainder * base;
        base *= 10;
    }

    printf("The binary conversion of the decimal number %d is %d.\n", decimal, binary);

    return 0;
}