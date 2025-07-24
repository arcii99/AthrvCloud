//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: portable
#include <stdio.h>
#include <string.h>

void decode(char* code){
    int len = strlen(code);

    for(int i = 0; i < len; i++){
        switch(code[i]){
            case '1':
                printf("a");
                break;
            case '2':
                printf("b");
                break;
            case '3':
                printf("c");
                break;
            case '4':
                printf("d");
                break;
            case '5':
                printf("e");
                break;
            case '6':
                printf("f");
                break;
            case '7':
                printf("g");
                break;
            case '8':
                printf("h");
                break;
            case '9':
                printf("i");
                break;
            case 'A':
                printf("j");
                break;
            case 'B':
                printf("k");
                break;
            case 'C':
                printf("l");
                break;
            case 'D':
                printf("m");
                break;
            case 'E':
                printf("n");
                break;
            case 'F':
                printf("o");
                break;
            case 'G':
                printf("p");
                break;
            case 'H':
                printf("q");
                break;
            case 'I':
                printf("r");
                break;
            case 'J':
                printf("s");
                break;
            case 'K':
                printf("t");
                break;
            case 'L':
                printf("u");
                break;
            case 'M':
                printf("v");
                break;
            case 'N':
                printf("w");
                break;
            case 'O':
                printf("x");
                break;
            case 'P':
                printf("y");
                break;
            case 'Q':
                printf("z");
                break;
            case '_':
                printf(" ");
                break;
            default:
                printf("%c", code[i]);
        }
    }
}

int main(){
    char code[] = "B1A2K4_7MFNK";
    decode(code);
    return 0;
}