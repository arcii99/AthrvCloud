//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    char output[100];
    int i, j;
    
    printf("Welcome to the C Alien Language Translator!\n");
    printf("Please enter a sentence to translate: ");
    fgets(input, 100, stdin);
    
    for(i = 0; i < strlen(input); i++) {
        if(input[i] == 'c') {
            output[i] = 'k';
        } else if(input[i] == 'k') {
            output[i] = 'c';
        } else if(input[i] == 'a') {
            output[i] = 'e';
        } else if(input[i] == 'e') {
            output[i] = 'a';
        } else if(input[i] == 'l') {
            output[i] = 'm';
        } else if(input[i] == 'm') {
            output[i] = 'l';
        } else if(input[i] == 'i') {
            output[i] = 'y';
        } else if(input[i] == 'y') {
            output[i] = 'i';
        } else if(input[i] == 'n') {
            output[i] = 'p';
        } else if(input[i] == 'p') {
            output[i] = 'n';
        } else if(input[i] == 'o') {
            output[i] = 'u';
        } else if(input[i] == 'u') {
            output[i] = 'o';
        } else {
            output[i] = input[i];
        }
    }
    
    printf("Your translated sentence is: %s", output);
    
    return 0;
}