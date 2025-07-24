//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code lookup table
const char *morse_lookup[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", 
    ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

// Function to convert a letter to Morse code
char *letter_to_morse(char letter) {
    int index = letter - 'A';
    if (index >= 0 && index <= 25) {
        return morse_lookup[index];
    }
    return "";
}

// Function to convert a string to Morse code
void text_to_morse(char *text) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        char letter = toupper(text[i]);
        if (letter == ' ') {
            printf("  ");
        } else {
            printf("%s ", letter_to_morse(letter));
        }
    }
    printf("\n");
}

// Main function
int main() {
    char text[100];
    printf("Enter text to convert to Morse code: ");
    scanf("%[^\n]", text);
    text_to_morse(text);
    return 0;
}