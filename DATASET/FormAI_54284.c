//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: mind-bending
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

// Function to convert a character to morse code
void char_to_morse(char c, char* morse_code) {
    switch (c) {
        case 'a':
        case 'A':
            strcpy(morse_code, ".-");
            break;
        case 'b':
        case 'B':
            strcpy(morse_code, "-...");
            break;
        case 'c':
        case 'C':
            strcpy(morse_code, "-.-.");
            break;
        case 'd':
        case 'D':
            strcpy(morse_code, "-..");
            break;
        case 'e':
        case 'E':
            strcpy(morse_code, ".");
            break;
        case 'f':
        case 'F':
            strcpy(morse_code, "..-.");
            break;
        case 'g':
        case 'G':
            strcpy(morse_code, "--.");
            break;
        case 'h':
        case 'H':
            strcpy(morse_code, "....");
            break;
        case 'i':
        case 'I':
            strcpy(morse_code, "..");
            break;
        case 'j':
        case 'J':
            strcpy(morse_code, ".---");
            break;
        case 'k':
        case 'K':
            strcpy(morse_code, "-.-");
            break;
        case 'l':
        case 'L':
            strcpy(morse_code, ".-..");
            break;
        case 'm':
        case 'M':
            strcpy(morse_code, "--");
            break;
        case 'n':
        case 'N':
            strcpy(morse_code, "-.");
            break;
        case 'o':
        case 'O':
            strcpy(morse_code, "---");
            break;
        case 'p':
        case 'P':
            strcpy(morse_code, ".--.");
            break;
        case 'q':
        case 'Q':
            strcpy(morse_code, "--.-");
            break;
        case 'r':
        case 'R':
            strcpy(morse_code, ".-.");
            break;
        case 's':
        case 'S':
            strcpy(morse_code, "...");
            break;
        case 't':
        case 'T':
            strcpy(morse_code, "-");
            break;
        case 'u':
        case 'U':
            strcpy(morse_code, "..-");
            break;
        case 'v':
        case 'V':
            strcpy(morse_code, "...-");
            break;
        case 'w':
        case 'W':
            strcpy(morse_code, ".--");
            break;
        case 'x':
        case 'X':
            strcpy(morse_code, "-..-");
            break;
        case 'y':
        case 'Y':
            strcpy(morse_code, "-.--");
            break;
        case 'z':
        case 'Z':
            strcpy(morse_code, "--..");
            break;
        case '1':
            strcpy(morse_code, ".----");
            break;
        case '2':
            strcpy(morse_code, "..---");
            break;
        case '3':
            strcpy(morse_code, "...--");
            break;
        case '4':
            strcpy(morse_code, "....-");
            break;
        case '5':
            strcpy(morse_code, ".....");
            break;
        case '6':
            strcpy(morse_code, "-....");
            break;
        case '7':
            strcpy(morse_code, "--...");
            break;
        case '8':
            strcpy(morse_code, "---..");
            break;
        case '9':
            strcpy(morse_code, "----.");
            break;
        case '0':
            strcpy(morse_code, "-----");
            break;
        default:
            strcpy(morse_code, "");
            break;
    }
}

// Function to convert a string to morse code
void string_to_morse(char* string, char* morse_code) {
    int length = strlen(string);

    for (int i = 0; i < length; i++) {
        char morse_char[10];
        char_to_morse(string[i], morse_char);

        strcat(morse_code, morse_char);
        strcat(morse_code, " ");
    }
}

int main() {
    char string[MAX_STRING_LENGTH];
    char morse_code[MAX_STRING_LENGTH];
    
    printf("Enter a string to convert to morse code: ");
    fgets(string, MAX_STRING_LENGTH, stdin);

    printf("\n-----------------------------\n");
    printf("Morse code representation: \n");

    string_to_morse(string, morse_code);
    printf("%s\n", morse_code);

    return 0;
}