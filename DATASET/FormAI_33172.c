//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: high level of detail
#include <stdio.h>
#include <string.h>

char* cat_language_translator(char* input) {
    char* output = malloc(sizeof(char) * strlen(input));
    int i = 0;
    while(input[i] != '\0') {
        if(input[i] == 'c') {
            output[i] = 'm';
        } else if(input[i] == 'C') {
            output[i] = 'M';
        } else if(input[i] == 'a') {
            output[i] = 'e';
        } else if(input[i] == 'A') {
            output[i] = 'E';
        } else if(input[i] == 't') {
            output[i] = 'p';
        } else if(input[i] == 'T') {
            output[i] = 'P';
        } else if(input[i] == 's') {
            output[i] = 'n';
        } else if(input[i] == 'S') {
            output[i] = 'N';
        } else {
            output[i] = input[i];
        }
        i++;
    }
    return output;
}

int main() {
    char input[100];
    printf("Enter a sentence in C Cat Language:\n");
    fgets(input, 100, stdin);
    char* output = cat_language_translator(input);
    printf("\nTranslation in English:\n%s", output);
    return 0;
}