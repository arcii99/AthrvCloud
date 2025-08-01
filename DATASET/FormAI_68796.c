//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

char* morse_code(char c) {
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
        case '0': return "-----";
        case '1': return ".----";
        case '2': return "..---";
        case '3': return "...--";
        case '4': return "....-";
        case '5': return ".....";
        case '6': return "-....";
        case '7': return "--...";
        case '8': return "---..";
        case '9': return "----.";
        default: return " ";
    }
}

void text_to_morse(char text[]) {
    for(int i=0; text[i]!='\0'; i++) {
        char upper = toupper(text[i]);
        char *morse = morse_code(upper);
        printf("%s ", morse);
    }
    printf("\n");
}

int main() {
    char text[100];
    printf("Enter text to convert to Morse code: ");
    fgets(text, sizeof(text), stdin);
    printf("Morse code: ");
    text_to_morse(text);

    return 0;
}