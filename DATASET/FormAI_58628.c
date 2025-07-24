//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: interoperable
#include <stdio.h>
#include <string.h>

char* toMorseCode(char letter) {
    switch (letter) {
        case 'a': case 'A':
            return ".-";
        case 'b': case 'B':
            return "-...";
        case 'c': case 'C':
            return "-.-.";
        case 'd': case 'D':
            return "-..";
        case 'e': case 'E':
            return ".";
        case 'f': case 'F':
            return "..-.";
        case 'g': case 'G':
            return "--.";
        case 'h': case 'H':
            return "....";
        case 'i': case 'I':
            return "..";
        case 'j': case 'J':
            return ".---";
        case 'k': case 'K':
            return "-.-";
        case 'l': case 'L':
            return ".-..";
        case 'm': case 'M':
            return "--";
        case 'n': case 'N':
            return "-.";
        case 'o': case 'O':
            return "---";
        case 'p': case 'P':
            return ".--.";
        case 'q': case 'Q':
            return "--.-";
        case 'r': case 'R':
            return ".-.";
        case 's': case 'S':
            return "...";
        case 't': case 'T':
            return "-";
        case 'u': case 'U':
            return "..-";
        case 'v': case 'V':
            return "...-";
        case 'w': case 'W':
            return ".--";
        case 'x': case 'X':
            return "-..-";
        case 'y': case 'Y':
            return "-.--";
        case 'z': case 'Z':
            return "--..";
        case '1':
            return ".----";
        case '2':
            return "..---";
        case '3':
            return "...--";
        case '4':
            return "....-";
        case '5':
            return ".....";
        case '6':
            return "-....";
        case '7':
            return "--...";
        case '8':
            return "---..";
        case '9':
            return "----.";
        case '0':
            return "-----";
        default:
            return "";
    }
}

void convertToMorseCode(char* input, char* output) {
    int i, j, len;
    len = strlen(input);

    for (i = 0, j = 0; i < len; i++, j+=2) {
        char* code = toMorseCode(input[i]);
        strcat(output, code);
        strcat(output, " ");
    }
}

int main() {
    char input[100], output[100], choice;
    int i;

    do {
        printf("Enter text to convert to Morse Code: ");
        fgets(input, 100, stdin);

        convertToMorseCode(input, output);

        printf("Morse Code: %s\n", output);

        printf("Do you want to convert another text? [y/n]: ");
        scanf("%c", &choice);
        getchar();

        memset(output, 0, sizeof(output));
    } while (choice == 'y' || choice == 'Y');

    return 0;
}