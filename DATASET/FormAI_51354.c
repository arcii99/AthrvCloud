//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: complex
#include <stdio.h>
#include <string.h>

// Define Morse code table
char codeTable[36][6] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"};

// Define character set
char charSet[37] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

// Function to convert given character into Morse code
char* charToMorse(char c) {
    int i;
    // If character is space, return space Morse code
    if (c == ' ') {
        return "  ";
    }
    // Convert lowercase character to uppercase
    if (c >= 'a' && c <= 'z') {
        c = c - 32; // Subtract 32 to convert to uppercase
    }
    // Find index of character in character set
    for (i = 0; i < 37; i++) {
        if (charSet[i] == c) {
            break;
        }
    }
    // If character is not found in character set, return null
    if (i == 37) {
        return NULL;
    }
    // Return Morse code corresponding to the character
    return codeTable[i];
}

int main() {
    char sentence[1000];
    int i, j, len;
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);
    len = strlen(sentence);
    // Convert each character in given sentence into Morse code character
    for (i = 0; i < len; i++) {
        char* code = charToMorse(sentence[i]);
        // If character is not found in character set, print error message and exit
        if (code == NULL) {
            printf("ERROR: Invalid character '%c' detected!\n", sentence[i]);
            return 1;
        }
        // If space character is detected, print new line
        if (code[0] == ' ' && code[1] == ' ') {
            printf("\n");
        } else {
            // Otherwise, print Morse code sequence separated by space
            for (j = 0; j < strlen(code); j++) {
                printf("%c ", code[j]);
            }
        }
    }
    return 0;
}