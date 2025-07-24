//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: romantic
#include <stdio.h>
#include <string.h>

void morseCode(char text[]) {
    char morse[37][6] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};
    char converted[200] = "";
    int i, j, k = 0, len;

    len = strlen(text);

    for(i = 0; i < len; i++) {
        if(text[i] == ' ') {
            strcat(converted, "\t");
        }
        else {
            for(j = 0; j < 37; j++) {
                if(tolower(text[i]) == 97+j) {
                    strcat(converted, morse[j]);
                    strcat(converted, " ");
                }
            }
        }
    }

    printf("%s\n", converted);
}

int main() {
    printf("Welcome to the Romantic Morse Code Converter!\n");

    printf("Please type in your message and watch as it gets converted to Morse code, one dot and dash at a time:\n");

    char input[200];

    fgets(input, 200, stdin);

    printf("Oh my darling, let me convert that for you. Here it is in Morse code:\n");

    morseCode(input);

    printf("There you have it, my love. Your message, now in Morse code. I hope it sings to your heart just as it does to mine.\n");

    return 0;
}