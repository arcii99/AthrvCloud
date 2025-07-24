//FormAI DATASET v1.0 Category: Binary Converter ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    int decimal_number;
    int binary_number[32] = {0}; // maximum 32 bits
    int index = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal_number);

    // convert decimal to binary
    while (decimal_number > 0) {
        binary_number[index] = decimal_number % 2;
        decimal_number = decimal_number / 2;
        index++;
    }

    // print binary result
    printf("The binary representation is: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary_number[i]);
    }
    printf("\n");

    return 0;
}