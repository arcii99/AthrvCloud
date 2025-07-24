//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* textToMorseCode(char*);

int main() {
    char message[100];
    printf("Oh Romeo, Oh Romeo, whisper your sweet nothings to me in text:\n");
    fgets(message, sizeof(message), stdin);
    printf("I shall convert it into Morse code for you:\n");
    printf("%s\n", textToMorseCode(message));
    printf("Alas, my dear Romeo, our love may suffer the same fate as this message, lost in the transmission.\n");
    return 0;
}

char* textToMorseCode(char* message) {
    char *morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
                        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                        "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---",
                        "...--", "....-", ".....", "-....", "--...", "---..", "----.", "/", "\0"};
    char *alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 /";
    char* output = malloc(5*sizeof(char)*strlen(message));
    char* letter;
    for(int i = 0; i < strlen(message); i++) {
        letter = strchr(alphabets, toupper(message[i]));
        if(letter != NULL) {
            strcat(output, morseCode[letter - alphabets]);
            strcat(output, " ");
        }
    }
    return output;
}