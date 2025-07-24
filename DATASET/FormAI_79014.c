//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[50]; // Maximum length of input is 50 characters
    printf("Enter text to convert to ASCII art:\n");
    scanf("%[^\n]", input); // Read input until newline is encountered
    
    char *characters[] = {"@", "#", "$", "%", "^", "&", "*", "(", ")", "-", "_", "=", "+", "[", "]", "{", "}", "|", ":", ";", "<", ">", ",", ".", "?"}; // Array of ASCII characters
    int numChars = sizeof(characters) / sizeof(characters[0]); // Determine number of characters in array
    
    for (int i = 0; input[i] != '\0'; i++) {
        int asciiVal = (int)input[i]; // Get ASCII value of current character
        if (asciiVal < 32 || asciiVal > 122) { // Characters outside printable ASCII range
            printf("\nInvalid character: '%c'", input[i]);
        }
        else {
            int index = (asciiVal - 32) % numChars; // Map ASCII value to index in character array
            printf("%s", characters[index]);
        }
    }
    return 0;
}