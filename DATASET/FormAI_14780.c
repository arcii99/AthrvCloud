//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: beginner-friendly
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Define Morse code table as 2D array
const char* morseCodeTable[26][2] = {
    {"A", ".-"}, {"B", "-..."}, {"C", "-.-."}, {"D", "-.."},
    {"E", "."}, {"F", "..-."}, {"G", "--."}, {"H", "...."},
    {"I", ".."}, {"J", ".---"}, {"K", "-.-"}, {"L", ".-.."},
    {"M", "--"}, {"N", "-."}, {"O", "---"}, {"P", ".--."},
    {"Q", "--.-"}, {"R", ".-."}, {"S", "..."}, {"T", "-"},
    {"U", "..-"}, {"V", "...-"}, {"W", ".--"}, {"X", "-..-"},
    {"Y", "-.--"}, {"Z", "--.."}
};

// Function to convert a single character to Morse code
void convertToMorse(char ch) {
    // Convert to upper case for simplicity
    ch = toupper(ch);
    int index = ch - 'A';  // Determine array index based on character
    if (index >= 0 && index <= 25) {  // If it is a valid character
        printf("%s ", morseCodeTable[index][1]);  // Print its Morse code
    } else {
        printf("%c ", ch);  // If not a letter, just print the character
    }
}

// Function to convert a string to Morse code
void convertStringToMorse(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        convertToMorse(str[i]);  // Call function to convert each character
    }
    printf("\n");  // Add newline at end for readability
}

int main() {
    char phrase[100];  // Declare a character array to hold user input
    printf("Enter a phrase to convert to Morse code: ");
    // Use fgets to avoid buffer overflow
    fgets(phrase, sizeof(phrase), stdin);
    printf("Morse code: ");
    convertStringToMorse(phrase);
    return 0;
}