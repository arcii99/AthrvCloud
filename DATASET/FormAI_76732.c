//FormAI DATASET v1.0 Category: Binary Converter ; Style: secure
#include <stdio.h>
#include <string.h>

int power(int, int);

int main() {
    int decimal, binary[32], index = 0, num, i;
    char input[32];

    printf("Enter a decimal number: ");
    fgets(input, 32, stdin);

    // Check for negative input
    if (input[0] == '-') {
        printf("Error: Negative input!");
        return 1;
    }

    // Remove newline from input
    input[strcspn(input, "\n")] = 0;

    decimal = atoi(input);

    // Check if input is a number
    if (decimal == 0 && strcmp(input, "0") != 0) {
        printf("Error: Input is not a number!");
        return 1;
    }

    num = decimal;

    // Convert decimal to binary
    while (num != 0) {
        binary[index] = num % 2;
        num = num / 2;
        index++;
    }

    // Output binary number
    printf("Binary equivalent: ");
    for (i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }

    return 0;
}

int power(int base, int exponent) {
    int result = 1, i;

    for (i = 0; i < exponent; i++) {
        result = result * base;
    }

    return result;
}