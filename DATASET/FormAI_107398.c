//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: complex
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter phrase in C Cat Language: ");
    fgets(input, 100, stdin);
    
    int len = strlen(input);
    char output[len];
    
    int i;
    for(i=0; i<len; i++) {
        if(input[i] == 'C') {
            output[i] = 'K'; // Translate 'C' to 'K'
        } else if(input[i] == 'a') {
            output[i] = 'e'; // Translate 'a' to 'e'
        } else if(input[i] == 't') {
            output[i] = 'd'; // Translate 't' to 'd'
        } else if(input[i] == ' ') {
            output[i] = ' '; // Keep spaces
        } else {
            output[i] = input[i]; // Keep everything else the same
        }
    }
    
    printf("Translated phrase: %s", output);
    
    return 0;
}