//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void printMorseCode(char input);
void convertToMorseCode(char* inputString, char* outputString);

int main(){
    char inputString[MAX_LENGTH], outputString[MAX_LENGTH];
    printf("Enter a string to be converted to Morse code: ");
    fgets(inputString, MAX_LENGTH, stdin);
    inputString[strcspn(inputString, "\n")] = 0; // remove newline character from input
    printf("Converting input string \"%s\" to Morse code...\n", inputString);
    convertToMorseCode(inputString, outputString);
    printf("Result: \"%s\"\n", outputString);
    return 0;
}

void convertToMorseCode(char* inputString, char* outputString){
    int length = strlen(inputString);
    for(int i=0; i<length; i++){
        char c = inputString[i];
        if(c == ' '){
            strcat(outputString, "/ ");
            continue;
        }
        printMorseCode(c);
        strcat(outputString, " ");
    }
}

void printMorseCode(char input){
    switch(input){
        case 'A': printf(".- "); break;
        case 'B': printf("-... "); break;
        case 'C': printf("-.-. "); break;
        case 'D': printf("-.. "); break;
        case 'E': printf(". "); break;
        case 'F': printf("..-. "); break;
        case 'G': printf("--. "); break;
        case 'H': printf(".... "); break;
        case 'I': printf(".. "); break;
        case 'J': printf(".--- "); break;
        case 'K': printf("-.- "); break;
        case 'L': printf(".-.. "); break;
        case 'M': printf("-- "); break;
        case 'N': printf("-. "); break;
        case 'O': printf("--- "); break;
        case 'P': printf(".--. "); break;
        case 'Q': printf("--.- "); break;
        case 'R': printf(".-. "); break;
        case 'S': printf("... "); break;
        case 'T': printf("- "); break;
        case 'U': printf("..- "); break;
        case 'V': printf("...- "); break;
        case 'W': printf(".-- "); break;
        case 'X': printf("-..- "); break;
        case 'Y': printf("-.-- "); break;
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
        default: printf("%c ", input); break;
    }
}