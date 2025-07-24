//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code table
const char *morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
                         "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

// Conversion function
void text_to_morse(char *text, char *morse_code) {
    int i, j, k;
    // Convert each character in the text to Morse code and append to morse_code string
    for (i = 0; text[i] != '\0'; i++) {
        // Only convert upper case letters
        if (text[i] >= 'A' && text[i] <= 'Z') {
            char *code = morse[text[i] - 'A'];
            for (j = 0; code[j] != '\0'; j++) {
                morse_code[k++] = code[j];
                morse_code[k++] = ' '; // Add space after each character
            }
            morse_code[k++] = ' '; // Add additional space after each letter
        }
    }
    // Add null terminator to end of morse_code string
    morse_code[k] = '\0'; 
}

// Main function
int main() {
    char text[50];
    char morse_code[200]; // Maximum length of Morse code for 50 characters of text
    printf("Enter text to convert: ");
    // Read input text from user
    fgets(text, 50, stdin);
    // Replace newline character added by fgets with null terminator
    text[strcspn(text, "\n")] = '\0';
    // Convert text to Morse code
    text_to_morse(text, morse_code);
    printf("Morse code: %s", morse_code);
    return 0;
}