//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

    printf("Welcome to the C Alien Language Translator! \n");

    // Input
    char input[100];
    printf("Please enter the phrase you would like to translate: \n");
    fgets(input, 100, stdin);

    // Translation
    char output[100];
    for(int i = 0; i < strlen(input); i++) {
        switch(input[i]) {
            case 'X':
                output[i] = 'Z';
                break;
            case 'Y':
                output[i] = 'X';
                break;
            case 'Z':
                output[i] = 'Y';
                break;
            default:
                output[i] = input[i];
        }
    }

    // Output
    printf("Your translated phrase is: %s", output);

    return 0;
}