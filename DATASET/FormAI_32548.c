//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char message[1000];
    int i, j;
    char* morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"}; // morse code table
    
    printf("Enter a message: ");
    fgets(message, 1000, stdin); // reading input message
    
    printf("Morse code: ");
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) { // if character is alphabetic
            int index = tolower(message[i]) - 'a';
            printf("%s ", morseCode[index]);
        }
        else if (message[i] == ' ') { // if character is space
            printf("/ ");
        }
    }
    
    return 0;
}