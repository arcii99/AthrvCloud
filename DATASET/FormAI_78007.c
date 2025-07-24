//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

// Morse code mapping for letters and numbers
char *morse_code[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                       ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
                       "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", 
                       ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

// Helper function to convert a letter or number to morse code
void convert_to_morse_code(char letter) {
    if (letter == ' ') {
        printf("  "); // Two spaces for a word boundary in Morse code
        return;
    }
    
    if (letter >= 'A' && letter <= 'Z') {
        letter = letter - 'A'; // Convert to 0-based index
        printf("%s ", morse_code[letter]);
    } else if (letter >= '0' && letter <= '9') {
        letter = letter - '0' + 26; // Convert to 0-based index for numbers
        printf("%s ", morse_code[letter]);
    }
}

// Main function
int main() {
    char message[100];
    printf("Enter a message to convert to Morse code: ");
    fgets(message, 100, stdin); // Read input string

    printf("Morse code: ");
    for (int i = 0; i < strlen(message); i++) {
        convert_to_morse_code(toupper(message[i])); // Convert each letter to Morse code
    }
    printf("\n");
    return 0;
}