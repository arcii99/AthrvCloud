//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: scalable
#include <stdio.h>
#include <string.h>

char* toMorseCode(char);

int main(){
    char message[100];
    printf("Enter message to convert to Morse code:\n");
    fgets(message, 100, stdin);

    int len = strlen(message);
    for (int i=0; i<len; i++){
        char c = message[i];
        if (c == '\n'){
            break;
        }
        printf("%s ", toMorseCode(c));
    }

    return 0;
}

char* toMorseCode(char c){
    char *morseCode;
    switch (c) {
        case 'a': case 'A':
            morseCode = ".-";
            break;
        case 'b': case 'B':
            morseCode = "-...";
            break;
        case 'c': case 'C':
            morseCode = "-.-.";
            break;
        case 'd': case 'D':
            morseCode = "-..";
            break;
        case 'e': case 'E':
            morseCode = ".";
            break;
        case 'f': case 'F':
            morseCode = "..-.";
            break;
        case 'g': case 'G':
            morseCode = "--.";
            break;
        case 'h': case 'H':
            morseCode = "....";
            break;
        case 'i': case 'I':
            morseCode = "..";
            break;
        case 'j': case 'J':
            morseCode = ".---";
            break;
        case 'k': case 'K':
            morseCode = "-.-";
            break;
        case 'l': case 'L':
            morseCode = ".-..";
            break;
        case 'm': case 'M':
            morseCode = "--";
            break;
        case 'n': case 'N':
            morseCode = "-.";
            break;
        case 'o': case 'O':
            morseCode = "---";
            break;
        case 'p': case 'P':
            morseCode = ".--.";
            break;
        case 'q': case 'Q':
            morseCode = "--.-";
            break;
        case 'r': case 'R':
            morseCode = ".-.";
            break;
        case 's': case 'S':
            morseCode = "...";
            break;
        case 't': case 'T':
            morseCode = "-";
            break;
        case 'u': case 'U':
            morseCode = "..-";
            break;
        case 'v': case 'V':
            morseCode = "...-";
            break;
        case 'w': case 'W':
            morseCode = ".--";
            break;
        case 'x': case 'X':
            morseCode = "-..-";
            break;
        case 'y': case 'Y':
            morseCode = "-.--";
            break;
        case 'z': case 'Z':
            morseCode = "--..";
            break;
        case '0':
            morseCode = "-----";
            break;
        case '1':
            morseCode = ".----";
            break;
        case '2':
            morseCode = "..---";
            break;
        case '3':
            morseCode = "...--";
            break;
        case '4':
            morseCode = "....-";
            break;
        case '5':
            morseCode = ".....";
            break;
        case '6':
            morseCode = "-....";
            break;
        case '7':
            morseCode = "--...";
            break;
        case '8':
            morseCode = "---..";
            break;
        case '9':
            morseCode = "----.";
            break;  
        case ' ':
            morseCode = "    ";
            break;  
        default:
            morseCode = "";
    }
    return morseCode;
}