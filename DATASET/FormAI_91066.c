//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: retro
#include <stdio.h>
#include <string.h>

void printTranslation(char *input) {
    char c[strlen(input)];
    strcpy(c, input);

    for (int i=0; i<strlen(c); i++) {
        if (c[i] == 'c') {
            printf("meow ");
        } else if (c[i] == 'C') {
            printf("MEOW ");
        } else if (c[i] == 'a') {
            printf("purr ");
        } else if (c[i] == 'A') {
            printf("PURR ");
        } else if (c[i] == 't') {
            printf("hiss ");
        } else if (c[i] == 'T') {
            printf("HISS ");
        } else {
            printf("%c ", c[i]);
        }
    }
    printf("\n");
}

int main() {
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Enter a phrase to translate: ");

    char input[100];
    fgets(input, 100, stdin);
    printf("Translation: ");
    printTranslation(input);

    return 0;
}