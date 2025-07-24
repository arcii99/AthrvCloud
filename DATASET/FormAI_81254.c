//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: protected
#include <stdio.h>
#include <string.h>

int main() {
    char input[50];

    printf("Input a sentence in C Cat Language: ");
    fgets(input, 50, stdin);

    char output[50];
    int index = 0;

    for(int i = 0; i < strlen(input); i++) {
        // Check for vowels and replace them with "meow"
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
            output[index++] = 'm';
            output[index++] = 'e';
            output[index++] = 'o';
            output[index++] = 'w';
        } else {
            output[index++] = input[i];
        }
    }

    output[index] = '\0';

    printf("Translated sentence: %s", output);

    return 0;
}