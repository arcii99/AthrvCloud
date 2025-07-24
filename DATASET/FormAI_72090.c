//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

int main() {
    char text[100], morse[100];
    int i, j;
    
    printf("Enter the text to be converted to Morse code: ");
    scanf("%[^\n]", text);
    
    for(i=0; i<strlen(text); i++) {
        switch(text[i]) {
            case 'A': case 'a': strcat(morse, ".- "); break;
            case 'B': case 'b': strcat(morse, "-... "); break;
            case 'C': case 'c': strcat(morse, "-.-. "); break;
            case 'D': case 'd': strcat(morse, "-.. "); break;
            case 'E': case 'e': strcat(morse, ". "); break;
            case 'F': case 'f': strcat(morse, "..-. "); break;
            case 'G': case 'g': strcat(morse, "--. "); break;
            case 'H': case 'h': strcat(morse, ".... "); break;
            case 'I': case 'i': strcat(morse, ".. "); break;
            case 'J': case 'j': strcat(morse, ".--- "); break;
            case 'K': case 'k': strcat(morse, "-.- "); break;
            case 'L': case 'l': strcat(morse, ".-.. "); break;
            case 'M': case 'm': strcat(morse, "-- "); break;
            case 'N': case 'n': strcat(morse, "-. "); break;
            case 'O': case 'o': strcat(morse, "--- "); break;
            case 'P': case 'p': strcat(morse, ".--. "); break;
            case 'Q': case 'q': strcat(morse, "--.- "); break;
            case 'R': case 'r': strcat(morse, ".-. "); break;
            case 'S': case 's': strcat(morse, "... "); break;
            case 'T': case 't': strcat(morse, "- "); break;
            case 'U': case 'u': strcat(morse, "..- "); break;
            case 'V': case 'v': strcat(morse, "...- "); break;
            case 'W': case 'w': strcat(morse, ".-- "); break;
            case 'X': case 'x': strcat(morse, "-..- "); break;
            case 'Y': case 'y': strcat(morse, "-.-- "); break;
            case 'Z': case 'z': strcat(morse, "--.. "); break;
            case '0': strcat(morse, "----- "); break;
            case '1': strcat(morse, ".---- "); break;
            case '2': strcat(morse, "..--- "); break;
            case '3': strcat(morse, "...-- "); break;
            case '4': strcat(morse, "....- "); break;
            case '5': strcat(morse, "..... "); break;
            case '6': strcat(morse, "-.... "); break;
            case '7': strcat(morse, "--... "); break;
            case '8': strcat(morse, "---.. "); break;
            case '9': strcat(morse, "----. "); break;
            case ' ': strcat(morse, "/ "); break;
            default: strcat(morse, " "); break;
        }
    }
    
    printf("Morse code: %s\n", morse);
    
    return 0;
}