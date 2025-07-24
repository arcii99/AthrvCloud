//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: invasive
#include <stdio.h>
#include <string.h>

// Function to convert character to Morse code
void charToMorse(char c) {
    switch(c) {
        case 'a': printf(".- "); break;
        case 'b': printf("-... "); break;
        case 'c': printf("-.-. "); break;
        case 'd': printf("-.. "); break;
        case 'e': printf(". "); break;
        case 'f': printf("..-. "); break;
        case 'g': printf("--. "); break;
        case 'h': printf(".... "); break;
        case 'i': printf(".. "); break;
        case 'j': printf(".--- "); break;
        case 'k': printf("-.- "); break;
        case 'l': printf(".-.. "); break;
        case 'm': printf("-- "); break;
        case 'n': printf("-. "); break;
        case 'o': printf("--- "); break;
        case 'p': printf(".--. "); break;
        case 'q': printf("--.- "); break;
        case 'r': printf(".-. "); break;
        case 's': printf("... "); break;
        case 't': printf("- "); break;
        case 'u': printf("..- "); break;
        case 'v': printf("...- "); break;
        case 'w': printf(".-- "); break;
        case 'x': printf("-..- "); break;
        case 'y': printf("-.-- "); break;
        case 'z': printf("--.. "); break;
        case '0': printf("----- "); break;
        case '1': printf(".---- "); break;
        case '2': printf("..--- "); break;
        case '3': printf("...-- "); break;
        case '4': printf("....- "); break;
        case '5': printf("..... "); break;
        case '6': printf("-.... "); break;
        case '7': printf("--... "); break;
        case '8': printf("---.. "); break;
        case '9': printf("----. "); break;
        case ' ': printf("  "); break; // adding double space for word separator
        default : printf(""); // ignoring other characters
    }
}

int main() {
    char text[100]; // array to store user input
    printf("Enter text to be converted to Morse code: ");
    fgets(text, 100, stdin); // reading user input
    
    printf("Morse code for the entered text is:\n");
    
    for(int i = 0; i < strlen(text); i++) { // iterating over the text
        charToMorse(text[i]); // calling function to convert char to Morse
    }
    
    return 0;
}