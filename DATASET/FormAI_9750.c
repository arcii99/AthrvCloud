//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: cheerful
//Welcome to the C Cat Language Translator!

#include <stdio.h>

int main() {

    printf("Welcome to the C Cat Language Translator!\n");

    //Let's ask the user for some input
    printf("Please enter a sentence in C Cat Language:\n");
    char input[1000];
    fgets(input, sizeof(input), stdin);

    //Let's translate the input
    printf("Translating...\n");
    char output[1000];
    int i, j;
    for(i = 0, j = 0; input[i] != '\0'; i++) {
        if(input[i] == 'c') {
            output[j++] = 'p';
            output[j++] = 'u';
            output[j++] = 'r';
            output[j++] = 'r';
            output[j++] = 'r';
            output[j++] = 'r';
            output[j++] = 'r';
        }
        else if(input[i] == 'a') {
            output[j++] = 'm';
            output[j++] = 'e';
            output[j++] = 'o';
        }
        else if(input[i] == 't') {
            output[j++] = 'h';
            output[j++] = 'e';
            output[j++] = 'r';
            output[j++] = 'r';
            output[j++] = 'r';
            output[j++] = 'r';
        }
        else if(input[i] == ' ') {
            output[j++] = ' ';
        }
    }
    output[j] = '\0';

    //Let's print the output
    printf("Translated sentence: %s", output);

    return 0;
}