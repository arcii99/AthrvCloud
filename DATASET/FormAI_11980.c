//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: scalable
#include <stdio.h>
#include <string.h>

char *MORSE_CODE[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", 
    "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
    "-.--", "--.."
};

char* text_to_morse(char *text) {
    int len = strlen(text);
    char *morse = malloc(len*5+1); 
    morse[0] = '\0';

    for(int i=0; i<len; i++) { 
        if(text[i] == ' ') {  
            strcat(morse, "/");
        } else if(text[i] >= 'A' && text[i] <= 'Z') {
            strcat(morse, MORSE_CODE[text[i] - 'A']);
        } else if(text[i] >= 'a' && text[i] <= 'z') { 
            strcat(morse, MORSE_CODE[text[i] - 'a']);
        } else { 
            strcat(morse, " "); 
        }
        strcat(morse, " ");
    }
    return morse;
}

int main() {
    char text[100];
    printf("Enter a text to convert to Morse code: ");
    fgets(text, 100, stdin);
    char *morse = text_to_morse(text);
    printf("Morse code: %s\n", morse);
    free(morse);
    return 0;
}