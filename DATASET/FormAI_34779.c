//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: synchronous
#include <stdio.h>
#include <string.h>

typedef struct {
    char letter;
    char *code;
} Morse;

int main() {

    Morse morseCode[] = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."}, 
        {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, 
        {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, 
        {'Y', "-.--"}, {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, 
        {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {' ', "/"} 
    };
    
    char input[100];
    printf("Enter a message to convert to Morse Code:\n");
    gets(input);
    int inputLength = strlen(input);
    char output[inputLength*5+1]; /* mose code letter can be up to 5 characters long */
    
    int i, j, k;
    for (i=0; i<inputLength; i++) {
        char letter = toupper(input[i]);
        int morseIndex = -1;
        for (j=0; j<sizeof(morseCode)/sizeof(Morse); j++) {
            if (letter == morseCode[j].letter) {
                morseIndex = j;
                break;
            }
        }
        if (morseIndex == -1) {
            printf("Invalid character: %c\n", letter);
            return 1;
        }
        strcat(output, morseCode[morseIndex].code);
        strcat(output, " ");
    }
    printf("Morse Code:\n%s\n", output);

    return 0;
}