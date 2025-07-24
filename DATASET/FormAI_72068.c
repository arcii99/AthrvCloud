//FormAI DATASET v1.0 Category: Binary Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 16 // Maximum length of binary string, including null terminator

int main() {
    char binary[MAX_LENGTH]; // Binary string
    int decimal = 0; // Decimal value
    int i = 0; // Counter variable
    
    printf("Enter binary number: ");
    fgets(binary, MAX_LENGTH, stdin); // Read binary string from user input

    // Remove newline character if it exists
    if (binary[strlen(binary) - 1] == '\n') {
        binary[strlen(binary) - 1] = '\0';
    }
    
    // Convert binary string to decimal value
    for (i = 0; i < strlen(binary); i++) {
        // If binary character is not '0' or '1', print error message and exit program
        if (binary[i] != '0' && binary[i] != '1') {
            printf("Error: Invalid binary number!\n");
            return 1; // Return 1 to indicate program error
        }
        
        decimal = decimal * 2 + (binary[i] - '0'); // Convert binary to decimal
    }
    
    // Print decimal value
    printf("Decimal value: %d\n", decimal);
    
    return 0; // Return 0 to indicate program success
}