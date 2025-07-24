//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: expert-level
#include <stdio.h>
#include <string.h>

// Function to convert the given character to Morse Code
void charToMorseCode(char c, char *morseCode) {
    switch(c) {
        case 'a':
        case 'A':
            strcpy(morseCode, ".-");
            break;
        case 'b':
        case 'B':
            strcpy(morseCode, "-...");
            break;
        case 'c':
        case 'C':
            strcpy(morseCode, "-.-.");
            break;
        case 'd':
        case 'D':
            strcpy(morseCode, "-..");
            break;
        case 'e':
        case 'E':
            strcpy(morseCode, ".");
            break;
        case 'f':
        case 'F':
            strcpy(morseCode, "..-.");
            break;
        case 'g':
        case 'G':
            strcpy(morseCode, "--.");
            break;
        case 'h':
        case 'H':
            strcpy(morseCode, "....");
            break;
        case 'i':
        case 'I':
            strcpy(morseCode, "..");
            break;
        case 'j':
        case 'J':
            strcpy(morseCode, ".---");
            break;
        case 'k':
        case 'K':
            strcpy(morseCode, "-.-");
            break;
        case 'l':
        case 'L':
            strcpy(morseCode, ".-..");
            break;
        case 'm':
        case 'M':
            strcpy(morseCode, "--");
            break;
        case 'n':
        case 'N':
            strcpy(morseCode, "-.");
            break;
        case 'o':
        case 'O':
            strcpy(morseCode, "---");
            break;
        case 'p':
        case 'P':
            strcpy(morseCode, ".--.");
            break;
        case 'q':
        case 'Q':
            strcpy(morseCode, "--.-");
            break;
        case 'r':
        case 'R':
            strcpy(morseCode, ".-.");
            break;
        case 's':
        case 'S':
            strcpy(morseCode, "...");
            break;
        case 't':
        case 'T':
            strcpy(morseCode, "-");
            break;
        case 'u':
        case 'U':
            strcpy(morseCode, "..-");
            break;
        case 'v':
        case 'V':
            strcpy(morseCode, "...-");
            break;
        case 'w':
        case 'W':
            strcpy(morseCode, ".--");
            break;
        case 'x':
        case 'X':
            strcpy(morseCode, "-..-");
            break;
        case 'y':
        case 'Y':
            strcpy(morseCode, "-.--");
            break;
        case 'z':
        case 'Z':
            strcpy(morseCode, "--..");
            break;
        case '0':
            strcpy(morseCode, "-----");
            break;
        case '1':
            strcpy(morseCode, ".----");
            break;
        case '2':
            strcpy(morseCode, "..---");
            break;
        case '3':
            strcpy(morseCode, "...--");
            break;
        case '4':
            strcpy(morseCode, "....-");
            break;
        case '5':
            strcpy(morseCode, ".....");
            break;
        case '6':
            strcpy(morseCode, "-....");
            break;
        case '7':
            strcpy(morseCode, "--...");
            break;
        case '8':
            strcpy(morseCode, "---..");
            break;
        case '9':
            strcpy(morseCode, "----.");
            break;
        case ' ':
            strcpy(morseCode, "/");
            break;
        default:
            break;
    }
}

// Function to convert the given string to Morse Code and print the result to the console
void convertTextToMorseCode(char *text) {
    char morseCode[100];
    for(int i = 0; i < strlen(text); i++) {
        charToMorseCode(text[i], morseCode);
        printf("%s ", morseCode);
    }
}

int main() {
    // Get the input text from the user
    char text[100];
    printf("Enter the text to convert to Morse Code: ");
    gets(text); // Note: gets() is not safe, but used here for simplicity

    // Convert the text to Morse Code and print the result to the console
    convertTextToMorseCode(text);

    return 0;
}