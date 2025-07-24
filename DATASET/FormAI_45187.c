//FormAI DATASET v1.0 Category: Word Count Tool ; Style: romantic
#include <stdio.h>
#include <ctype.h>

int main(void) {
    char input[1000];
    int words = 1, letters = 0, i = 0;

    printf("My love, please enter a sentence or paragraph:\n");
    fgets(input, 1000, stdin);

    while (input[i] != '\0') {
        if (isspace(input[i])) { // check if current character is a space
            words++;
        } else {
            letters++;
        }
        i++;
    }

    printf("\nMy darling, your input has %d words and %d letters.\n", words, letters);

    return 0;
}