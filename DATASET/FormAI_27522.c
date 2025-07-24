//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: detailed
#include <stdio.h>
#include <string.h>

// Function to convert characters to Morse code
void charToMorse(char c, char* morse) {
    switch(c) {
        case 'a': case 'A':
            strcpy(morse, ".-");
            break;
        case 'b': case 'B':
            strcpy(morse, "-...");
            break;
        case 'c': case 'C':
            strcpy(morse, "-.-.");
            break;
        case 'd': case 'D':
            strcpy(morse, "-..");
            break;
        case 'e': case 'E':
            strcpy(morse, ".");
            break;
        case 'f': case 'F':
            strcpy(morse, "..-.");
            break;
        case 'g': case 'G':
            strcpy(morse, "--.");
            break;
        case 'h': case 'H':
            strcpy(morse, "....");
            break;
        case 'i': case 'I':
            strcpy(morse, "..");
            break;
        case 'j': case 'J':
            strcpy(morse, ".---");
            break;
        case 'k': case 'K':
            strcpy(morse, "-.-");
            break;
        case 'l': case 'L':
            strcpy(morse, ".-..");
            break;
        case 'm': case 'M':
            strcpy(morse, "--");
            break;
        case 'n': case 'N':
            strcpy(morse, "-.");
            break;
        case 'o': case 'O':
            strcpy(morse, "---");
            break;
        case 'p': case 'P':
            strcpy(morse, ".--.");
            break;
        case 'q': case 'Q':
            strcpy(morse, "--.-");
            break;
        case 'r': case 'R':
            strcpy(morse, ".-.");
            break;
        case 's': case 'S':
            strcpy(morse, "...");
            break;
        case 't': case 'T':
            strcpy(morse, "-");
            break;
        case 'u': case 'U':
            strcpy(morse, "..-");
            break;
        case 'v': case 'V':
            strcpy(morse, "...-");
            break;
        case 'w': case 'W':
            strcpy(morse, ".--");
            break;
        case 'x': case 'X':
            strcpy(morse, "-..-");
            break;
        case 'y': case 'Y':
            strcpy(morse, "-.--");
            break;
        case 'z': case 'Z':
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

// Function to add space between characters
void addSpace(char* morse) {
    if(strcmp(morse, "") != 0) {
        strcat(morse, " ");
    }
}

int main() {
    char text[100];
    char morse[500] = "";
    
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin); // read user input
   
    int len = strlen(text);
    for(int i = 0; i < len; ++i) {
        charToMorse(text[i], morse);
        addSpace(morse);
        strcat(morse, "| "); // Use a vertical bar to distinguish different words (spaces)
    }
    
    printf("%s", morse);
    return 0;
}