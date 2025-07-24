//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 256
#define DOT '.'
#define DASH '-'

char* morse_code(char c);

int main() {
    char message[MAX_LENGTH];
    printf("Enter message to convert to Morse code: ");
    fgets(message, MAX_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0'; // remove newline character

    int message_length = strlen(message);
    for (int i = 0; i < message_length; i++) {
        char c = message[i];
        if (c == ' ') {
            printf(" ");
        } else {
            char *code = morse_code(c);
            printf("%s ", code);
        }
    }

    return 0;
}

char* morse_code(char c) {
    switch(toupper(c)) {
        case 'A':
            return ".-";
        case 'B':
            return "-...";
        case 'C':
            return "-.-.";
        case 'D':
            return "-..";
        case 'E':
            return ".";
        case 'F':
            return "..-.";
        case 'G':
            return "--.";
        case 'H':
            return "....";
        case 'I':
            return "..";
        case 'J':
            return ".---";
        case 'K':
            return "-.-";
        case 'L':
            return ".-..";
        case 'M':
            return "--";
        case 'N':
            return "-.";
        case 'O':
            return "---";
        case 'P':
            return ".--.";
        case 'Q':
            return "--.-";
        case 'R':
            return ".-.";
        case 'S':
            return "...";
        case 'T':
            return "-";
        case 'U':
            return "..-";
        case 'V':
            return "...-";
        case 'W':
            return ".--";
        case 'X':
            return "-..-";
        case 'Y':
            return "-.--";
        case 'Z':
            return "--..";
        default:
            return "";
    }
}