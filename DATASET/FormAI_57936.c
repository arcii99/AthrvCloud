//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: calm
#include <stdio.h>

// Function to convert character to morse code
void morse(char c) {
    switch (c) {
        case 'a':
        case 'A': printf(".- "); break;
        case 'b':
        case 'B': printf("-... "); break;
        case 'c':
        case 'C': printf("-.-. "); break;
        case 'd':
        case 'D': printf("-.. "); break;
        case 'e':
        case 'E': printf(". "); break;
        case 'f':
        case 'F': printf("..-. "); break;
        case 'g':
        case 'G': printf("--. "); break;
        case 'h':
        case 'H': printf(".... "); break;
        case 'i':
        case 'I': printf(".. "); break;
        case 'j':
        case 'J': printf(".--- "); break;
        case 'k':
        case 'K': printf("-.- "); break;
        case 'l':
        case 'L': printf(".-.. "); break;
        case 'm':
        case 'M': printf("-- "); break;
        case 'n':
        case 'N': printf("-. "); break;
        case 'o':
        case 'O': printf("--- "); break;
        case 'p':
        case 'P': printf(".--. "); break;
        case 'q':
        case 'Q': printf("--.- "); break;
        case 'r':
        case 'R': printf(".-. "); break;
        case 's':
        case 'S': printf("... "); break;
        case 't':
        case 'T': printf("- "); break;
        case 'u':
        case 'U': printf("..- "); break;
        case 'v':
        case 'V': printf("...- "); break;
        case 'w':
        case 'W': printf(".-- "); break;
        case 'x':
        case 'X': printf("-..- "); break;
        case 'y':
        case 'Y': printf("-.-- "); break;
        case 'z':
        case 'Z': printf("--.. "); break;
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
        case ' ': printf("/ "); break;
        default: printf(""); break;
    }
}

int main() {
    char text[100];
    printf("Enter text to convert to morse code: ");
    fgets(text, sizeof(text), stdin);
    
    for (int i = 0; text[i] != '\0'; i++) {
        morse(text[i]);
    }
    
    return 0;
}