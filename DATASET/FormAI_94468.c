//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: shape shifting
#include <stdio.h>
#include <string.h>

int main() {
    char text[2000];
    printf("Enter the text to be converted to Morse code:\n");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // remove trailing newline character

    int length = strlen(text);

    printf("Morse code for '%s' is:\n", text);

    for(int i=0; i<length; i++) {
        char c = tolower(text[i]); // convert character to lowercase
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
            case ' ': printf("/ "); break;
            default: printf("%c ", c); break;
        }

        // Shape-shifting
        if(i % 2 == 0) {
            printf("\b\b \n"); // remove last two characters and add a newline
        }
        else if(i % 3 == 0) {
            printf("\b\b\b "); // remove last three characters and add a space
        }
        else {
            printf("\b\b"); // remove last two characters
        }
    }

    printf("\n"); // add a newline at the end

    return 0;
}