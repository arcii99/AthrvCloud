//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: inquisitive
#include <stdio.h>
#include <string.h>

/* Function to convert a letter to Morse code */
char* letter_to_morse(char letter) {
    switch (letter) {
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
        case '0':
            return "-----";
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
        default:
            return "";
    }
}

/* Function to convert a string to Morse code */
char* string_to_morse(char* string) {
    static char morse[1000]; // creating an array to store morse code
    memset(morse, '\0', sizeof(morse)); // setting all values of array to '\0'

    int index = 0;
    for (int i=0; i<strlen(string); i++) {
        char letter = string[i];
        char* morse_code = letter_to_morse(letter);
        if (strcmp(morse_code, "") == 0) {
            continue; // skip if not a valid letter or number
        }
        strcat(morse, morse_code); // append morse code to the array
        if (i != strlen(string) - 1) {
            strcat(morse, " "); // add a space after each letter (except the last one)
        }
        index += strlen(morse_code) + 1; // update the index to the next position in the array
    }

    return morse;
}

int main() {
    char string[1000];
    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);
    // remove new line character from the end of the string
    string[strcspn(string, "\n")] = '\0';
    char* morse_code = string_to_morse(string);
    printf("Morse code: %s\n", morse_code);
    return 0;
}