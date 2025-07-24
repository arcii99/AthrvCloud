//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: protected
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    printf("Enter a message to be converted to Morse code: ");
    fgets(message, sizeof(message), stdin);
    
    int i, j;
    const char *morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
    const char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char convertedMessage[1000] = "";

    for (i = 0; i < strlen(message) - 1; i++) {
        if (message[i] == ' ') {
            strcat(convertedMessage, " / ");
        } else {
            for (j = 0; j < strlen(letters); j++) {
                if (toupper(message[i]) == letters[j]) {
                    strcat(convertedMessage, morseCode[j]);
                    strcat(convertedMessage, " ");
                    break;
                }
            }
        }
    }
    
    printf("The message converted to Morse code is: %s", convertedMessage);
    
    return 0;
}