//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: realistic
#include <stdio.h>
#include <string.h>

// Morse code lookup table
const char *MORSE_TABLE[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
    "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--.."
};

// Corresponding English characters
const char *ENGLISH_CHARS = "abcdefghijklmnopqrstuvwxyz";

// Function to convert a single character to Morse code
void convert_to_morse(char c)
{
    char lowercase_c = tolower(c); // Convert to lowercase
    
    // Find the index of the character in the English character array
    int index = strchr(ENGLISH_CHARS, lowercase_c) - ENGLISH_CHARS;
    
    if (index < 0 || index > 25) {
        printf(" ");
        return;
    }
    
    // Print the Morse code representation of the character
    printf("%s ", MORSE_TABLE[index]);
}

int main()
{
    char text[1000];
    
    printf("Enter text to convert to Morse code: ");
    fgets(text, sizeof(text), stdin);
    strtok(text, "\n"); // Remove newline character
    
    printf("Morse code: ");
    
    // Iterate through each character in the input string
    for (int i = 0; i < strlen(text); i++) {
        convert_to_morse(text[i]);
    }
    
    printf("\n");
    
    return 0;
}