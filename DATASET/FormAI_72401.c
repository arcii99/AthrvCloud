//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: protected
#include <stdio.h>
#include <string.h>

// Function to convert text to morse code
void textToMorse(char input[], char output[]) {
    // Morse code look-up table
    char *morseCode[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    
    int len = strlen(input);
    int i, j;
    for (i = 0; i < len; i++) {
        if (input[i] == ' ') { // space represents end of a letter
            output[strlen(output) - 1] = '|'; // use '|' to separate letters in morse code
            output[strlen(output) - 1] = ' '; // use space to separate words in morse code
        } else {
            int index = input[i] - 'a'; // get corresponding index for morse code array
            char *code = morseCode[index];
            int codeLen = strlen(code);
            for (j = 0; j < codeLen; j++) {
                output[strlen(output)] = code[j];
                output[strlen(output)] = ' '; // use space to separate dots and dashes in morse code
            }
        }
    }
}

int main() {
    char input[100], output[500];
    
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character from input
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
    
    // Convert text to morse code
    textToMorse(input, output);
    printf("Morse code: %s", output);
    
    return 0;
}