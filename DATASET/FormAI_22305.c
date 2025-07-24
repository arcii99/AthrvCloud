//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

void morse(char symbol) { // function to print morse code of a symbol
    switch(symbol) {
        case 'A':
            printf(".- "); break;
        case 'B':
            printf("-... "); break;
        case 'C':
            printf("-.-. "); break;
        case 'D':
            printf("-.. "); break;
        case 'E':
            printf(". "); break;
        case 'F':
            printf("..-. "); break;
        case 'G':
            printf("--. "); break;
        case 'H':
            printf(".... "); break;
        case 'I':
            printf(".. "); break;
        case 'J':
            printf(".--- "); break;
        case 'K':
            printf("-.- "); break;
        case 'L':
            printf(".-.. "); break;
        case 'M':
            printf("-- "); break;
        case 'N':
            printf("-. "); break;
        case 'O':
            printf("--- "); break;
        case 'P':
            printf(".--. "); break;
        case 'Q':
            printf("--.- "); break;
        case 'R':
            printf(".-. "); break;
        case 'S':
            printf("... "); break;
        case 'T':
            printf("- "); break;
        case 'U':
            printf("..- "); break;
        case 'V':
            printf("...- "); break;
        case 'W':
            printf(".-- "); break;
        case 'X':
            printf("-..- "); break;
        case 'Y':
            printf("-.-- "); break;
        case 'Z':
            printf("--.. "); break;
        case ' ':
            printf("/ "); break;
        default:
            printf("? ");
    }
}

int main() {
    char string[100]; // string to store input
    int length;
    printf("Enter the input string: ");
    scanf("%[^\n]%*c", string);
    length = strlen(string);
    printf("Morse Code: ");
    for(int i = 0; i < length; i++) {
        morse(toupper(string[i])); // convert to upper case before printing morse code
    }
    printf("\n");
    return 0;
}