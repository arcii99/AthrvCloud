//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to convert character to Morse code
void convertToMorse(char ch){
    switch(ch){
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
        case ' ': printf("/ "); break;
        default: printf("%c is not a valid character. ", ch); break;
    }
}


int main(){
    char inputStr[100];
    printf("Welcome to the Morse Code Converter Program!\n");
    printf("Enter a text to convert to Morse code:\n");
    fgets(inputStr, 100, stdin);
    printf("Morse code conversion:\n");
    for(int i=0; i<strlen(inputStr); i++){
        char currChar = toupper(inputStr[i]);
        convertToMorse(currChar);
    }
    printf("\n");
    printf("Thank you for using the Morse Code Converter Program!");
    return 0;
}