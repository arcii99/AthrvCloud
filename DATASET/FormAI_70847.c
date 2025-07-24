//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    char hex_input[16];
    int decimal_output = 0;
    int hex_digit = 0;
    int i, j;
    
    printf("This is a C program that converts a hexadecimal number into decimal format.\n");
    
    printf("\nEnter a hexadecimal value (up to 8 digits): 0x");
    scanf("%s",hex_input);

    if (hex_input[0] == '0' && (hex_input[1] == 'x' || hex_input[1] == 'X')) {
        for (i = strlen(hex_input)-1, j = 0; i >= 2; --i, ++j) {
            if (hex_input[i] >= '0' && hex_input[i] <= '9') {
                hex_digit = hex_input[i] - '0';
            } 

            else if (hex_input[i] >= 'A' && hex_input[i] <= 'F') {
                hex_digit = hex_input[i] - 'A' + 10;
            } 

            else if (hex_input[i] >= 'a' && hex_input[i] <= 'f') {
                hex_digit = hex_input[i] - 'a' + 10;
            }

            else {
                fprintf(stderr, "The input is invalid, please enter a valid hexadecimal number.\n");
                exit(EXIT_FAILURE);
            }

            decimal_output += hex_digit * (1 << (4 * j));
        }

        printf("The decimal equivalent of the entered hexadecimal number is: %d\n", decimal_output);
    } 

    else {
        fprintf(stderr, "The input is invalid, please enter a valid hexadecimal number.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}