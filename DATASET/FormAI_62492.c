//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

void morseCode(char letter){
    switch(letter) {
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
        default: printf(""); break;
    }
}

int main(){
    char sentence[100];
    printf("Enter a sentence to convert it to Morse code: ");
    fgets(sentence, sizeof(sentence), stdin);
    printf("Morse Code: ");
    for(int i=0; i<strlen(sentence); i++){
        if(sentence[i] == ' '){
            printf("/ ");
        }
        else{
            morseCode(tolower(sentence[i]));
        }
    }
    printf("\n");
    return 0;
}