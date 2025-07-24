//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: brave
#include <stdio.h>
#include <string.h>

// Function to convert a character to morse code
void charToMorse(char c, char morse[]) {
    switch (c) {
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
            break;
    }
}

int main() {
    char input[1000];
    printf("Enter a string to convert to Morse code: ");
    fgets(input, 1000, stdin);
    
    // Remove the newline character at the end of the input
    input[strcspn(input, "\n")] = 0;
    
    int len = strlen(input);
    char morse[len * 10]; // Allocate enough memory for worst-case scenario
    morse[0] = '\0'; // Initialize to empty string
    
    for (int i = 0; i < len; i++) {
        char curr = input[i];
        char morseChar[5];
        charToMorse(curr, morseChar);
        strcat(morse, morseChar);
        strcat(morse, " "); // Add space between characters
    }
    
    printf("Morse code output: %s", morse);
    
    return 0;
}