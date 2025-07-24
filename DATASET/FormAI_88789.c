//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* translate(char* input) {
    int length = strlen(input);
    int i;
    
    for (i = 0; i < length; i++) {
        if (input[i] == 'a') {
            input[i] = 'z';
        } else if (input[i] == 'b') {
            input[i] = 'y';
        } else if (input[i] == 'c') {
            input[i] = 'x';
        } else if (input[i] == 'd') {
            input[i] = 'w';
        } else if (input[i] == 'e') {
            input[i] = 'v';
        } else if (input[i] == 'f') {
            input[i] = 'u';
        } else if (input[i] == 'g') {
            input[i] = 't';
        } else if (input[i] == 'h') {
            input[i] = 's';
        } else if (input[i] == 'i') {
            input[i] = 'r';
        } else if (input[i] == 'j') {
            input[i] = 'q';
        } else if (input[i] == 'k') {
            input[i] = 'p';
        } else if (input[i] == 'l') {
            input[i] = 'o';
        } else if (input[i] == 'm') {
            input[i] = 'n';
        } else if (input[i] == 'n') {
            input[i] = 'm';
        } else if (input[i] == 'o') {
            input[i] = 'l';
        } else if (input[i] == 'p') {
            input[i] = 'k';
        } else if (input[i] == 'q') {
            input[i] = 'j';
        } else if (input[i] == 'r') {
            input[i] = 'i';
        } else if (input[i] == 's') {
            input[i] = 'h';
        } else if (input[i] == 't') {
            input[i] = 'g';
        } else if (input[i] == 'u') {
            input[i] = 'f';
        } else if (input[i] == 'v') {
            input[i] = 'e';
        } else if (input[i] == 'w') {
            input[i] = 'd';
        } else if (input[i] == 'x') {
            input[i] = 'c';
        } else if (input[i] == 'y') {
            input[i] = 'b';
        } else if (input[i] == 'z') {
            input[i] = 'a';
        }
    }
    
    return input;
}

int main() {
    char input[100];
    
    printf("Enter input in Alien language (lower case alphabets only):\n");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; //remove newline character from input
    
    printf("Translated text is: %s\n", translate(input));
    
    return 0;
}