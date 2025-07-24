//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 200

char* morse_code(char c) {
    char* code = "";
    switch(c) {
        case 'a': code = ".-"; break;
        case 'b': code = "-..."; break;
        case 'c': code = "-.-."; break;
        case 'd': code = "-.."; break;
        case 'e': code = "."; break;
        case 'f': code = "..-."; break;
        case 'g': code = "--."; break;
        case 'h': code = "...."; break;
        case 'i': code = ".."; break;
        case 'j': code = ".---"; break;
        case 'k': code = "-.-"; break;
        case 'l': code = ".-.."; break;
        case 'm': code = "--"; break;
        case 'n': code = "-."; break;
        case 'o': code = "---"; break;
        case 'p': code = ".--."; break;
        case 'q': code = "--.-"; break;
        case 'r': code = ".-."; break;
        case 's': code = "..."; break;
        case 't': code = "-"; break;
        case 'u': code = "..-"; break;
        case 'v': code = "...-"; break;
        case 'w': code = ".--"; break;
        case 'x': code = "-..-"; break;
        case 'y': code = "-.--"; break;
        case 'z': code = "--.."; break;
        case '0': code = "-----"; break;
        case '1': code = ".----"; break;
        case '2': code = "..---"; break;
        case '3': code = "...--"; break;
        case '4': code = "....-"; break;
        case '5': code = "....."; break;
        case '6': code = "-...."; break;
        case '7': code = "--..."; break;
        case '8': code = "---.."; break;
        case '9': code = "----."; break;
        default: break;
    }
    return code;
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a text to convert to Morse code:\n");
    fgets(str, MAX_LENGTH, stdin);
    printf("Converting text \"%s\" to Morse code:\n", str);
    
    for(int i=0; i<strlen(str); i++) {
        if(str[i] == ' ') {
            printf("/ "); // insert space between words
        } else {
            printf("%s ", morse_code(tolower(str[i])));
        }
    }
    
    return 0;
}