//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

// function to convert a character to Morse code
void charToMorse(char c, char* morse) {
    switch (c) {
        case 'A': case 'a': strcpy(morse, ".-"); break;
        case 'B': case 'b': strcpy(morse, "-..."); break;
        case 'C': case 'c': strcpy(morse, "-.-."); break;
        case 'D': case 'd': strcpy(morse, "-.."); break;
        case 'E': case 'e': strcpy(morse, "."); break;
        case 'F': case 'f': strcpy(morse, "..-."); break;
        case 'G': case 'g': strcpy(morse, "--."); break;
        case 'H': case 'h': strcpy(morse, "...."); break;
        case 'I': case 'i': strcpy(morse, ".."); break;
        case 'J': case 'j': strcpy(morse, ".---"); break;
        case 'K': case 'k': strcpy(morse, "-.-"); break;
        case 'L': case 'l': strcpy(morse, ".-.."); break;
        case 'M': case 'm': strcpy(morse, "--"); break;
        case 'N': case 'n': strcpy(morse, "-."); break;
        case 'O': case 'o': strcpy(morse, "---"); break;
        case 'P': case 'p': strcpy(morse, ".--."); break;
        case 'Q': case 'q': strcpy(morse, "--.-"); break;
        case 'R': case 'r': strcpy(morse, ".-."); break;
        case 'S': case 's': strcpy(morse, "..."); break;
        case 'T': case 't': strcpy(morse, "-"); break;
        case 'U': case 'u': strcpy(morse, "..-"); break;
        case 'V': case 'v': strcpy(morse, "...-"); break;
        case 'W': case 'w': strcpy(morse, ".--"); break;
        case 'X': case 'x': strcpy(morse, "-..-"); break;
        case 'Y': case 'y': strcpy(morse, "-.--"); break;
        case 'Z': case 'z': strcpy(morse, "--.."); break;
        case '1': strcpy(morse, ".----"); break;
        case '2': strcpy(morse, "..---"); break;
        case '3': strcpy(morse, "...--"); break;
        case '4': strcpy(morse, "....-"); break;
        case '5': strcpy(morse, "....."); break;
        case '6': strcpy(morse, "-...."); break;
        case '7': strcpy(morse, "--..."); break;
        case '8': strcpy(morse, "---.."); break;
        case '9': strcpy(morse, "----."); break;
        case '0': strcpy(morse, "-----"); break;
        default: strcpy(morse, ""); break;
    }
}

// function to convert a string to Morse code
void stringToMorse(char* str, char* morse) {
    int len = strlen(str);
    char morseChar[5];
    morse[0] = '\0';
    for (int i = 0; i < len; i++) {
        charToMorse(str[i], morseChar);
        strcat(morse, morseChar);
        strcat(morse, " ");
    }
}

// main function to prompt user for input and convert it to Morse code
int main() {
    char str[100];
    char morse[500];
    printf("Enter a string to convert to Morse code: ");
    scanf("%[^\n]", str);
    stringToMorse(str, morse);
    printf("Morse code: %s\n", morse);
    return 0;
}