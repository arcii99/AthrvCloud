//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Linus Torvalds
/* C Cat Language Translator */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Enter your phrase in C Cat language: ");

    char input[MAX_LENGTH];
    fgets(input, MAX_LENGTH, stdin);

    char output[MAX_LENGTH];
    int output_index = 0;

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == 'c') {
            output[output_index++] = 'm';
            output[output_index++] = 'e';
            output[output_index++] = 'o';
            continue;
        }

        if (input[i] == 'C') {
            output[output_index++] = 'M';
            output[output_index++] = 'E';
            output[output_index++] = 'O';
            continue;
        }

        if (input[i] == '\n') {
            output[output_index++] = '\0';
            break;
        }

        output[output_index++] = input[i];
    }

    printf("Your phrase in Human language is: %s\n", output);

    return 0;
}