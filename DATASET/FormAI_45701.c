//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: unmistakable
#include <stdio.h>
#include <string.h>

char morseCode[36][6] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
    "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
};

char morseTranslate(char value) {
    if (value == ' ') {
        return '/';
    } else {
        return morseCode[value-'A'][0];
    }
}

void textToMorse(char *msg) {
    int len = strlen(msg);
    for(int i = 0; i < len; i++) {
        char value = toupper(msg[i]);
        if (value < 'A' || value > 'Z') {
            continue;
        }

        char *morse = morseCode[value-'A'];
        
        while(*morse != '\0') {
             putchar(*morse);
             putchar(' ');
             morse++;
        }
        putchar('/');
        putchar(' ');  
    }
}

int main() {
    char message[100];
    printf("Enter a message to convert to Morse code: ");
    fgets(message, 100, stdin);

    printf("\nTranslated message: ");
    textToMorse(message);

    return 0;
}