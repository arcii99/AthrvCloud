//FormAI DATASET v1.0 Category: Color Code Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 10

int main() {
    char input[MAX_INPUT];
    printf("Enter a 6-digit hexadecimal color code: ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline character
    
    // Check if input is valid hexadecimal code
    for (int i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i]) && (input[i] < 'A' || input[i] > 'F') && (input[i] < 'a' || input[i] > 'f')) {
            printf("Error: Invalid hexadecimal color code\n");
            return 1;
        }
    }
    
    // Convert input to decimal values
    int r = strtol(input, NULL, 16) >> 16;
    int g = strtol(input, NULL, 16) >> 8;
    int b = strtol(input, NULL, 16);
    
    // Calculate grayscale equivalent
    int gray = (r * 0.3) + (g * 0.59) + (b * 0.11);
    
    // Output original color and grayscale equivalent
    printf("Original Color: #%s\n", input);
    printf("Grayscale Equivalent: #%02X%02X%02X\n", gray, gray, gray);
    
    return 0;
}