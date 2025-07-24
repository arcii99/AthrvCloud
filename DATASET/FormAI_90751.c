//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: detailed
#include <stdio.h>
#include <string.h>

// function to convert character to Morse code
void charToMorse(char c, char *morse) {
    switch(c) {
        case 'a':
        case 'A':
            strcpy(morse, ".-");
            break;
        case 'b':
        case 'B':
            strcpy(morse, "-...");
            break;
        case 'c':
        case 'C':
            strcpy(morse, "-.-.");
            break;
        case 'd':
        case 'D':
            strcpy(morse, "-..");
            break;
        case 'e':
        case 'E':
            strcpy(morse, ".");
            break;
        case 'f':
        case 'F':
            strcpy(morse, "..-.");
            break;
        case 'g':
        case 'G':
            strcpy(morse, "--.");
            break;
        case 'h':
        case 'H':
            strcpy(morse, "....");
            break;
        case 'i':
        case 'I':
            strcpy(morse, "..");
            break;
        case 'j':
        case 'J':
            strcpy(morse, ".---");
            break;
        case 'k':
        case 'K':
            strcpy(morse, "-.-");
            break;
        case 'l':
        case 'L':
            strcpy(morse, ".-..");
            break;
        case 'm':
        case 'M':
            strcpy(morse, "--");
            break;
        case 'n':
        case 'N':
            strcpy(morse, "-.");
            break;
        case 'o':
        case 'O':
            strcpy(morse, "---");
            break;
        case 'p':
        case 'P':
            strcpy(morse, ".--.");
            break;
        case 'q':
        case 'Q':
            strcpy(morse, "--.-");
            break;
        case 'r':
        case 'R':
            strcpy(morse, ".-.");
            break;
        case 's':
        case 'S':
            strcpy(morse, "...");
            break;
        case 't':
        case 'T':
            strcpy(morse, "-");
            break;
        case 'u':
        case 'U':
            strcpy(morse, "..-");
            break;
        case 'v':
        case 'V':
            strcpy(morse, "...-");
            break;
        case 'w':
        case 'W':
            strcpy(morse, ".--");
            break;
        case 'x':
        case 'X':
            strcpy(morse, "-..-");
            break;
        case 'y':
        case 'Y':
            strcpy(morse, "-.--");
            break;
        case 'z':
        case 'Z':
            strcpy(morse, "--..");
            break;
        case '0':
            strcpy(morse, "-----");
            break;
        case '1':
            strcpy(morse, ".----");
            break;
        case '2':
            strcpy(morse, "..---");
            break;
        case '3':
            strcpy(morse, "...--");
            break;
        case '4':
            strcpy(morse, "....-");
            break;
        case '5':
            strcpy(morse, ".....");
            break;
        case '6':
            strcpy(morse, "-....");
            break;
        case '7':
            strcpy(morse, "--...");
            break;
        case '8':
            strcpy(morse, "---..");
            break;
        case '9':
            strcpy(morse, "----.");
            break;
        default:
            strcpy(morse, "");
    }
}

// function that converts text to Morse code
void textToMorse(char *text, char *morse) {
    int len = strlen(text);
    for(int i=0; i<len; i++) {
        char c = text[i];
        char morseChar[10];
        charToMorse(c, morseChar);
        strcat(morse, morseChar);
        if(i < len-1) {
            strcat(morse, " ");
        }
    }
}

// main function
int main() {
    char text[100];
    char morse[1000];
    printf("Enter text: ");
    fgets(text, 100, stdin);
    text[strlen(text)-1] = '\0';
    textToMorse(text, morse);
    printf("Morse code: %s\n", morse);
    return 0;
}