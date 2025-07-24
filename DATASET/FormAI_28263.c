//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: medieval
#include <stdio.h>
#include <string.h>

// Function to convert a text character into Morse code
char* toMorse(char letter) {
    switch (letter) {
        case 'a':
        case 'A':
            return ".-";
            break;
        case 'b':
        case 'B':
            return "-...";
            break;
        case 'c':
        case 'C':
            return "-.-.";
            break;
        case 'd':
        case 'D':
            return "-..";
            break;
        case 'e':
        case 'E':
            return ".";
            break;
        case 'f':
        case 'F':
            return "..-.";
            break;
        case 'g':
        case 'G':
            return "--.";
            break;
        case 'h':
        case 'H':
            return "....";
            break;
        case 'i':
        case 'I':
            return "..";
            break;
        case 'j':
        case 'J':
            return ".---";
            break;
        case 'k':
        case 'K':
            return "-.-";
            break;
        case 'l':
        case 'L':
            return ".-..";
            break;
        case 'm':
        case 'M':
            return "--";
            break;
        case 'n':
        case 'N':
            return "-.";
            break;
        case 'o':
        case 'O':
            return "---";
            break;
        case 'p':
        case 'P':
            return ".--.";
            break;
        case 'q':
        case 'Q':
            return "--.-";
            break;
        case 'r':
        case 'R':
            return ".-.";
            break;
        case 's':
        case 'S':
            return "...";
            break;
        case 't':
        case 'T':
            return "-";
            break;
        case 'u':
        case 'U':
            return "..-";
            break;
        case 'v':
        case 'V':
            return "...-";
            break;
        case 'w':
        case 'W':
            return ".--";
            break;
        case 'x':
        case 'X':
            return "-..-";
            break;
        case 'y':
        case 'Y':
            return "-.--";
            break;
        case 'z':
        case 'Z':
            return "--..";
            break;
        case ' ':
            return "   ";
            break;
        default:
            return "";
            break;
    }
}

int main() {
    char text[100];
    printf("What message would thou like to convert to Morse code?\n");
    fgets(text, 100, stdin);
    int len = strlen(text);
    printf("\nThou hast entered: %s\n\n", text);

    printf("The Morse code for thy message is: \n");
    for (int i = 0; i < len; i++) {
        char letter = text[i];
        char* morse = toMorse(letter);
        printf("%s ", morse);
    }
    printf("\n");

    return 0;
}