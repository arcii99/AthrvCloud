//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: ephemeral
#include <stdio.h>
#include <string.h>

// Ephemeral style C Alien Language Translator

int main(void) {
    char input[100];
    printf("Welcome to the C Alien Language Translator!\n");
    printf("Please input a sentence in C Alien Language: ");
    fgets(input, sizeof(input), stdin);
    
    // Loop through each character and translate to English
    for(int i=0; i<strlen(input); i++) {
        switch(input[i]) {
            case '$': printf("a"); break;
            case '#': printf("b"); break;
            case '*': printf("c"); break;
            case '&': printf("d"); break;
            case '@': printf("e"); break;
            case '!': printf("f"); break;
            case '^': printf("g"); break;
            case '%': printf("h"); break;
            case '+': printf("i"); break;
            case '=': printf("j"); break;
            case '|': printf("k"); break;
            case '?': printf("l"); break;
            case '/': printf("m"); break;
            case ';': printf("n"); break;
            case '>': printf("o"); break;
            case '<': printf("p"); break;
            case '(': printf("q"); break;
            case ')': printf("r"); break;
            case '{': printf("s"); break;
            case '}': printf("t"); break;
            case '[': printf("u"); break;
            case ']': printf("v"); break;
            case '~': printf("w"); break;
            case '`': printf("x"); break;
            case ',': printf("y"); break;
            case '.': printf("z"); break;
            case ' ': printf(" "); break; // Keep spaces
            default: printf("%c", input[i]); // Keep any unrecognized characters
        }
    }
    printf("\nDone translating! Thanks for using the C Alien Language Translator.\n");
    return 0;
}