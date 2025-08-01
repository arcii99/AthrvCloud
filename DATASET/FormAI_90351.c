//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: curious
#include <stdio.h>
#include <string.h>

char* toMorse(char c){
    switch (c){
        case 'a': return ".-";
        case 'b': return "-...";
        case 'c': return "-.-.";
        case 'd': return "-..";
        case 'e': return ".";
        case 'f': return "..-.";
        case 'g': return "--.";
        case 'h': return "....";
        case 'i': return "..";
        case 'j': return ".---";
        case 'k': return "-.-";
        case 'l': return ".-..";
        case 'm': return "--";
        case 'n': return "-.";
        case 'o': return "---";
        case 'p': return ".--.";
        case 'q': return "--.-";
        case 'r': return ".-.";
        case 's': return "...";
        case 't': return "-";
        case 'u': return "..-";
        case 'v': return "...-";
        case 'w': return ".--";
        case 'x': return "-..-";
        case 'y': return "-.--";
        case 'z': return "--..";
        case '0': return "-----";
        case '1': return ".----";
        case '2': return "..---";
        case '3': return "...--";
        case '4': return "....-";
        case '5': return ".....";
        case '6': return "-....";
        case '7': return "--...";
        case '8': return "---..";
        case '9': return "----.";
        default: return "";
    }
}

int main(){
    char text[100];
    printf("Enter text to convert to Morse code: \n");
    fgets(text, 100, stdin);
    printf("Morse code: \n");
    for (int i = 0; i < strlen(text); i++){
        if (text[i] == ' '){
            printf(" ");
        }
        else {
            char* morse = toMorse(text[i]);
            printf("%s", morse);
        }
    }
    printf("\n");
    return 0;
}