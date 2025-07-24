//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: sophisticated
#include <stdio.h>
#include <string.h>

void translate(char* input) {
    int length = strlen(input);
    char output[length];

    for(int i = 0; i < length; i++) {
        if(input[i] == 'a') {
            output[i] = 'q';
        } else if(input[i] == 'b') {
            output[i] = 'w';
        } else if(input[i] == 'c') {
            output[i] = 'e';
        } else if(input[i] == 'd') {
            output[i] = 'r';
        } else if(input[i] == 'e') {
            output[i] = 't';
        } else if(input[i] == 'f') {
            output[i] = 'y';
        } else if(input[i] == 'g') {
            output[i] = 'u';
        } else if(input[i] == 'h') {
            output[i] = 'i';
        } else if(input[i] == 'i') {
            output[i] = 'o';
        } else if(input[i] == 'j') {
            output[i] = 'p';
        } else if(input[i] == 'k') {
            output[i] = 'a';
        } else if(input[i] == 'l') {
            output[i] = 's';
        } else if(input[i] == 'm') {
            output[i] = 'd';
        } else if(input[i] == 'n') {
            output[i] = 'f';
        } else if(input[i] == 'o') {
            output[i] = 'g';
        } else if(input[i] == 'p') {
            output[i] = 'h';
        } else if(input[i] == 'q') {
            output[i] = 'j';
        } else if(input[i] == 'r') {
            output[i] = 'k';
        } else if(input[i] == 's') {
            output[i] = 'l';
        } else if(input[i] == 't') {
            output[i] = 'z';
        } else if(input[i] == 'u') {
            output[i] = 'x';
        } else if(input[i] == 'v') {
            output[i] = 'c';
        } else if(input[i] == 'w') {
            output[i] = 'v';
        } else if(input[i] == 'x') {
            output[i] = 'b';
        } else if(input[i] == 'y') {
            output[i] = 'n';
        } else if(input[i] == 'z') {
            output[i] = 'm';
        } else {
            output[i] = input[i];
        }
    }

    printf("Translated Text: %s", output);
}

int main() {
    char input[100];
    printf("Enter text to translate to Alien language: ");
    scanf("%s", input);

    translate(input);

    return 0;
}