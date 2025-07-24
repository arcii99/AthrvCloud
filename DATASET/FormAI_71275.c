//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: surrealist
#include <stdio.h>
#include <string.h>

int main() {
    // welcome message
    printf("Welcome to the surreal Morse code generator!\n");
    printf("Please enter the text you would like to convert:\n");
    
    // read user input
    char text[101];
    fgets(text, 101, stdin);
    text[strcspn(text, "\n")] = '\0'; // remove trailing newline
    
    // translate to Morse code
    printf("Translating to Morse code...\n");
    for (int i = 0; i < strlen(text); i++) {
        char letter = toupper(text[i]);
        switch(letter) {
            case 'A':
                printf(".- ");
                break;
            case 'B':
                printf("-... ");
                break;
            case 'C':
                printf("-.-. ");
                break;
            case 'D':
                printf("-.. ");
                break;
            case 'E':
                printf(". ");
                break;
            case 'F':
                printf("..-. ");
                break;
            case 'G':
                printf("--. ");
                break;
            case 'H':
                printf(".... ");
                break;
            case 'I':
                printf(".. ");
                break;
            case 'J':
                printf(".--- ");
                break;
            case 'K':
                printf("-.- ");
                break;
            case 'L':
                printf(".-.. ");
                break;
            case 'M':
                printf("-- ");
                break;
            case 'N':
                printf("-. ");
                break;
            case 'O':
                printf("--- ");
                break;
            case 'P':
                printf(".--. ");
                break;
            case 'Q':
                printf("--.- ");
                break;
            case 'R':
                printf(".-. ");
                break;
            case 'S':
                printf("... ");
                break;
            case 'T':
                printf("- ");
                break;
            case 'U':
                printf("..- ");
                break;
            case 'V':
                printf("...- ");
                break;
            case 'W':
                printf(".-- ");
                break;
            case 'X':
                printf("-..- ");
                break;
            case 'Y':
                printf("-.-- ");
                break;
            case 'Z':
                printf("--.. ");
                break;
            case '1':
                printf(".---- ");
                break;
            case '2':
                printf("..--- ");
                break;
            case '3':
                printf("...-- ");
                break;
            case '4':
                printf("....- ");
                break;
            case '5':
                printf("..... ");
                break;
            case '6':
                printf("-.... ");
                break;
            case '7':
                printf("--... ");
                break;
            case '8':
                printf("---.. ");
                break;
            case '9':
                printf("----. ");
                break;
            case '0':
                printf("----- ");
                break;
            case ' ':
                printf("  ");
                break;
            default:
                printf("o_O ");
                break;
        }
    }
    printf("\n");
    return 0;
}