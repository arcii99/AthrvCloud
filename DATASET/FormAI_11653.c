//FormAI DATASET v1.0 Category: Data validation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to validate whether a string is a valid integer
int is_valid_integer(char *str) {
    int i = 0;
    
    // Check if the first character is a minus sign or a digit
    if (str[i] == '-' || isdigit(str[i])) {
        // If the first character is a minus sign, move to the next character
        if (str[i] == '-') {
            i++;
        }
        // Check if the remaining characters are digits
        while (str[i] != '\0') {
            if (!isdigit(str[i])) {
                return 0;
            }
            i++;
        }
        return 1;
    }
    return 0;
}

// Function to validate whether a string is a valid floating point number
int is_valid_float(char *str) {
    int i = 0;
    int decimal_count = 0;
    
    // Check if the first character is a minus sign or a digit
    if (str[i] == '-' || isdigit(str[i])) {
        // If the first character is a minus sign, move to the next character
        if (str[i] == '-') {
            i++;
        }
        // Check if the remaining characters are digits or a decimal point
        while (str[i] != '\0') {
            if (str[i] == '.') {
                // Make sure there is only one decimal point
                decimal_count++;
                if (decimal_count > 1) {
                    return 0;
                }
            } else if (!isdigit(str[i])) {
                return 0;
            }
            i++;
        }
        return 1;
    }
    return 0;
}

// Function to validate whether a string is a valid phone number
int is_valid_phone_number(char *str) {
    int i = 0;
    int digit_count = 0;
    
    // Check if the string has the correct length
    if (strlen(str) != 10) {
        return 0;
    }
    // Check if the string contains only digits
    while (str[i] != '\0') {
        if (!isdigit(str[i])) {
            return 0;
        }
        digit_count++;
        i++;
    }
    // Make sure the string contains exactly 10 digits
    if (digit_count != 10) {
        return 0;
    }
    return 1;
}

int main() {
    char input[100];
    
    // Ask the user for input
    printf("Enter an integer: ");
    fgets(input, 100, stdin);
    // Remove the newline character from the input
    input[strcspn(input, "\n")] = 0;
    
    // Validate the integer input
    if (is_valid_integer(input)) {
        printf("%s is a valid integer.\n", input);
    } else {
        printf("%s is not a valid integer.\n", input);
    }
    
    // Ask the user for input
    printf("Enter a floating point number: ");
    fgets(input, 100, stdin);
    // Remove the newline character from the input
    input[strcspn(input, "\n")] = 0;
    
    // Validate the floating point input
    if (is_valid_float(input)) {
        printf("%s is a valid floating point number.\n", input);
    } else {
        printf("%s is not a valid floating point number.\n", input);
    }
    
    // Ask the user for input
    printf("Enter a phone number: ");
    fgets(input, 100, stdin);
    // Remove the newline character from the input
    input[strcspn(input, "\n")] = 0;
    
    // Validate the phone number input
    if (is_valid_phone_number(input)) {
        printf("%s is a valid phone number.\n", input);
    } else {
        printf("%s is not a valid phone number.\n", input);
    }
    
    return 0;
}