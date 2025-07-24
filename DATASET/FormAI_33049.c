//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: mathematical
#include <stdio.h>
#include <string.h>

void dot(){
    printf(".");
}

void dash(){
    printf("-");
}

void convertToCode(char c){
    switch(tolower(c)){
        case 'a':
            dot();
            dash();
            break;
        case 'b':
            dash();
            dot();
            dot();
            dot();
            break;
        case 'c':
            dash();
            dot();
            dash();
            dot();
            break;
        case 'd':
            dash();
            dot();
            dot();
            break;
        case 'e':
            dot();
            break;
        case 'f':
            dot();
            dot();
            dash();
            dot();
            break;
        case 'g':
            dash();
            dash();
            dot();
            break;
        case 'h':
            dot();
            dot();
            dot();
            dot();
            break;
        case 'i':
            dot();
            dot();
            break;
        case 'j':
            dot();
            dash();
            dash();
            dash();
            break;
        case 'k':
            dash();
            dot();
            dash();
            break;
        case 'l':
            dot();
            dash();
            dot();
            dot();
            break;
        case 'm':
            dash();
            dash();
            break;
        case 'n':
            dash();
            dot();
            break;
        case 'o':
            dash();
            dash();
            dash();
            break;
        case 'p':
            dot();
            dash();
            dash();
            dot();
            break;
        case 'q':
            dash();
            dash();
            dot();
            dash();
            break;
        case 'r':
            dot();
            dash();
            dot();
            break;
        case 's':
            dot();
            dot();
            dot();
            break;
        case 't':
            dash();
            break;
        case 'u':
            dot();
            dot();
            dash();
            break;
        case 'v':
            dot();
            dot();
            dot();
            dash();
            break;
        case 'w':
            dot();
            dash();
            dash();
            break;
        case 'x':
            dash();
            dot();
            dot();
            dash();
            break;
        case 'y':
            dash();
            dot();
            dash();
            dash();
            break;
        case 'z':
            dash();
            dash();
            dot();
            dot();
            break;
        case ' ':
            printf(" ");
            break;
    }
}

void convertToMorse(char *text){
    int length = strlen(text);
    for(int i = 0; i < length; i++){
        convertToCode(text[i]);
        printf(" ");
    }
}

int main(){
    char text[50];
    printf("Enter the text you want to convert to Morse code: ");
    fgets(text, 50, stdin);
    printf("Morse code: ");
    convertToMorse(text);
    return 0;
}