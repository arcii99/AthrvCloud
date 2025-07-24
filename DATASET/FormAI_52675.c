//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: thoughtful
#include <stdio.h>
#include <string.h>

// ASCII art generator function
void ascii_art_generator(char input[]) {
    // Array of ASCII characters for generating the art
    char ascii[] = {'@', '#', '%', '&', '*', '+', '=', '-', ':', '.', ' '};
    
    int len = strlen(input);
    int row, col, index;
    for (row = 0; row < 7; row++) {
        for (col = 0; col < len; col++) {
            // Get the ASCII index for the current character in the input string
            index = (int)input[col] % 11; // using modulo operator to ensure the index is within range
            
            // Print the corresponding ASCII character in the art
            printf("%c", ascii[index]);
        }
        
        // Move to the next row
        printf("\n");
    }
}

int main() {
    // Example usage
    char input[] = "C Text to ASCII Art Generator";
    ascii_art_generator(input);
    return 0;
}