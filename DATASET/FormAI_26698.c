//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 100
#define MAX_MORSE_SIZE 500

// Morse code table
const char *MORSE_TABLE[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"};

// Function to convert a character to Morse code
void char_to_morse(char c, char morse[MAX_MORSE_SIZE]) {
    if (c == ' ') {
        strcat(morse, " ");
    } else {
        strcat(morse, MORSE_TABLE[c - 'A']);
        strcat(morse, " ");
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    char morse[MAX_MORSE_SIZE] = "";
    int i;
    
    printf("Enter text to convert to Morse code: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    
    // Remove new line character from input
    input[strcspn(input, "\n")] = 0;
    
    // Convert each character to Morse code
    for (i = 0; i < strlen(input); i++) {
        char_to_morse(toupper(input[i]), morse);
    }
    
    // Print the Morse code
    printf("Morse code: %s\n", morse);
    
    return 0;
}