//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

// function to convert a single character to its morse code equivalent
char* char_to_morse(const char c) {
    switch(c) {
        case 'a':
        case 'A':
            return ".-";
        case 'b':
        case 'B':
            return "-...";
        case 'c':
        case 'C':
            return "-.-.";
        case 'd':
        case 'D':
            return "-..";
        case 'e':
        case 'E':
            return ".";
        case 'f':
        case 'F':
            return "..-.";
        case 'g':
        case 'G':
            return "--.";
        case 'h':
        case 'H':
            return "....";
        case 'i':
        case 'I':
            return "..";
        case 'j':
        case 'J':
            return ".---";
        case 'k':
        case 'K':
            return "-.-";
        case 'l':
        case 'L':
            return ".-..";
        case 'm':
        case 'M':
            return "--";
        case 'n':
        case 'N':
            return "-.";
        case 'o':
        case 'O':
            return "---";
        case 'p':
        case 'P':
            return ".--.";
        case 'q':
        case 'Q':
            return "--.-";
        case 'r':
        case 'R':
            return ".-.";
        case 's':
        case 'S':
            return "...";
        case 't':
        case 'T':
            return "-";
        case 'u':
        case 'U':
            return "..-";
        case 'v':
        case 'V':
            return "...-";
        case 'w':
        case 'W':
            return ".--";
        case 'x':
        case 'X':
            return "-..-";
        case 'y':
        case 'Y':
            return "-.--";
        case 'z':
        case 'Z':
            return "--..";
        default:
            return "/";
    }
}

// function to convert text to morse code
void text_to_morse(const char* text, char* morse) {
    char c;
    size_t len = strlen(text);
    size_t i, j;
    for (i = 0, j = 0; i < len; i++) {
        c = text[i];
        if (c == ' ') {
            morse[j++] = '/';
        } else {
            char* morse_char = char_to_morse(c);
            size_t morse_len = strlen(morse_char);
            memcpy(&morse[j], morse_char, morse_len);
            j += morse_len;
            morse[j++] = ' ';
        }
    }
    morse[j] = '\0';
}

int main() {
    char text[100];
    char morse[500];
    printf("Enter the text to convert to Morse code:\n");
    fgets(text, sizeof(text), stdin);
    text_to_morse(text, morse);
    printf("Morse code: %s\n", morse);
    return 0;
}