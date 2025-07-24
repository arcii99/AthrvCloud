//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: realistic
#include <stdio.h>
#include <string.h>

#define MAX_MORSE_CODE_LEN 20 // maximum length of a Morse code sequence

// Morse code table (key-value pairs)
const char* MORSE_CODE_TABLE[] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--.."  // Z
};

int main() {
    char text[100]; // input text buffer
    char morseCode[MAX_MORSE_CODE_LEN]; // Morse code buffer
    int morseCodeLen; // Morse code length
    
    printf("Enter a string to convert to Morse code:\n");
    fgets(text, sizeof(text), stdin); // read input string from keyboard
    
    // process each character in the input string
    for (int i = 0; i < strlen(text); i++) {
        char c = toupper(text[i]); // convert character to upper case
        
        if (c >= 'A' && c <= 'Z') { // if character is a letter
            int idx = c - 'A'; // get index of Morse code sequence in table
            strcpy(morseCode, MORSE_CODE_TABLE[idx]); // copy Morse code sequence to buffer
            morseCodeLen = strlen(morseCode);
            
            // output Morse code sequence
            for (int j = 0; j < morseCodeLen; j++) {
                printf("%c ", morseCode[j]); // print Morse code character
            }
        }
        else if (c == ' ') { // if character is a space
            printf("/ "); // output slash character to denote a space
        }
        else { // if character is not a letter or space
            printf("%c ", c); // output character as is (not in Morse code)
        }
    }
    
    printf("\n"); // print a new line to separate output from input
    return 0; // exit program
}