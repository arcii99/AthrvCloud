//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: protected
#include <stdio.h>
#include <ctype.h>

// Function to check if an input string is a valid hexadecimal string
int is_valid_hex_string(const char *hex_string) {
    while(*hex_string) {
        if(!isxdigit(*hex_string)) {
            return 0;
        }
        hex_string++;
    }
    return 1;
}

// Function to convert a single hexadecimal character to its decimal equivalent
int hex_char_to_decimal(char hex_char) {
    hex_char = toupper(hex_char); // Convert hex character to uppercase for simplicity
    if(hex_char >= '0' && hex_char <= '9') {
        return hex_char - '0'; 
    } else {
        return hex_char - 'A' + 10;
    }
}

// Function to convert a hexadecimal string to its decimal equivalent
int hex_string_to_decimal(const char *hex_string) {
    int decimal_value = 0;
    while(*hex_string) {
        decimal_value = decimal_value * 16 + hex_char_to_decimal(*hex_string);
        hex_string++;
    }
    return decimal_value; 
}

int main() {
    char hex_string[100];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_string);

    if(!is_valid_hex_string(hex_string)) {
        printf("Invalid hexadecimal string\n");
        return 1;
    }

    int decimal_value = hex_string_to_decimal(hex_string);
    printf("Decimal equivalent: %d\n", decimal_value);
    return 0;
}