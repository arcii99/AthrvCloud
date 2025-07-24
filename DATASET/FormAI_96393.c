//FormAI DATASET v1.0 Category: Color Code Converter ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {
    char input[10];
    int red, green, blue;

    printf("Enter RGB color code in the format 'R,G,B': ");
    fgets(input, 10, stdin); // Get user input
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;
    
    // Split input into red, green, and blue values
    char *token = strtok(input, ",");
    red = atoi(token);
    token = strtok(NULL, ",");
    green = atoi(token);
    token = strtok(NULL, ",");
    blue = atoi(token);

    // Convert to hexadecimal
    char hex[7]; // Holds hexadecimal value in string format
    sprintf(hex, "#%02X%02X%02X", red, green, blue); // Converts RGB to Hex

    printf("Hexadecimal color code is: %s", hex);

    return 0;
}