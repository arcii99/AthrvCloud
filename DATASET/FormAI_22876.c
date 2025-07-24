//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100        //maximum size of input string

//Function to convert character to Morse Code
char* convertToMorse(char c) {
    switch (c) {
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

int main() {    
    char input[MAX_SIZE], output[MAX_SIZE*10];    //output can be ten times the length of input
    int i, j;

    printf("Enter text to be converted to Morse Code: ");
    fgets(input, MAX_SIZE, stdin);  //reading input from user

    //iterating over each character of input and converting it to Morse Code
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            output[j++] = ' ';      //adding space to output if input character is space
        }
        else {
            char* morseCode = convertToMorse(input[i]);    //converting character to Morse Code using function
            strcat(output, morseCode);
            j += strlen(morseCode);
            output[j++] = ' ';      //adding space to output after Morse Code of each character
        }
    }
    
    //printing final output
    printf("\nMorse Code Conversion: %s\n", output);

    return 0;
}