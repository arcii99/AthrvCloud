//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: optimized
#include <stdio.h>
#include <string.h>

void morseCode(char message[]) {
    char* morseCharacters[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","|"};
    char* alphaCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    int messageLength = strlen(message);

    for(int i = 0; i < messageLength; i++) {
        for(int j = 0; j < 27; j++) {
            if(toupper(message[i]) == alphaCharacters[j]) {
                printf("%s ", morseCharacters[j]);
            }
        }
    }
}

int main() {
    char message[100];

    printf("Enter text to convert to Morse Code: ");
    fgets(message, 100, stdin);

    printf("Morse Code Output: ");
    morseCode(message);

    return 0;
}