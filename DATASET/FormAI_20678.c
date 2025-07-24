//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Cryptic
#include <stdio.h>
#include <string.h>

char morse[26][10] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}; // Morse code table for letters

char* convertToMorse(char* message) {
    char* morseCode = (char*) malloc(sizeof(char) * 500); // allocate memory for morse code string
    char* token;
    char delimiter[] = " ";
    int i = 0, j = 0;
    token = strtok(message, delimiter); // tokenize message by space delimiter

    while(token != NULL) { // loop through each word
        int len = strlen(token); // get length of word
        for(i = 0; i < len; i++) { // loop through each character in word
            if(token[i] >= 'a' && token[i] <= 'z') { // convert to uppercase
                token[i] = token[i] - 32;
            }
            j += sprintf(morseCode + j, "%s/", morse[token[i] - 'A']); // concatenate morse code for character
        }
        j += sprintf(morseCode + j, " "); // add space between words
        token = strtok(NULL, delimiter); // get next word
    }
    morseCode[j - 1] = '\0'; // remove last space in morse code string
    return morseCode; // return morse code string
}

int main() {
    char message[500];
    printf("Enter a message to convert to Morse code: ");
    scanf("%[^\n]", message); // read message from user
    char* morseCode = convertToMorse(message); // convert message to morse code
    printf("Morse code: %s", morseCode); // print morse code
    free(morseCode); // free memory allocated for morse code string
    return 0;
}