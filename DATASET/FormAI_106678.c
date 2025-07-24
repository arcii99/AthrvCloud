//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMorse(char letter);

int main(){
    char input[100];
    printf("Enter the text you want to convert to Morse code: ");
    scanf("%[^\n]", input);
    printf("Morse code: ");
    for(int i=0; i<strlen(input); i++){
        if(input[i]==' '){ //if there is space, print slash
            printf("/");
        }
        else{
            printMorse(input[i]); //print the Morse code equivalent of the letter
        }
        printf(" ");
    }
    return 0;
}

void printMorse(char letter){
    switch(letter){
        case 'a':
        case 'A':
            printf(".-");
            break;
        case 'b':
        case 'B':
            printf("-...");
            break;
        case 'c':
        case 'C':
            printf("-.-.");
            break;
        case 'd':
        case 'D':
            printf("-..");
            break;
        case 'e':
        case 'E':
            printf(".");
            break;
        case 'f':
        case 'F':
            printf("..-.");
            break;
        case 'g':
        case 'G':
            printf("--.");
            break;
        case 'h':
        case 'H':
            printf("....");
            break;
        case 'i':
        case 'I':
            printf("..");
            break;
        case 'j':
        case 'J':
            printf(".---");
            break;
        case 'k':
        case 'K':
            printf("-.-");
            break;
        case 'l':
        case 'L':
            printf(".-..");
            break;
        case 'm':
        case 'M':
            printf("--");
            break;
        case 'n':
        case 'N':
            printf("-.");
            break;
        case 'o':
        case 'O':
            printf("---");
            break;
        case 'p':
        case 'P':
            printf(".--.");
            break;
        case 'q':
        case 'Q':
            printf("--.-");
            break;
        case 'r':
        case 'R':
            printf(".-.");
            break;
        case 's':
        case 'S':
            printf("...");
            break;
        case 't':
        case 'T':
            printf("-");
            break;
        case 'u':
        case 'U':
            printf("..-");
            break;
        case 'v':
        case 'V':
            printf("...-");
            break;
        case 'w':
        case 'W':
            printf(".--");
            break;
        case 'x':
        case 'X':
            printf("-..-");
            break;
        case 'y':
        case 'Y':
            printf("-.--");
            break;
        case 'z':
        case 'Z':
            printf("--..");
            break;
        case '0':
            printf("-----");
            break;
        case '1':
            printf(".----");
            break;
        case '2':
            printf("..---");
            break;
        case '3':
            printf("...--");
            break;
        case '4':
            printf("....-");
            break;
        case '5':
            printf(".....");
            break;
        case '6':
            printf("-....");
            break;
        case '7':
            printf("--...");
            break;
        case '8':
            printf("---..");
            break;
        case '9':
            printf("----.");
            break;
        default:
            printf("%c", letter); //if the letter is not a valid alphabet or number, print the letter itself
    }
}