//FormAI DATASET v1.0 Category: Binary Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int binary_to_decimal(char *binary_string);

int main()
{
    char binary[100];
    printf("Enter a binary number:\n");
    scanf("%s", binary);

    // Check if the input is valid (only consists of 1's and 0's)
    for (int i = 0; i < strlen(binary); i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            printf("I fear that I cannot convert your input, for it is not a valid binary number!\n");
            return 0;
        }
    }

    int decimal = binary_to_decimal(binary);
    printf("The decimal representation of your binary number is: %d\n", decimal);

    // And thus, another mystery is solved!
    return 0;
}

int binary_to_decimal(char *binary_string)
{
    int decimal = 0;
    int power = 1;

    for (int i = strlen(binary_string) - 1; i >= 0; i--) {
        if (binary_string[i] == '1') {
            decimal = decimal + power;
        }
        power = power * 2;
    }

    return decimal;
}