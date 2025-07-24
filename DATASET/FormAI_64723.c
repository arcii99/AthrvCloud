//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: future-proof
#include <stdio.h>
#include <string.h>

// Function to convert a character to Morse code
void convertToMorse(char c, char* morse) {
    switch(c) {
        case 'A':
            strcpy(morse, ".-");
            break;
        case 'B':
            strcpy(morse, "-...");
            break;
        case 'C':
            strcpy(morse, "-.-.");
            break;
        case 'D':
            strcpy(morse, "-..");
            break;
        case 'E':
            strcpy(morse, ".");
            break;
        case 'F':
            strcpy(morse, "..-.");
            break;
        case 'G':
            strcpy(morse, "--.");
            break;
        case 'H':
            strcpy(morse, "....");
            break;
        case 'I':
            strcpy(morse, "..");
            break;
        case 'J':
            strcpy(morse, ".---");
            break;
        case 'K':
            strcpy(morse, "-.-");
            break;
        case 'L':
            strcpy(morse, ".-..");
            break;
        case 'M':
            strcpy(morse, "--");
            break;
        case 'N':
            strcpy(morse, "-.");
            break;
        case 'O':
            strcpy(morse, "---");
            break;
        case 'P':
            strcpy(morse, ".--.");
            break;
        case 'Q':
            strcpy(morse, "--.-");
            break;
        case 'R':
            strcpy(morse, ".-.");
            break;
        case 'S':
            strcpy(morse, "...");
            break;
        case 'T':
            strcpy(morse, "-");
            break;
        case 'U':
            strcpy(morse, "..-");
            break;
        case 'V':
            strcpy(morse, "...-");
            break;
        case 'W':
            strcpy(morse, ".--");
            break;
        case 'X':
            strcpy(morse, "-..-");
            break;
        case 'Y':
            strcpy(morse, "-.--");
            break;
        case 'Z':
            strcpy(morse, "--..");
            break;
        case ' ':
            strcpy(morse, " ");
            break;
        default:
            strcpy(morse, "");
    }
}

int main() {
    printf("Welcome to the Text to Morse Code Converter!\n");
    printf("Enter the text you want to convert to Morse code: ");
    char text[100];
    char morse[1500] = "";
    fgets(text, 100, stdin);
    
    // Convert text to Morse code
    for(int i = 0; i < strlen(text); i++) {
        char c = toupper(text[i]);
        char temp[4];
        convertToMorse(c, temp);
        strcat(morse, temp);
        strcat(morse, " ");
    }
    
    printf("Morse Code: %s\n", morse);
    
    return 0;
}