//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: brave
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void printMorse(char c);

int main(){

    char input[100];
    printf("Enter a line of text to convert to Morse code: ");
    fgets(input, 100, stdin);

    printf("Morse code output: ");
    for(int i=0; i<strlen(input); i++){
        if(isalpha(input[i])){
            printMorse(toupper(input[i]));
            printf(" ");
        }
        else if(input[i] == ' '){
            printf("  ");
        }
        else if(input[i] == '\n'){
            break;
        }
    }

    return 0;
}

void printMorse(char c){
    char *morse_code[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
    };
    printf("%s", morse_code[c-'A']);
}