//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

char *morse_code(char c){
    static char code[6];
    switch(c){
        case 'A':
            strcpy(code, ".-");
            break;
        case 'B':
            strcpy(code, "-...");
            break;
        case 'C':
            strcpy(code, "-.-.");
            break;
        case 'D':
            strcpy(code, "-..");
            break;
        case 'E':
            strcpy(code, ".");
            break;
        case 'F':
            strcpy(code, "..-.");
            break;
        case 'G':
            strcpy(code, "--.");
            break;
        case 'H':
            strcpy(code, "....");
            break;
        case 'I':
            strcpy(code, "..");
            break;
        case 'J':
            strcpy(code, ".---");
            break;
        case 'K':
            strcpy(code, "-.-");
            break;
        case 'L':
            strcpy(code, ".-..");
            break;
        case 'M':
            strcpy(code, "--");
            break;
        case 'N':
            strcpy(code, "-.");
            break;
        case 'O':
            strcpy(code, "---");
            break;
        case 'P':
            strcpy(code, ".--.");
            break;
        case 'Q':
            strcpy(code, "--.-");
            break;
        case 'R':
            strcpy(code, ".-.");
            break;
        case 'S':
            strcpy(code, "...");
            break;
        case 'T':
            strcpy(code, "-");
            break;
        case 'U':
            strcpy(code, "..-");
            break;
        case 'V':
            strcpy(code, "...-");
            break;
        case 'W':
            strcpy(code, ".--");
            break;
        case 'X':
            strcpy(code, "-..-");
            break;
        case 'Y':
            strcpy(code, "-.--");
            break;
        case 'Z':
            strcpy(code, "--..");
            break;
        case ' ':
            strcpy(code, " ");
            break;
        default:
            strcpy(code, "");
    }
    return code;
}

int main(){
    char message[] = "But, soft! what light through yonder window breaks? It is the east, and Juliet is the sun.";
    int i, j;
    char morse[500];
    for(i = 0; i < strlen(message); i++){
        if(message[i] >= 'a' && message[i] <= 'z') message[i] -= 32;
        if(message[i] == '\n') continue;
        char *code = morse_code(message[i]);
        if(strcmp(code, "") == 0){
            printf("Invalid character.\n");
            return 0;
        }
        strcat(morse, code);
        strcat(morse, " ");
    }
    printf("Morse code for message:\n%s\nis:\n%s\n", message, morse);
    return 0;
}