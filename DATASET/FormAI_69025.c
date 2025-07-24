//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: systematic
#include <stdio.h>
#include <string.h>

int main() {
    // Define the ASCII art character set
    char ascii_chars[] = {' ', '.', ':', '–', '+', '*', '#', '@'};
    int ascii_range = strlen(ascii_chars);

    // User input prompt
    printf("Enter text to convert to ASCII art: ");

    // Get user input
    char text[100];
    fgets(text, sizeof(text), stdin);

    // Remove newline character from input
    text[strcspn(text, "\n")] = 0;

    // Get length of user input
    int text_length = strlen(text);

    // Iterate through user input string 
    for (int i=0; i<text_length; i++) {
        // Get ASCII code of character
        int ascii_code = (int) text[i];
        // Convert ASCII code to index in our ASCII art character set
        int char_index = (int) (ascii_code / (256 / ascii_range));
        // Print the corresponding ASCII art character
        printf("%c", ascii_chars[char_index]);
    }
    printf("\n");
    
    return 0;
}