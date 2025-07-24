//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

char *morse_code(char c) {
    switch(c) {
        case 'a':
        case 'A':
            return ".- ";
        case 'b':
        case 'B':
            return "-... ";
        case 'c':
        case 'C':
            return "-.-. ";
        case 'd':
        case 'D':
            return "-.. ";
        case 'e':
        case 'E':
            return ". ";
        case 'f':
        case 'F':
            return "..-. ";
        case 'g':
        case 'G':
            return "--. ";
        case 'h':
        case 'H':
            return ".... ";
        case 'i':
        case 'I':
            return ".. ";
        case 'j':
        case 'J':
            return ".--- ";
        case 'k':
        case 'K':
            return "-.- ";
        case 'l':
        case 'L':
            return ".-.. ";
        case 'm':
        case 'M':
            return "-- ";
        case 'n':
        case 'N':
            return "-. ";
        case 'o':
        case 'O':
            return "--- ";
        case 'p':
        case 'P':
            return ".--. ";
        case 'q':
        case 'Q':
            return "--.- ";
        case 'r':
        case 'R':
            return ".-. ";
        case 's':
        case 'S':
            return "... ";
        case 't':
        case 'T':
            return "- ";
        case 'u':
        case 'U':
            return "..- ";
        case 'v':
        case 'V':
            return "...- ";
        case 'w':
        case 'W':
            return ".-- ";
        case 'x':
        case 'X':
            return "-..- ";
        case 'y':
        case 'Y':
            return "-.-- ";
        case 'z':
        case 'Z':
            return "--.. ";
        case ' ':
            return "/ ";
        default:
            return "";
    }
}

int main() {
    char quote[] = "\"O Romeo, Romeo, wherefore art thou Romeo?\"";
    char morse_quote[1000] = "";
    int i;
    for(i = 0; i < strlen(quote); i++) {
        char *morse = morse_code(quote[i]);
        strcat(morse_quote, morse);
    }
    printf("Morse code translation of Romeo's famous quote:\n%s\n", morse_quote);
    return 0;
}