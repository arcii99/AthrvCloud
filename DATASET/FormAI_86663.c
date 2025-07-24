//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: excited
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LENGTH 100

void printMorse(char character);

int main() {
    char text[MAX_LENGTH];
    char morse[MAX_LENGTH*4];
    int j = 0;
    printf("Hello! I am a C program that converts text to Morse Code!\n");
    printf("Please enter the text to be converted: ");
    fgets(text, MAX_LENGTH, stdin);
    printf("\n\n");
    printf("Here is the Morse Code Version of your input:\n");

    for(int i = 0; i < strlen(text); i++) {
        char current_character = text[i];
        if(current_character == ' ') {
            morse[j++] = ' ';
        } else if(current_character >= 'A' && current_character <= 'Z') {
            printMorse(current_character - 'A' + '.'); // prints the morse code for the uppercase letter
            morse[j++] = ' ';
        } else if(current_character >= 'a' && current_character <= 'z') {
            printMorse(current_character - 'a' + '.'); // prints the morse code for the lowercase letter
            morse[j++] = ' ';
        }
    }
    morse[j] = '\0';

    printf("\n%s\n", morse);
    printf("\nThanks for using my program, have fun using Morse Code!\n");
    return 0;
}

void printMorse(char character) {
    switch(character) {
        case 'a': printf(".- "); break;
        case 'b': printf("-... "); break;
        case 'c': printf("-.-. "); break;
        case 'd': printf("-.. "); break;
        case 'e': printf(". "); break;
        case 'f': printf("..-. "); break;
        case 'g': printf("--. "); break;
        case 'h': printf(".... "); break;
        case 'i': printf(".. "); break;
        case 'j': printf(".--- "); break;
        case 'k': printf("-.- "); break;
        case 'l': printf(".-.. "); break;
        case 'm': printf("-- "); break;
        case 'n': printf("-. "); break;
        case 'o': printf("--- "); break;
        case 'p': printf(".--. "); break;
        case 'q': printf("--.- "); break;
        case 'r': printf(".-. "); break;
        case 's': printf("... "); break;
        case 't': printf("- "); break;
        case 'u': printf("..- "); break;
        case 'v': printf("...- "); break;
        case 'w': printf(".-- "); break;
        case 'x': printf("-..- "); break;
        case 'y': printf("-.-- "); break;
        case 'z': printf("--.. "); break;
        case '.': printf(".-.-.- "); break;
        case ',': printf("--..-- "); break;
        case '?': printf("..--.. "); break;
        case '\'': printf(".----. "); break;
        case '!': printf("-.-.-- "); break;
        case '/': printf("-..-. "); break;
        case '(': printf("-.--. "); break;
        case ')': printf("-.--.- "); break;
        case '&': printf(".-... "); break;
        case ':': printf("---... "); break;
        case ';': printf("-.-.-. "); break;
        case '=': printf("-...- "); break;
        case '+': printf(".-.-. "); break;
        case '-': printf("-....- "); break;
        case '_': printf("..--.- "); break;
        case '\"': printf(".-..-. "); break;
        case '$': printf("...-..- "); break;
        case '@': printf(".--.-. "); break;
        default: printf(" "); break;
    }
}