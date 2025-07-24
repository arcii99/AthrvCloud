//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: rigorous
#include <stdio.h>
#include <string.h>

char* translate(char* phrase) {
    const int MAX_LENGTH = 1000;
    char* translated = malloc(MAX_LENGTH);
    strcpy(translated, "");

    for (int i = 0; i < strlen(phrase); i++) {
        if (phrase[i] == 'c' || phrase[i] == 'C') {
            strcat(translated, "meow");
        } else {
            char temp[] = {phrase[i], '\0'};
            strcat(translated, temp);
        }
    }

    return translated;
}

int main() {
    char input[1000];
    printf("Enter a phrase to translate to C Cat Language: ");
    fgets(input, sizeof(input), stdin);
    char* translated = translate(input);
    printf("Translated to C Cat Language: %s\n", translated);
    return 0;
}