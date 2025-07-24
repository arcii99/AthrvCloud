//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: single-threaded
#include <stdio.h>
#include <string.h>

// Morse code conversion lookup table
const char *morse_table[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/",
        ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// Function to convert ASCII character to Morse code
void ascii_to_morse(char *ascii, char *morse) {
    int i, j;

    for(i=0; ascii[i] != '\0'; i++) { // Loop through each ASCII character
        if(ascii[i] == ' ') {
            strcat(morse, "/");
        } else {
            // Convert to uppercase
            if(ascii[i] >= 'a' && ascii[i] <= 'z') {
                ascii[i] = ascii[i] - 32;
            }

            // Find index of character in Morse code lookup table
            j = ascii[i] - 'A';

            // Append Morse code to output string
            strcat(morse, morse_table[j]);
            strcat(morse, " ");
        }
    }
}

int main() {
    char ascii[100];
    char morse[500] = "";

    // Get user input
    printf("Enter a string: ");
    fgets(ascii, 100, stdin);
    ascii[strcspn(ascii, "\n")] = '\0';

    // Convert ASCII to Morse code
    ascii_to_morse(ascii, morse);

    // Print Morse code output
    printf("Morse code: %s\n", morse);

    return 0;
}