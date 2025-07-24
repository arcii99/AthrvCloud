//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* text_to_morse(char input) {
    char *morse_code;
    switch(input){
        case 'a': morse_code = ".-"; break;
        case 'b': morse_code = "-..."; break;
        case 'c': morse_code = "-.-."; break;
        case 'd': morse_code = "-.."; break;
        case 'e': morse_code = "."; break;
        case 'f': morse_code = "..-."; break;
        case 'g': morse_code = "--."; break;
        case 'h': morse_code = "...."; break;
        case 'i': morse_code = ".."; break;
        case 'j': morse_code = ".---"; break;
        case 'k': morse_code = "-.-"; break;
        case 'l': morse_code = ".-.."; break;
        case 'm': morse_code = "--"; break;
        case 'n': morse_code = "-."; break;
        case 'o': morse_code = "---"; break;
        case 'p': morse_code = ".--."; break;
        case 'q': morse_code = "--.-"; break;
        case 'r': morse_code = ".-."; break;
        case 's': morse_code = "..."; break;
        case 't': morse_code = "-"; break;
        case 'u': morse_code = "..-"; break;
        case 'v': morse_code = "...-"; break;
        case 'w': morse_code = ".--"; break;
        case 'x': morse_code = "-..-"; break;
        case 'y': morse_code = "-.--"; break;
        case 'z': morse_code = "--.."; break;
        case '0': morse_code = "-----"; break;
        case '1': morse_code = ".----"; break;
        case '2': morse_code = "..---"; break;
        case '3': morse_code = "...--"; break;
        case '4': morse_code = "....-"; break;
        case '5': morse_code = "....."; break;
        case '6': morse_code = "-...."; break;
        case '7': morse_code = "--..."; break;
        case '8': morse_code = "---.."; break;
        case '9': morse_code = "----."; break;
        case ' ': morse_code = "/"; break;
        default: morse_code = "";
    }
    return morse_code;
}

void text_to_morse_conversion(char mystring[]) {
    int i = 0;
    int length = strlen(mystring);

    for(i; i<length; i++) {
        char input = mystring[i];
        char* morse = text_to_morse(input);
        printf("%s ", morse);
    }
}

int main(){
    char mystring[100];
    printf("Enter the text you want to convert into Morse Code:\n");
    fgets(mystring, 100, stdin);
    printf("Morse Code:\n");
    text_to_morse_conversion(mystring);
    return 0;
}