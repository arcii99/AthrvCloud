//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* charToMorse(char c) {
    switch (c) {
        case 'A': return ".-";
        case 'B': return "-...";
        case 'C': return "-.-.";
        case 'D': return "-..";
        case 'E': return ".";
        case 'F': return "..-.";
        case 'G': return "--.";
        case 'H': return "....";
        case 'I': return "..";
        case 'J': return ".---";
        case 'K': return "-.-";
        case 'L': return ".-..";
        case 'M': return "--";
        case 'N': return "-.";
        case 'O': return "---";
        case 'P': return ".--.";
        case 'Q': return "--.-";
        case 'R': return ".-.";
        case 'S': return "...";
        case 'T': return "-";
        case 'U': return "..-";
        case 'V': return "...-";
        case 'W': return ".--";
        case 'X': return "-..-";
        case 'Y': return "-.--";
        case 'Z': return "--..";
    }
    return "";
}

char* textToMorse(char* text) {
    int size = strlen(text);
    char* result = (char*)malloc((size * 4) + 1);
    memset(result, 0, (size * 4) + 1);
    for (int i = 0; i < size; i++) {
        char* morse = charToMorse(toupper(text[i]));
        strcat(result, morse);
        if (i < size - 1) strcat(result, " ");
    }
    return result;
}

int main() {
    char text[] = "Hello World!";
    char* morse = textToMorse(text);
    printf("%s\n", morse);
    free(morse);
    return 0;
}