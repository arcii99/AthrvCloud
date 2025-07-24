//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: realistic
#include <stdio.h>
#include <string.h>

void convertToMorse(char str[]);

int main(){

    char sentence[100];

    printf("Please enter the text to convert to Morse code: ");
    fgets(sentence, 100, stdin);

    convertToMorse(sentence);

    return 0;
}

void convertToMorse(char str[]){

    int i, j, len;
    char c;

    len = strlen(str);

    for(i=0; i<len; i++){

        // convert each letter to Morse code
        c = toupper(str[i]);

        switch(c){
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
            default: printf("? "); break;
        }
    }
}