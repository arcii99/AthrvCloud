//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_WIDTH 80

// Define ASCII art characters
const char *ascii_art[] = {
    "     _      _____ _____ _____ _____ ____  _ ",
    " ___|_|___ | __  |  |  |     |     |    \\|_|",
    "|  _| |  _|  __|  |  |__|  |  |  |   __| | |",
    "|_| |_|_| |_____|_____|_____|_____|____/|_|"
};

int main() {
    char input[MAX_WIDTH];
    int input_length, ascii_art_length;
    
    ascii_art_length = sizeof(ascii_art) / sizeof(ascii_art[0]);
    
    printf("Enter a string to convert to ASCII art:\n");
    fgets(input, MAX_WIDTH, stdin);
    input_length = strlen(input);
    
    // Remove newline character from input
    if (input[input_length - 1] == '\n')
        input[input_length - 1] = '\0';
        
    // Center input within ASCII art width
    int padding = (MAX_WIDTH - input_length) / 2;
    
    // Print ASCII art characters
    for (int i = 0; i < ascii_art_length; i++) {
        printf("%*s", padding, ""); // Print padding
        for (int j = 0; j < input_length; j++) {
            printf("%c ", input[j]); // Print input characters
        }
        printf("%s\n", ascii_art[i]); // Print ASCII art line
    }
    
    return 0;
}