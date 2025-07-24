//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: irregular
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char input[BUFFER_SIZE];
    printf("Welcome to the C Alien Language Translator!\n");
    printf("Enter a sentence in the C Alien Language:\n");
    fgets(input, BUFFER_SIZE, stdin);

    int i, j;
    char output[BUFFER_SIZE];
    int length = strlen(input);
    for (i = 0, j = 0; i < length; i++, j++) {
        if (input[i] == 'C' || input[i] == 'c') {
            output[j++] = 'Z';
            output[j] = 'O';
        } else if (input[i] == ' ') {
            output[j] = input[i];
        } else {
            output[j] = input[i];
            int counter;
            for (counter = 0; counter < 4; counter++) {
                j++;
                output[j] = input[i];
            }
        }
    }
    output[j] = '\0';

    printf("The translated sentence is:\n%s", output);
    return 0;
}