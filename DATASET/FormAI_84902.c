//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printMorseCode(char c){
    switch (toupper(c)){
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
        case '0':
            printf("----- ");
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
        case ' ':
            printf(" / ");
            break;
        default:
            //Ignore unsupported characters
            break;
    }
}

void textToMorseCode(char input[]){
    printf("Morse Code: ");
    for (int i = 0; i < strlen(input); i++){
        printMorseCode(input[i]);
    }
    printf("\n");
}

int main(){
    char input[100];

    printf("Enter a text to convert to morse code (maximum 100 characters): ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; //Remove newline character from input

    textToMorseCode(input);

    return 0;
}