//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: enthusiastic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", 
"--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

char* text_to_morse(char* text) {
    char* morse = "";
    for(int i = 0; i < strlen(text); i++) {
        char c = toupper(text[i]);
        if(c >= 'A' && c <= 'Z') {
            morse = strcat(morse, morse_code[c - 'A']);
            morse = strcat(morse, " ");
        }
        else if(c >= '0' && c <= '9') {
            morse = strcat(morse, morse_code[c - '0' + 26]);
            morse = strcat(morse, " ");
        }
        else if(c == ' ') {
            morse = strcat(morse, "/");
            morse = strcat(morse, " ");
        }
    }
    return morse;
}

int main() {
    printf("Enter text to convert to Morse Code:\n");
    char text[100];
    fgets(text, 100, stdin);
    printf("\nMorse Code:\n%s", text_to_morse(text));
    return 0;
}