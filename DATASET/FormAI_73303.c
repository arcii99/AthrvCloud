//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: relaxed
#include <stdio.h>
#include <string.h>

#define DOT "."
#define DASH "-"
#define SPACE " "
#define MAX_LENGTH 100

char* morse_code(char ch) {
    int i;
    char* code;

    switch (ch) {
        case 'a':
        case 'A':
            code = ".-";
            break;
        case 'b':
        case 'B':
            code = "-...";
            break;
        case 'c':
        case 'C':
            code = "-.-.";
            break;
        case 'd':
        case 'D':
            code = "-..";
            break;
        case 'e':
        case 'E':
            code = ".";
            break;
        case 'f':
        case 'F':
            code = "..-.";
            break;
        case 'g':
        case 'G':
            code = "--.";
            break;
        case 'h':
        case 'H':
            code = "....";
            break;
        case 'i':
        case 'I':
            code = "..";
            break;
        case 'j':
        case 'J':
            code = ".---";
            break;
        case 'k':
        case 'K':
            code = "-.-";
            break;
        case 'l':
        case 'L':
            code = ".-..";
            break;
        case 'm':
        case 'M':
            code = "--";
            break;
        case 'n':
        case 'N':
            code = "-.";
            break;
        case 'o':
        case 'O':
            code = "---";
            break;
        case 'p':
        case 'P':
            code = ".--.";
            break;
        case 'q':
        case 'Q':
            code = "--.-";
            break;
        case 'r':
        case 'R':
            code = ".-.";
            break;
        case 's':
        case 'S':
            code = "...";
            break;
        case 't':
        case 'T':
            code = "-";
            break;
        case 'u':
        case 'U':
            code = "..-";
            break;
        case 'v':
        case 'V':
            code = "...-";
            break;
        case 'w':
        case 'W':
            code = ".--";
            break;
        case 'x':
        case 'X':
            code = "-..-";
            break;
        case 'y':
        case 'Y':
            code = "-.--";
            break;
        case 'z':
        case 'Z':
            code = "--..";
            break;
        case '1':
            code = ".----";
            break;
        case '2':
            code = "..---";
            break;
        case '3':
            code = "...--";
            break;
        case '4':
            code = "....-";
            break;
        case '5':
            code = ".....";
            break;
        case '6':
            code = "-....";
            break;
        case '7':
            code = "--...";
            break;
        case '8':
            code = "---..";
            break;
        case '9':
            code = "----.";
            break;
        case '0':
            code = "-----";
            break;
        case ' ':
            code = "/";
            break;
        default:
            code = "";
    }

    return code;
}

int main() {
    char text[MAX_LENGTH];
    int i, j;

    printf("Please enter some text: ");
    fgets(text, MAX_LENGTH, stdin);

    text[strcspn(text, "\r\n")] = 0; // Remove trailing newline character

    printf("Morse code for the text is:\n");

    for (i = 0; i < strlen(text); i++) {
        char ch = text[i];
        char* code = morse_code(ch);
        printf("%s", code);

        if (i != strlen(text) - 1 && ch != ' ') {
            printf("%s", SPACE);
        }
    }

    printf("\n");

    return 0;
}