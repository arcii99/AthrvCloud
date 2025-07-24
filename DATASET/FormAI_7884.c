//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

void translate(char* input) {
    char output[MAX_SIZE];
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (c == 'a') {
            output[i] = 'b';
        } else if (c == 'b') {
            output[i] = 'c';
        } else if (c == 'c') {
            output[i] = 'd';
        } else if (c == 'd') {
            output[i] = 'e';
        } else if (c == 'e') {
            output[i] = 'f';
        } else if (c == 'f') {
            output[i] = 'g';
        } else if (c == 'g') {
            output[i] = 'h';
        } else if (c == 'h') {
            output[i] = 'i';
        } else if (c == 'i') {
            output[i] = 'j';
        } else if (c == 'j') {
            output[i] = 'k';
        } else if (c == 'k') {
            output[i] = 'l';
        } else if (c == 'l') {
            output[i] = 'm';
        } else if (c == 'm') {
            output[i] = 'n';
        } else if (c == 'n') {
            output[i] = 'o';
        } else if (c == 'o') {
            output[i] = 'p';
        } else if (c == 'p') {
            output[i] = 'q';
        } else if (c == 'q') {
            output[i] = 'r';
        } else if (c == 'r') {
            output[i] = 's';
        } else if (c == 's') {
            output[i] = 't';
        } else if (c == 't') {
            output[i] = 'u';
        } else if (c == 'u') {
            output[i] = 'v';
        } else if (c == 'v') {
            output[i] = 'w';
        } else if (c == 'w') {
            output[i] = 'x';
        } else if (c == 'x') {
            output[i] = 'y';
        } else if (c == 'y') {
            output[i] = 'z';
        } else if (c == 'z') {
            output[i] = 'a';
        } else {
            output[i] = c; // Preserve non-letter characters
        }
    }
    output[strlen(input)] = '\0';
    printf("%s\n", output);
}

int main() {
    printf("Enter a phrase in the Alien language:\n");
    char input[MAX_SIZE];
    fgets(input, MAX_SIZE, stdin);
    translate(input);
    return 0;
}