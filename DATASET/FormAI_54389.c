//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert character to morse code
void toMorse(char c) {
    switch(c) {
        case 'a': printf(".-   "); break;
        case 'b': printf("-... "); break;
        case 'c': printf("-.-. "); break;
        case 'd': printf("-..  "); break;
        case 'e': printf(".    "); break;
        case 'f': printf("..-. "); break;
        case 'g': printf("--.  "); break;
        case 'h': printf(".... "); break;
        case 'i': printf("..   "); break;
        case 'j': printf(".--- "); break;
        case 'k': printf("-.-  "); break;
        case 'l': printf(".-.. "); break;
        case 'm': printf("--   "); break;
        case 'n': printf("-.   "); break;
        case 'o': printf("---  "); break;
        case 'p': printf(".--. "); break;
        case 'q': printf("--.- "); break;
        case 'r': printf(".-.  "); break;
        case 's': printf("...  "); break;
        case 't': printf("-    "); break;
        case 'u': printf("..-  "); break;
        case 'v': printf("...- "); break;
        case 'w': printf(".--  "); break;
        case 'x': printf("-..- "); break;
        case 'y': printf("-.-- "); break;
        case 'z': printf("--.. "); break;
        case '1': printf(".----"); break;
        case '2': printf("..---"); break;
        case '3': printf("...--"); break;
        case '4': printf("....-"); break;
        case '5': printf("....."); break;
        case '6': printf("-...."); break;
        case '7': printf("--..."); break;
        case '8': printf("---.."); break;
        case '9': printf("----."); break;
        case '0': printf("-----"); break;
        case ' ': printf("/    "); break;
        default: printf("?    "); break;
    }
}

// Main function
int main() {
    char input[256];
    printf("Enter text to be converted to Morse code: ");
    scanf("%s", input);
    
    int len = strlen(input);
    for(int i=0; i<len; i++) {
        toMorse(input[i]);
    }
    
    printf("\n");
    return 0;
}