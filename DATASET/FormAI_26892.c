//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* defining the alien language */
#define ALPHABET "AEIOUaeiou"
#define LEN 10

/* function to translate from C to Alien language */
void c_to_alien(char *input) {
    char *output = malloc(strlen(input) * LEN + 1);
    int i, j;

    for (i = 0, j = 0; input[i] != '\0'; i++, j+=LEN) {
        if (strchr(ALPHABET, input[i]) == NULL) {
            /* not a vowel, so just copy */
            strncpy(output+j, input+i, 1);
        } else {
            /* vowel, so replace with alien language */
            strncpy(output+j, "akp", LEN);
        }
    }

    output[j] = '\0';
    printf("Translated to Alien Language: %s\n", output);
    free(output);
}

int main() {
    char input[100];

    printf("Enter a phrase in C language to translate into Alien language:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; /* remove trailing newline */

    c_to_alien(input); /* translate to alien language */

    return 0;
}