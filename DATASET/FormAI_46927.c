//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

// Function to convert a single character to Morse code
char* convertCharToMorse(char c) {
    // Array of Morse code characters
    char* morseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                          ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", 
                          ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    // Array of characters
    char* characters[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", 
                          "j", "k", "l", "m", "n", "o", "p", "q", 
                          "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    // Convert character to lowercase
    c = tolower(c);
    // Search for character in the characters array
    for(int i=0; i < 26; i++) {
        if(characters[i][0] == c) {
            return morseCodes[i];
        }
    }
    return "";
}

int main() {
    // Read input string from user
    char input[100];
    printf("Enter text to convert to Morse code: ");
    scanf("%[^\n]s", input);
    // Convert input string to Morse code
    int length = strlen(input);
    for(int i=0; i < length; i++) {
        // Convert each character to Morse code
        char* morseCode = convertCharToMorse(input[i]);
        // Print Morse code for each character
        printf("%s ", morseCode);
    }
    printf("\n");
    return 0;
}