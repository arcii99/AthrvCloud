//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char input[100];
    char output[100];
    int i;

    printf("Welcome to the Cat Language Translator.\n");
    printf("Please enter a sentence in Cat Language: ");

    fgets(input, sizeof(input), stdin);

    for (i = 0; input[i] != '\0'; i++) {

        switch(input[i]) {

            case 'M': output[i] = 'M'; break;
            case 'e': output[i] = 'e'; break;
            case 'o': output[i] = 'o'; break;
            case 'w': output[i] = 'w'; break;
            case ' ': output[i] = ' '; break;
            default: output[i] = '?';
        }

    }

    printf("The translated sentence is: %s\n", output);

    return 0;
}