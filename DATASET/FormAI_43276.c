//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: brave
#include <stdio.h>
#include <string.h>

// Morse code structure
struct MorseCode {
    char character;
    char* code;
};

// Define Morse Code
struct MorseCode morseCode[] = {
    {'A',".-"}, {'B',"-..."}, {'C',"-.-."}, {'D',"-.."}, {'E',"."}, {'F',"..-."},
    {'G',"--."}, {'H',"...."}, {'I',".."}, {'J',".---"}, {'K',"-.-"}, {'L',".-.."},
    {'M',"--"}, {'N',"-."}, {'O',"---"}, {'P',".--."}, {'Q',"--.-"}, {'R',".-."},
    {'S',"..."}, {'T',"-"}, {'U',"..-"}, {'V',"...-"}, {'W',".--"}, {'X',"-..-"},
    {'Y',"-.--"}, {'Z',"--.."}, {'0',"-----"}, {'1',".----"}, {'2',"..---"},
    {'3',"...--"}, {'4',"....-"}, {'5',"....."}, {'6',"-...."}, {'7',"--..."},
    {'8',"---.."}, {'9',"----."}
};

int main() {
    char input[100], morse[500];
    int i, j, k;

    // Get user input
    printf("Enter text to be converted to Morse Code: ");
    gets(input);

    // Convert input to Morse code
    for (i = 0; i < strlen(input); i++) {
        // Check if input is a space or not
        if (input[i] == ' ') {
            strcat(morse, " ");
        } else {
            // Convert input to Morse code
            for (j = 0; j < 36; j++) {
                if (morseCode[j].character == input[i]) {
                    strcat(morse, morseCode[j].code);
                    strcat(morse, " ");
                }
            }
        }   
    }

    // Print Morse code
    printf("Morse code: %s\n", morse);

    return 0;
}