//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: recursive
#include <stdio.h>
#include <string.h>

void translate(char *str) {

    /* Base case: if string is empty, do nothing */
    if (*str == '\0') {
        return;
    }

    /* Translate vowels to the letter 'o' */
    if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u') {
        *str = 'o';
    }

    /* Recursive step: translate the rest of the string */
    translate(str + 1);
}

int main() {
    char input[100];

    /* Prompt user for input */
    printf("Enter a string: ");
    fgets(input, 100, stdin);

    /* Remove newline character from input */
    input[strlen(input) - 1] = '\0';

    /* Translate the input */
    translate(input);

    /* Print the translated string */
    printf("Translation: %s\n", input);

    return 0;
}