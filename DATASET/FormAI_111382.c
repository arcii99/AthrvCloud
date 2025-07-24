//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: complete
#include <stdio.h>
#include <string.h>

char* convertToMorse(char*);

int main() {
    char input[100];
    printf("Enter a message to convert to Morse code:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character from input
    
    char* morseCode = convertToMorse(input);
    printf("\nMorse code:\n%s", morseCode);
    
    return 0;
}

char* convertToMorse(char* message) {
    char* morseCode = "";
    char* alphabet[26] = {".-","-...","-.-.","-..",".","..-.","--.",
                          "....","..",".---","-.-",".-..","--","-.",
                          "---",".--.","--.-",".-.","...","-","..-",
                          "...-",".--","-..-","-.--","--.."};
    
    for(int i = 0; i < strlen(message); i++) {
        char c = message[i];
        if(c != ' ') {
            int index = toupper(c) - 'A';
            char* code = alphabet[index];
            morseCode = strcat(morseCode, code);
        }
        if(i != strlen(message) - 1) {
            morseCode = strcat(morseCode, " ");
        }
    }
    
    return morseCode;
}