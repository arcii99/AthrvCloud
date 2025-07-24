//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

#define DOT "."
#define DASH "-"
#define SPACE " "

char* convert_to_morse(char c){
    switch(c){
        case 'A':
            return DOT DASH SPACE;
        case 'B':
            return DASH DOT DOT DOT SPACE;
        case 'C':
            return DASH DOT DASH DOT SPACE;
        case 'D':
            return DASH DOT DOT SPACE;
        case 'E':
            return DOT SPACE;
        case 'F':
            return DOT DOT DASH DOT SPACE;
        case 'G':
            return DASH DASH DOT SPACE;
        case 'H':
            return DOT DOT DOT DOT SPACE;
        case 'I':
            return DOT DOT SPACE;
        case 'J':
            return DOT DASH DASH DASH SPACE;
        case 'K':
            return DASH DOT DASH SPACE;
        case 'L':
            return DOT DASH DOT DOT SPACE;
        case 'M':
            return DASH DASH SPACE;
        case 'N':
            return DASH DOT SPACE;
        case 'O':
            return DASH DASH DASH SPACE;
        case 'P':
            return DOT DASH DASH DOT SPACE;
        case 'Q':
            return DASH DASH DOT DASH SPACE;
        case 'R':
            return DOT DASH DOT SPACE;
        case 'S':
            return DOT DOT DOT SPACE;
        case 'T':
            return DASH SPACE;
        case 'U':
            return DOT DOT DASH SPACE;
        case 'V':
            return DOT DOT DOT DASH SPACE;
        case 'W':
            return DOT DASH DASH SPACE;
        case 'X':
            return DASH DOT DOT DASH SPACE;
        case 'Y':
            return DASH DOT DASH DASH SPACE;
        case 'Z':
            return DASH DASH DOT DOT SPACE;
        default:
            return "";
    }
}

int main(){
    char input[100];
    char output[1000] = "";
    printf("Enter text to convert to morse code: ");
    fgets(input, sizeof(input), stdin);
    for(int i = 0; i < strlen(input); i++){
        char character = input[i];
        if(character == ' '){
            strcat(output, SPACE);
        }else{
            strcat(output, convert_to_morse(toupper(character)));
        }
    }
    printf("Morse code: %s", output);
    return 0;
}